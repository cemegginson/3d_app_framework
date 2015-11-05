#include "EventSystem/Dispatcher.h"
#include "Util/Definitions.h"

#include <mutex>

//Dispatcher Static Variables
bool Dispatcher::inited = false;
bool Dispatcher::running = false;
std::mutex Dispatcher::dispatchQueueLock;
std::mutex Dispatcher::threadQueueLock;

Dispatcher* Dispatcher::theInstance = nullptr;
std::deque<std::pair<Subscriber*, std::shared_ptr<void>>>*  Dispatcher::threadQueue;

//Begin Class Methods
Dispatcher::Dispatcher() { }

Dispatcher::~Dispatcher() {
    running = false;
    for(std::thread* t : *processingThreads) {
        t->join();  //thould stop eventually...
        delete t;   //i'm pretty sure we need to shutdown the threads before we delete them
    }
}

Dispatcher* Dispatcher::GetInstance() {
    if(theInstance == nullptr) {
        theInstance = new Dispatcher();
        theInstance->Initialize();
    }
    return theInstance;
}

void Dispatcher::Initialize() {
    if(!inited) {
        inited = true;

        dispatchEvents  = new std::deque<std::pair<double,std::shared_ptr<void>>>();
        mappedEvents    = new std::map<int,std::list<Subscriber*>*>();
        threadQueue     = new std::deque<std::pair<Subscriber*, std::shared_ptr<void>>>();
        processingThreads = new std::deque<std::thread*>();

        running = true;

        for(int i=0; i<8; i++) {
            std::thread* processingThread = new std::thread(ThreadProcess);
            processingThread->detach(); //it probably won't terminate before the end of this program so we want to ignore errors
            processingThreads->push_back(processingThread);
        }
    } else {
        std::cerr << "Attempting to reinitialize a dispatcher...  Ignoring." << std::endl;
    }
}

void Dispatcher::Pump() {
    std::lock_guard<std::mutex> dispatchLock(dispatchQueueLock);
    for(auto i : *dispatchEvents) { //for every event
        for(auto obj : *(mappedEvents->at(i.first))) { //for every Subscriber* for that event
            if(obj == nullptr) continue;
            std::lock_guard<std::mutex> lock(threadQueueLock); //unlocked on out-of-scope
            threadQueue->push_back(std::pair<Subscriber*, std::shared_ptr<void>>(obj, i.second)); //queue Subscriber* with arguements
        }
    }
    dispatchEvents->clear(); //we queued them all for processing so clear the cache
    //std::cout << threadQueue->size() << std::endl;
}

void Dispatcher::ThreadProcess() {
    while(running) {
        std::pair<Subscriber*, std::shared_ptr<void>> work; //compiler might whine here
        {
            while(threadQueue->size() == 0) sleep(1);
            std::lock_guard<std::mutex> lock(threadQueueLock); //unlocked on out-of-scope
            if(threadQueue->size() == 0) continue;
            work = threadQueue->front();
            threadQueue->pop_front();
        }

        try {
            if(work.first->method == NULL) continue;
            work.first->method(work.second);
        } catch (std::string e) {
            std::cerr << "Exception thrown by function called by Event Threads." << std::endl;
            std::cerr << e << std::endl;
        }
    }
}

void Dispatcher::DispatchEvent(const double eventID, const std::shared_ptr<void> eventData) {
    //std::cout << "Dispatcher --->  Received event " << eventID << "." << std::endl;
    std::lock_guard<std::mutex> dispatchLock(dispatchQueueLock);
    dispatchEvents->push_back(std::pair<double,std::shared_ptr<void>>(eventID, eventData));
}

void Dispatcher::AddEventSubscriber(Subscriber *requestor, const double event_id) {
    if(mappedEvents->count(event_id) < 1) {
        std::cerr << "Dispatcher --->  Dynamically allocating list for Specific EventID " << event_id << "." << std::endl << "Dispatcher --->  This should be avoided for performance reasons." << std::endl;
        mappedEvents->emplace(event_id, new std::list<Subscriber*>());
    }
    mappedEvents->at(event_id)->push_back(requestor);
}

Subscriber* Dispatcher::RemoveEventSubscriber(Subscriber *requestor, const double event_id) {

    if(mappedEvents->find(event_id) != mappedEvents->end()) {

        auto list = std::list<Subscriber*>();
        Subscriber* s = nullptr;

        for(auto sub : *(mappedEvents->at(event_id))) {
            if(sub == requestor) list.push_back(sub);
        }

        for(auto sub : list) {
            s = sub;
            mappedEvents->at(event_id)->remove(sub);
        }

        return s;
    }
    return nullptr;
}

//TODO reimplement using map traversal
std::list<Subscriber*> Dispatcher::GetAllSubscribers(const void* owner) {
    std::list<Subscriber*> tmp;

    return tmp;
}

void Dispatcher::Terminate() {
    running = false;
    sleep(100);
}
