#pragma once

#include "Globals.h"
//Begin Dispatcher Class Section


class Dispatcher {

private:
	static bool inited;
	static bool running;
	static bool processing;
	static bool dispatchLock;
	static bool subscriberLock;
	static bool mappedLock;

	static Dispatcher* theInstance;

	static std::vector<std::pair<double,void*>>*  dispatchEvents;
	static std::map<int,std::list<Subscriber*>*>* mappedEvents;

	static std::thread processingThread;
	static double* localDeltaTime;


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

	static void DispatchEvent(double eventID, void* eventData = nullptr);

private:
	static void Process(double* deltaTime);
};
