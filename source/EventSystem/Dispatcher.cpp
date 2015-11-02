#include "EventSystem/Dispatcher.h"

//Begin Dispatcher static variables
bool Dispatcher::inited;
bool Dispatcher::running;
bool Dispatcher::processing;
bool Dispatcher::dispatchLock;
bool Dispatcher::subscriberLock;
bool Dispatcher::mappedLock;

Dispatcher* Dispatcher::theInstance;

std::deque<std::pair<double,std::shared_ptr<void>>>*  Dispatcher::dispatchEvents;
std::map<int,std::list<Subscriber*>*>* Dispatcher::mappedEvents;

std::thread Dispatcher::processingThread;
double* Dispatcher::localDeltaTime;
//End Dispatcher Static Variables



//Begin Class Methods
Dispatcher::Dispatcher() { }

Dispatcher* Dispatcher::GetInstance() {
    if(theInstance == nullptr) Initialize();
    return theInstance;
}

void Dispatcher::Initialize() {
    if(!inited) {
        inited = true;
        //can't put these 2 lines on one because clang is retarded (but has nice errors)
        Dispatcher d;
        theInstance = &d;
        ////////

        dispatchEvents  = new std::deque<std::pair<double,std::shared_ptr<void>>>();
        mappedEvents    = new std::map<int,std::list<Subscriber*>*>();

        running = true;
        processing = true;
        dispatchLock = false;
        mappedLock = false;
        subscriberLock = false;

        localDeltaTime = (double*)0;
        processingThread = std::thread(Process, localDeltaTime); //starts the processing thread
        processingThread.detach(); //it probably won't terminate before the end of this program so we want to ignore errors
    } else {
        std::cerr << "Attempting to reinitialize a dispatcher...  Ignoring." << std::endl;
    }
}

void Dispatcher::Process(double* deltaTime) {
    while(running) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));

        while(processing && running) {
            if(!dispatchLock) {
                if(dispatchEvents->size()==0) { // if no events have been dispatched, wait a little longer
                    sleep(1);
                    continue;
                }
                //events have been dispatched so force other threads to block when dispatching new events
                dispatchLock = true;

                //get the first event pair
                std::pair<double, std::shared_ptr<void>> eventPair = std::pair<double, std::shared_ptr<void>>(dispatchEvents->at(0).first, dispatchEvents->at(0).second);
                dispatchEvents->pop_front();
                                            //copy consturctor for thread safety
                dispatchLock = false;        //and so we can unlock the list so more can be dispatched

                //wait to acquire the map lock
                while(mappedLock && processing) sleep(1);
                if(!processing) break;
                mappedLock = true;

                //got the lock but only lock the subscribers if we need to
                if(mappedEvents->count(eventPair.first) > 0) {
                    // if subscribers are listening for this event specifically
                    //we need to acquire the subscriber lock too
                    while(subscriberLock && processing) sleep(1);
                    if(!processing) { mappedLock = false; break; }
                    subscriberLock = true;
                    //got it

                    for(auto subscriber : *mappedEvents->at(eventPair.first)) {
                        if(!subscriber) { // warn of null subscribers
                            std::cerr << "Dispatcher --->  Null subscriber in SpecificEventSubscribers." << std::endl;
                            continue;
                        }
                        //if the subscriber has a method to be called then call it
                        if(subscriber && subscriber->method) {
                            if(eventPair.second) subscriber->method(eventPair.second);
                            else subscriber->method(nullptr);
                        }
                    }
                }
                //we're done with the map so unlock it
                mappedLock = false;

                //done with subscribers now
                subscriberLock = false;
            }
        }
    }
    //Something forced us out of our loop
    std::cerr << "Processing thread terminated?" << std::endl;
}

void Dispatcher::DispatchEvent(double eventID, std::shared_ptr<void> eventData) {
    //std::cout << "Dispatcher --->  Received event " << eventID << "." << std::endl;
    dispatchEvents->push_back(std::pair<double,std::shared_ptr<void>>(eventID, eventData));
}

void Dispatcher::AddEventSubscriber(Subscriber *requestor, double event_id) {
    if(mappedEvents->count(event_id) < 1) {
        std::cerr << "Dispatcher --->  Dynamically allocating list for Specific EventID " << event_id << "." << std::endl << "Dispatcher --->  This should be avoided for performance reasons." << std::endl;
        mappedEvents->emplace(event_id, new std::list<Subscriber*>());
    }
    mappedEvents->at(event_id)->push_back(requestor);
}

Subscriber* Dispatcher::RemoveEventSubscriber(Subscriber *requestor, double event_id) {
    while(mappedLock && processing) sleep(1);
    mappedLock = true;

    if(mappedEvents->find(event_id) != mappedEvents->end()) {

        while(subscriberLock && processing) sleep(1);
        subscriberLock = true;

        auto list = std::list<Subscriber*>();
        Subscriber* s = nullptr;

        for(auto sub : *mappedEvents->at(event_id)) {
            if(sub == requestor) list.push_back(sub);
        }

        for(auto sub : list) {
            s = sub;
            mappedEvents->at(event_id)->remove(sub);
        }
        mappedLock = false;
        subscriberLock = false;
        return s;
    }
    return nullptr;
}

//TODO reimplement using map traversal
std::list<Subscriber*> Dispatcher::GetAllSubscribers(void* owner) {
    std::list<Subscriber*> tmp;

    subscriberLock = false;
    return tmp;
}

void Dispatcher::Stop() {
    processing = false;
    sleep(100);
}

void Dispatcher::Start() {
    processing = true;
}

void Dispatcher::Terminate() {
    running = false;
    processing = false;
    sleep(100);
}
