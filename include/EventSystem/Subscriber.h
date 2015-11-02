#pragma once

#include "Definitions.h"
#include <functional>
#include "EventSystem/Dispatcher.h"

typedef void (SubscriptionFunction(std::shared_ptr<void>));

class Subscriber {
	public:
	    Subscriber(void* owner) {
			this->owner = owner;
		}
	    Subscriber(Subscriber &other) {
			this->owner = other.owner;
			this->method = other.method;
		}

/*  //Returns strongly typed std::bind objects with typed args and returns
	//Need a way to store this so that Dispatcher can call it

		template<typename R, typename C, typename... Args>
		std::function<R(Args...)> bind(R (C::* func)(Args...), C& instance) {
    		return [=](Args... args){ return (instance.*func)(args...); };
		}

		template<typename R, typename C, typename... Args>
		std::function<R(Args...)> bind(R (C::* func)(Args...) const, C const& instance) {
    		return [=](Args... args){ return (instance.*func)(args...); };
		}
*/
		std::function<SubscriptionFunction> method;

	    void* owner;
};
