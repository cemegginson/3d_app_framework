#pragma once

#include "Util/Definitions.h"

#include <condition_variable>
#include <mutex>
#include <deque>
#include <map>

//Begin Dispatcher Class Section

using EventType = std::string;

class Subscriber;

class Dispatcher {

	private:
		Dispatcher();
		void Initialize();

		static bool inited;
		static bool running;

		static Dispatcher* theInstance;

		std::deque<std::pair<EventType,std::shared_ptr<void>>>*  dispatchEvents;
		std::map<EventType,std::list<Subscriber*>*>* mappedEvents;

		static std::deque<std::pair<Subscriber*, std::shared_ptr<void>>>*  threadQueue;
		std::deque<std::thread*>* processingThreads; //using std::deque for constant time size() and O(1) random access

		static std::mutex dispatchQueueMutex;
		static std::mutex threadQueueMutex;
		static std::condition_variable threadSignal;

	public:

		~Dispatcher();

		static Dispatcher* GetInstance();

		Dispatcher(const Dispatcher&); //disallow copying
	    Dispatcher& operator= (const Dispatcher&); //disallow copying



		void Terminate();

		void AddEventSubscriber(Subscriber *requestor, const EventType);
		Subscriber* RemoveEventSubscriber(Subscriber *requestor, const EventType);
		std::list<Subscriber*> GetAllSubscribers(const void* owner);

		void DispatchEvent(const EventType eventID, const std::shared_ptr<void> eventData);

		void Pump();
		int QueueSize() const { return threadQueue->size(); }

	private:
		static void ThreadProcess();
};
