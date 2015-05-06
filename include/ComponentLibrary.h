#pragma once

#include <iostream>
#include <map>
#include <string>
#include "ComponentFactories.h"

class ComponentLibrary {
protected:
	std::map<std::string, ComponentFactory*> component_factories_;

public:
	ComponentLibrary() {}
	~ComponentLibrary() {}

	void AddFactory(std::string name, ComponentFactory* factory) {
		component_factories_.insert(std::pair<std::string, ComponentFactory*>(name, factory));
		return;
	}

	ComponentFactory* Search(std::string component_type) {
		return component_factories_.at(component_type);
	}
};
