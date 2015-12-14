// Copyright Casey Megginsons and Blaise Koch 2015

#include <condition_variable>
#include <mutex>
#include <deque>
#include <map>
#include <string>
#include <list>
#include <utility>

#include "event_system/Dispatcher.h"
#include "util/definitions.h"

// Dispatcher Static Variables
bool Dispatcher::initialized_ = false;
bool Dispatcher::running_ = false;

std::mutex Dispatcher::dispatch_queue_mutex_;
std::mutex Dispatcher::thread_queue_mutex_;
std::condition_variable Dispatcher::thread_signal_;

Dispatcher* Dispatcher::instance_ = nullptr;
std::deque<std::pair<Subscriber*, std::shared_ptr<void>>>*  Dispatcher::thread_queue_;
std::deque<std::pair<Subscriber*, std::shared_ptr<void>>>* Dispatcher::nonserial_queue_;

// Begin Class Methods
Dispatcher::Dispatcher() { }

Dispatcher::~Dispatcher() {
    running_ = false;
    for (std::thread* t : *processing_threads_) {
        t->join();  // thould stop eventually...
        delete t;   // i'm pretty sure we need to shutdown the threads before we delete them
    }

    dispatch_events_->clear();
    delete dispatch_events_;
    delete mapped_events_;

    thread_queue_->clear();
    delete thread_queue_;

    nonserial_queue_->clear();
    delete nonserial_queue_;
}

Dispatcher* Dispatcher::GetInstance() {
    if (instance_ == nullptr) {
        instance_ = new Dispatcher();
        instance_->Initialize();
    }
    return instance_;
}

void Dispatcher::Initialize() {
    if (!initialized_) {
        initialized_ = true;

        dispatch_events_  = new std::deque<std::pair<EventType, std::shared_ptr<void>>>();
        mapped_events_    = new std::map<EventType, std::list<Subscriber*>*>();
        thread_queue_     = new std::deque<std::pair<Subscriber*, std::shared_ptr<void>>>();
        nonserial_queue_ = new std::deque<std::pair<Subscriber*, std::shared_ptr<void>>>();

        processing_threads_ = new std::deque<std::thread*>();

        running_ = true;

        // Adjust the thread count
        for (int i=0; i < 3; i++) {
            std::thread* processing_thread = new std::thread(ThreadProcess);
            // it probably won't terminate before the end of this program so we want to ignore errors
            processing_thread->detach();
            processing_threads_->push_back(processing_thread);
        }
    } else {
        std::cerr << "Attempting to reinitialize a dispatcher...  Ignoring." << std::endl;
    }
}

void Dispatcher::Pump() {
    std::lock_guard<std::mutex> dispatchLock(dispatch_queue_mutex_);
    for (auto i : *dispatch_events_) {  // for every event
        try {
            for (auto obj : *(mapped_events_->at(i.first))) {  // for every Subscriber* for that event
                if (obj == nullptr) continue;
                std::lock_guard<std::mutex> lock(thread_queue_mutex_);  // unlocked on out-of-scope
                if (obj->serialized) {
                    thread_queue_->push_back(std::pair<Subscriber*, std::shared_ptr<void>>(obj, i.second));
                    thread_signal_.notify_one();
                } else {
                    nonserial_queue_->push_back(std::pair<Subscriber*, std::shared_ptr<void>>(obj, i.second));
                }
            }
        } catch (std::string msg) {
            std::cerr << "Event \"" << i.first << "\" does not apply to any Subscribers." << std::endl;
        }
    }
    dispatch_events_->clear();  // we queued them all for processing so clear the cache
}

void Dispatcher::NonSerialProcess() {
    while(nonserial_queue_->size() != 0) {
        auto work = nonserial_queue_->front();
        nonserial_queue_->pop_front();
        try {
            if (work.first->method == NULL || work.first->owner == nullptr) continue;
            work.first->method(work.second);
        } catch (std::string msg) {
            std::cerr << "Exception thrown by function called in nonserial processing." << std::endl;
            std::cerr << msg << std::endl;
        }
    }
}

void Dispatcher::ThreadProcess() {
    while (running_) {
        std::pair<Subscriber*, std::shared_ptr<void>> work;  // compiler might whine here

        {   // enter new scope so std::unique_lock will unlock on exceptions
            std::unique_lock<std::mutex> lock(thread_queue_mutex_);
            while (thread_queue_->size() == 0) thread_signal_.wait(lock);

            work = thread_queue_->front();
            thread_queue_->pop_front();
        }

        try {
            if (work.first->method == NULL || work.first->owner == nullptr) continue;
            work.first->method(work.second);
        } catch (std::string e) {
            std::cerr << "Exception thrown by function called by Event Threads." << std::endl;
            std::cerr << e << std::endl;
        }
    }
}

void Dispatcher::DispatchEvent(const EventType eventID, const std::shared_ptr<void> eventData) {
    // std::cout << "Dispatcher --->  Received event " << eventID << "." << std::endl;
    std::lock_guard<std::mutex> dispatchLock(dispatch_queue_mutex_);
    dispatch_events_->push_back(std::pair<EventType, std::shared_ptr<void>>(eventID, eventData));
}

void Dispatcher::AddEventSubscriber(Subscriber *requestor, const EventType event_id) {
    if (mapped_events_->count(event_id) < 1) {
        std::cerr << "Dispatcher --->  Dynamically allocating list for EventID "
            << event_id << "."
            << std::endl << "Dispatcher --->  This should be avoided for performance reasons."
            << std::endl;
        mapped_events_->emplace(event_id, new std::list<Subscriber*>());
    }
    mapped_events_->at(event_id)->push_back(requestor);
}

Subscriber* Dispatcher::RemoveEventSubscriber(Subscriber *requestor, const EventType event_id) {
    if (mapped_events_->find(event_id) != mapped_events_->end()) {
        auto list = std::list<Subscriber*>();
        Subscriber* s = nullptr;

        for (auto sub : *(mapped_events_->at(event_id))) {
            if (sub == requestor) list.push_back(sub);
        }

        for (auto sub : list) {
            s = sub;
            mapped_events_->at(event_id)->remove(sub);
        }

        return s;
    }
    return nullptr;
}

// TODO(bk5115545) reimplement using map traversal
std::list<Subscriber*> Dispatcher::GetAllSubscribers(const void* owner) {
    std::list<Subscriber*> tmp;
    UNUSED(owner);
    return tmp;
}

void Dispatcher::Terminate() {
    running_ = false;
    sleep(100);
}
