#pragma once

#include <string>
#include <Box2D/Box2D.h>

#include "Component.h"
#include "Definitions.h"

// Base Rigidbody class
class Rigidbody {
protected:
	std::string type_;
	std::string shape_;
    b2World* world_;
    b2Body* body_;

    bool controllable_;

public:
    Rigidbody();
    ~Rigidbody();
    virtual void Initialize(b2World*, b2BodyDef, b2FixtureDef) = 0;
    // void Update(float32);
    // void ExportPosition();
    // void ExportAngle();
	// void ImportPosition();
	// void ImportAngle();
};

// Physics Circles
class RigidCircle : public Rigidbody, public Component{
protected:
	float32 radius;

public:
	RigidCircle(std::shared_ptr<Actor>);
	~RigidCircle();
	void Initialize(b2World*, b2BodyDef, b2FixtureDef);
	void Update(float32);
	b2Vec2 ExportPosition();
	float32 ExportAngle();
	b2Vec2 ImportPosition();
	float32 ImportAngle();
};

// Physics Rectangles
class RigidRectangle : public Rigidbody, public Component {
protected:

public:
	RigidRectangle(std::shared_ptr<Actor>);
	~RigidRectangle();
	void Initialize(b2World*, b2BodyDef, b2FixtureDef);
	void Update(float32);
	b2Vec2 ExportPosition();
	float32 ExportAngle();
	b2Vec2 ImportPosition();
	float32 ImportAngle();
};
