#pragma once

#include "Util/Definitions.h"

#include <deque>

//Begin Dispatcher Class Section

class Subscriber;

class Dispatcher {

private:
	static bool inited;
	static bool running;
	static bool processing;
	static bool dispatchLock;
	static bool subscriberLock;
	static bool mappedLock;

	static Dispatcher* theInstance;

	static std::deque<std::pair<double,std::shared_ptr<void>>>*  dispatchEvents;
	static std::map<int,std::list<Subscriber*>*>* mappedEvents;

	static std::deque<std::thread*> processingThreads; //using std::deque for constant time size() and O(1) random access

public:
	Dispatcher();
	//It makes no sense for an all-static class to have a destructor
	//~Dispatcher();
	//It only needs to be destructed at program termination

	static Dispatcher* GetInstance();

	Dispatcher(const Dispatcher&); //disallow copying
    Dispatcher& operator= (const Dispatcher&); //disallow copying

	static void Initialize();

	static void Start();
	static void Stop();
	static void Terminate();

	static void AddEventSubscriber(Subscriber *requestor, double event_id);
	static Subscriber* RemoveEventSubscriber(Subscriber *requestor, double event_id);
	static std::list<Subscriber*> GetAllSubscribers(void* owner);

	static void DispatchEvent(double eventID, std::shared_ptr<void> eventData);

private:
	static void Process();
};
