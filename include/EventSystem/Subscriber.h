#pragma once

#include "Globals.h"
#include <functional>


typedef void (SubscriptionFunction(void* eventData));

class Subscriber {
	public:
	    Subscriber(void* owner) {
			this->owner = owner;
		}
	    Subscriber(Subscriber &other) {
			this->owner = other.owner;
			this->method = other.method;
		}

	    std::function<SubscriptionFunction> method;

	    void* owner;
};
