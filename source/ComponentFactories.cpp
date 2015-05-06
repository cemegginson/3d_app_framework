#include <iostream>
#include <stdlib.h>
#include <string>

#include "pugixml.hpp"

#include "ComponentFactories.h"
#include "GameFunctions.h"

// Raw ComponentFactory stuff
ComponentFactory::ComponentFactory() {}

ComponentFactory::~ComponentFactory() {}


// CarrierFactory stuff
CarrierFactory::CarrierFactory() : ComponentFactory() {}

CarrierFactory::~CarrierFactory() {}

Carrier* CarrierFactory::Create(std::shared_ptr<Actor> owner, pugi::xml_node node) {
	Carrier* carrier = new Carrier(owner);
	return carrier;
}


// InfantryFactory stuff
InfantryFactory::InfantryFactory() : ComponentFactory() {}

InfantryFactory::~InfantryFactory() {}

Infantry* InfantryFactory::Create(std::shared_ptr<Actor> owner, pugi::xml_node node) {
	Infantry* infantry = new Infantry(owner);
	return infantry;
}


// PlayerFactory stuff
PlayerFactory::PlayerFactory(InputDevice* input_device) : ComponentFactory() {
	input_device_ = input_device;
}

PlayerFactory::~PlayerFactory() {}

Player* PlayerFactory::Create(std::shared_ptr<Actor> owner, pugi::xml_node node) {
	Player* player = new Player(owner);
	player->SetInput(input_device_);
	return player;
}


// RigidbodyFactory stuff
RigidCircleFactory::RigidCircleFactory(b2World* world) : ComponentFactory() {
	world_ = world;
}

RigidCircleFactory::~RigidCircleFactory() {}

RigidCircle* RigidCircleFactory::Create(std::shared_ptr<Actor> owner, pugi::xml_node node) {
	RigidCircle* rigid_circle = new RigidCircle(owner);
	Vector2 position = owner->GetPosition();
	b2BodyDef body_definition;
	b2CircleShape circle_shape;
	b2FixtureDef shape_fixture_definition;

	if(std::stof(node.attribute("dynamic").value())) {
		body_definition.type = b2_dynamicBody;
	} else {
		body_definition.type = b2_staticBody;
	}

	// body_definition.bullet = true;
	body_definition.position.Set(RW2PW(position.x), RW2PW(position.y));
	body_definition.angle = RW2PWAngle(owner->GetAngle());
	body_definition.angularDamping = std::stof(node.attribute("angular_damping").value());
	body_definition.linearDamping = std::stof(node.attribute("linear_damping").value());

	circle_shape.m_radius = RW2PW(std::stof(node.attribute("radius").value()));
	shape_fixture_definition.shape = &circle_shape;
	shape_fixture_definition.density = std::stof(node.attribute("density").value());
	shape_fixture_definition.friction = std::stof(node.attribute("friction").value());
	shape_fixture_definition.restitution = std::stof(node.attribute("restitution").value());

	bool movable, turnable;
	// movable = std::stof(node.attribute("movable").value());
	// turnable = std::stof(node.attribute("turnable").value());

	rigid_circle->Initialize(world_, body_definition, shape_fixture_definition);

	return rigid_circle;
}


// RigidbodyFactory stuff
RigidRectangleFactory::RigidRectangleFactory(b2World* world) : ComponentFactory() {
	world_ = world;
}

RigidRectangleFactory::~RigidRectangleFactory() {}

RigidRectangle* RigidRectangleFactory::Create(std::shared_ptr<Actor> owner, pugi::xml_node node) {
	RigidRectangle* rigid_rectangle = new RigidRectangle(owner);
	Vector2 position = owner->GetPosition();
	b2BodyDef body_definition;
	b2PolygonShape polygon_shape;
	b2FixtureDef shape_fixture_definition;

	if(std::stof(node.attribute("dynamic").value())) {
		body_definition.type = b2_dynamicBody;
	} else {
		body_definition.type = b2_staticBody;
	}

	// body_definition.bullet = true;
	body_definition.position.Set(RW2PW(position.x), RW2PW(position.y));
	body_definition.angle = RW2PWAngle(owner->GetAngle());
	body_definition.angularDamping = std::stof(node.attribute("angular_damping").value());
	body_definition.linearDamping = std::stof(node.attribute("linear_damping").value());

	Vector2 dimensions;
	dimensions.x = std::stof(node.attribute("width").value());
	dimensions.y = std::stof(node.attribute("height").value());
	polygon_shape.SetAsBox(RW2PW(dimensions.x), RW2PW(dimensions.y));
	shape_fixture_definition.shape = &polygon_shape;
	shape_fixture_definition.density = std::stof(node.attribute("density").value());
	shape_fixture_definition.friction = std::stof(node.attribute("friction").value());
	shape_fixture_definition.restitution = std::stof(node.attribute("restitution").value());

	bool movable, turnable;
	// movable = std::stof(node.attribute("movable").value());
	// turnable = std::stof(node.attribute("turnable").value());

	rigid_rectangle->Initialize(world_, body_definition, shape_fixture_definition);

	return rigid_rectangle;
}


// SpriteFactory stuff
SpriteFactory::SpriteFactory(GraphicsDevice* graphics_device, ArtAssetLibrary* art_library) : ComponentFactory() {
	graphics_device_ = graphics_device;
	art_library_ = art_library;
}

SpriteFactory::~SpriteFactory() {}

Sprite* SpriteFactory::Create(std::shared_ptr<Actor> owner, pugi::xml_node node) {
	Sprite* new_sprite = new Sprite(owner);
	std::string texture = node.attribute("texture").value();
	new_sprite->Initialize(graphics_device_, art_library_->Search(texture));
	return new_sprite;
}
