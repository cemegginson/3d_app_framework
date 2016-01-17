#pragma once

#include "util/definitions.h"

#include <condition_variable>
#include <mutex>
#include <deque>
#include <map>
#include <memory>

//Begin Dispatcher Class Section

using EventType = std::string;

class Subscriber;

class Dispatcher {
    private:
        Dispatcher();
        ~Dispatcher();
        void Initialize();

        static bool initialized_;
        static bool running_;

        static Dispatcher* instance_;

        std::deque<EventType>*  dispatch_events_;
        std::map<EventType,std::list<Subscriber*>*>* mapped_events_;

        static std::deque<Subscriber*>*  thread_queue_;
        static std::deque<Subscriber*>*  nonserial_queue_;

        //using std::deque for constant time size() and O(1) random access
        std::deque<std::thread*>* processing_threads_;

        static std::mutex dispatch_queue_mutex_;
        static std::mutex thread_queue_mutex_;
        static std::mutex mapped_event_mutex_;
        static std::condition_variable thread_signal_;


    public:
        static Dispatcher* GetInstance();

        //disallow copying
        Dispatcher(const Dispatcher&) = delete;
        Dispatcher& operator= (const Dispatcher&) = delete;

        void Terminate();

        void AddEventSubscriber(Subscriber *requestor, const EventType);
        std::list<Subscriber*> GetAllSubscribers(const void* owner);

        void DispatchEvent(const EventType eventID);
        void DispatchImmediate(const EventType eventID);

        void Pump();
        void NonSerialProcess();

        int QueueSize() { return static_cast<int>(thread_queue_->size()); }

    private:
        static void ThreadProcess();
};
