#pragma once

#include "Util/Definitions.h"

#include <deque>
#include <mutex>

//Begin Dispatcher Class Section

class Subscriber;

class Dispatcher {

	private:
		Dispatcher();
		void Initialize();

		static bool inited;
		static bool running;

		static Dispatcher* theInstance;

		std::deque<std::pair<double,std::shared_ptr<void>>>*  dispatchEvents;
		std::map<int,std::list<Subscriber*>*>* mappedEvents;

		static std::deque<std::pair<Subscriber*, std::shared_ptr<void>>>*  threadQueue;
		std::deque<std::thread*>* processingThreads; //using std::deque for constant time size() and O(1) random access

		static std::mutex dispatchQueueLock;
		static std::mutex threadQueueLock;

	public:

		~Dispatcher();

		static Dispatcher* GetInstance();

		Dispatcher(const Dispatcher&); //disallow copying
	    Dispatcher& operator= (const Dispatcher&); //disallow copying



		void Terminate();

		void AddEventSubscriber(Subscriber *requestor, const double event_id);
		Subscriber* RemoveEventSubscriber(Subscriber *requestor, const double event_id);
		std::list<Subscriber*> GetAllSubscribers(const void* owner);

		void DispatchEvent(const double eventID, const std::shared_ptr<void> eventData);

		void Pump();
		int QueueSize() const { return threadQueue->size(); }

	private:
		static void ThreadProcess();
};
