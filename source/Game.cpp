#include <iostream>

// #include "ContactListener.h"
#include "Game.h"
#include "GameFunctions.h"
#include "pugixml.hpp"

Game::Game() {
	component_factories_ = nullptr;
	art_library_ = nullptr;
	graphics_device_ = nullptr;
	input_device_ = nullptr;
	timer_ = nullptr;
	view_ = nullptr;
	physics_delta_time_ = 1.0/100.0;
	velocity_iterations_ = 25;
	position_iterations_ = 10;
}

Game::~Game() {
	delete component_factories_;
	delete art_library_;
	delete graphics_device_;
	delete input_device_;
	delete view_;
}

bool Game::Initialize(GraphicsDevice* graphics_device, InputDevice* input_device) {
	graphics_device_ = graphics_device;
	input_device_ = input_device;

	view_ = new View();
	view_->Initialize(input_device_, 0, 0);

	// Load sprites
	art_library_ = new ArtAssetLibrary();
	art_library_->LoadAssets(graphics_device_, view_);

	timer_ = new Timer();
	timer_->Start();

	// Initialize Physics world
	const b2Vec2 gravity(0, 0);
	world_ = new b2World(gravity);

	// Create Factories
	component_factories_ = new ComponentLibrary();
	component_factories_->AddFactory("Carrier", (ComponentFactory*)new CarrierFactory());
	component_factories_->AddFactory("Infantry", (ComponentFactory*)new InfantryFactory());
	component_factories_->AddFactory("Player", (ComponentFactory*)new PlayerFactory(input_device_));
	component_factories_->AddFactory("Sprite", (ComponentFactory*)new SpriteFactory(graphics_device_, art_library_));
	component_factories_->AddFactory("RigidCircle", (ComponentFactory*)new RigidCircleFactory(world_));
	component_factories_->AddFactory("RigidRectangle", (ComponentFactory*)new RigidRectangleFactory(world_));

	// ContactListener* contact_listener = new ContactListener();
	// world_->SetContactListener(contact_listener);

	return true;
}

void Game::Reset() {
	// if(!actors_.empty()){
	// 	for (auto iter = actors_.begin(); iter != actors_.end(); iter++) {
	// 		delete *iter;
	// 	}
	// }
}

bool Game::LoadLevel(std::string file) {
	std::shared_ptr<Actor> new_actor;
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file(file.c_str());
	if (result) {
		pugi::xml_node Level = doc.child("Level");

		// Temporary variables for Actor creation
		std::string name;
		std::shared_ptr<Actor> new_actor;
		Vector2 position;
		float32 angle;
		bool controllable;

		// Temporary variables for Component creation
		Component* new_component;
		std::string type;

		// Loop through Actor XML nodes
		for (pugi::xml_node actor_node : Level.children("Actor")) {
			new_actor.reset(new Actor());
			name = actor_node.attribute("name").value();
			controllable = std::stoi(actor_node.attribute("controllable").value());
			position.x = std::stof(actor_node.attribute("x").value());
			position.y = std::stof(actor_node.attribute("y").value());
			angle = std::stof(actor_node.attribute("angle").value());
			new_actor->Initialize(name, position, angle, controllable);

			// Loop through Component XML nodes
			for (pugi::xml_node component_node : actor_node.children("Component")) {
				type = component_node.attribute("type").value();
				new_component = component_factories_->Search(type)->Create(new_actor, component_node);
				new_actor->AddComponent(new_component);
			}
			actors_.push_back(new_actor);
		}
	}
	return true;
}

void Game::Run() {
	timer_->Update();
	Update(timer_->DeltaTime());
	graphics_device_->Render();
}

void Game::Update(float32 delta_time) {
	// Update View position
	view_->Update(delta_time);

	// Cycle through every objects' Update method
	for (auto iter = actors_.begin(); iter != actors_.end(); ++iter) {
		(*iter)->Update(delta_time);
	}

	world_->Step(physics_delta_time_, velocity_iterations_, position_iterations_);
}
