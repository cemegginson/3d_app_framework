#include <math.h>

#include "GameFunctions.h"
#include "Physics.h"

Rigidbody::Rigidbody() {
    ;
}

Rigidbody::~Rigidbody() {
    world_->DestroyBody(body_);
}


// RigidCircle methods

RigidCircle::RigidCircle(std::shared_ptr<Actor> owner) : Component(owner), Rigidbody() {
    ;
}

RigidCircle::~RigidCircle() {
    ;
}

void RigidCircle::Initialize(b2World* world, b2BodyDef body_definition, b2FixtureDef shape_fixture_definition) {
    world_ = world;
    body_ = world->CreateBody(&body_definition);
    body_->CreateFixture(&shape_fixture_definition);
    controllable_ = owner_->IsControllable();
}

void RigidCircle::Update(float32 delta_time) {
    b2Vec2 new_direction;
    float32 angle = body_->GetAngle();
    float32 angular_velocity = 0;
    float32 velocity = 30;
    new_direction.x = 0;
    new_direction.y = 0;
    if(controllable_) {

        if(owner_->CheckEvent(TURN_LEFT)) {
            angular_velocity -= PI;
        }
        if(owner_->CheckEvent(TURN_RIGHT)) {
            angular_velocity += PI;
        }
        if(owner_->CheckEvent(MOVE_UP)) {
            new_direction.x += velocity * cos(angle - PI/2);
    		new_direction.y += velocity * sin(angle - PI/2);
        }
        if(owner_->CheckEvent(MOVE_DOWN)) {
            new_direction.x -= velocity * cos(angle - PI/2);
    		new_direction.y -= velocity * sin(angle - PI/2);
        }
        if(owner_->CheckEvent(MOVE_LEFT)) {
            new_direction.x -= 1;
        }
        if(owner_->CheckEvent(MOVE_RIGHT)) {
            new_direction.x += 1;
        }

        body_->SetLinearVelocity(new_direction);
        body_->SetAngularVelocity(angular_velocity);
    }
    ExportPosition();
    ExportAngle();
}

b2Vec2 RigidCircle::ExportPosition() {
    b2Vec2 physics_position = body_->GetPosition();
    Vector2 render_position;
    render_position.x = PW2RW(physics_position.x);
    render_position.y = PW2RW(physics_position.y);
    owner_->SetPosition(render_position);
    return physics_position;
}

float32 RigidCircle::ExportAngle() {
    float32 physics_angle = body_->GetAngle();
    owner_->SetAngle(PW2RWAngle(physics_angle));
    return physics_angle;
}

b2Vec2 RigidCircle::ImportPosition() {
    Vector2 render_position = owner_->GetPosition();
    b2Vec2 physics_position;
    physics_position.x = RW2PW(render_position.x);
    physics_position.y = RW2PW(render_position.y);
    return physics_position;
}

float32 RigidCircle::ImportAngle() {
    return RW2PWAngle(owner_->GetAngle());
}

// RigidRectangle methods

RigidRectangle::RigidRectangle(std::shared_ptr<Actor> owner) : Component(owner), Rigidbody() {
    ;
}

RigidRectangle::~RigidRectangle() {
    ;
}

void RigidRectangle::Initialize(b2World* world, b2BodyDef body_definition, b2FixtureDef shape_fixture_definition) {
    world_ = world;
    body_ = world->CreateBody(&body_definition);
    body_->CreateFixture(&shape_fixture_definition);
    controllable_ = owner_->IsControllable();
}

void RigidRectangle::Update(float32 delta_time) {
    b2Vec2 new_direction;
    float32 angle = body_->GetAngle();
    float32 angular_velocity = 0;
    float32 velocity = 30;
    new_direction.x = 0;
    new_direction.y = 0;

    b2Vec2 jump;
    jump.x = 0;
    jump.y = 5;

    if(controllable_) {
        if(owner_->CheckEvent(TURN_LEFT)) {
            angular_velocity -= PI;
        }
        if(owner_->CheckEvent(TURN_RIGHT)) {
            angular_velocity += PI;
        }
        if(owner_->CheckEvent(MOVE_UP)) {
            body_->ApplyForceToCenter(jump, 1);
        }
        if(owner_->CheckEvent(MOVE_DOWN)) {
            ;
        }
        if(owner_->CheckEvent(MOVE_LEFT)) {
            new_direction.x -= 30;
        }
        if(owner_->CheckEvent(MOVE_RIGHT)) {
            new_direction.x += 30;
        }

        body_->SetLinearVelocity(new_direction);
        body_->SetAngularVelocity(angular_velocity);
    }
    ExportPosition();
    ExportAngle();
}

b2Vec2 RigidRectangle::ExportPosition() {
    b2Vec2 physics_position = body_->GetPosition();
    Vector2 render_position;
    render_position.x = PW2RW(physics_position.x);
    render_position.y = PW2RW(physics_position.y);
    owner_->SetPosition(render_position);
    return physics_position;
}

float32 RigidRectangle::ExportAngle() {
    float32 physics_angle = body_->GetAngle();
    owner_->SetAngle(PW2RWAngle(physics_angle));
    return physics_angle;
}

b2Vec2 RigidRectangle::ImportPosition() {
    Vector2 render_position = owner_->GetPosition();
    b2Vec2 physics_position;
    physics_position.x = RW2PW(render_position.x);
    physics_position.y = RW2PW(render_position.y);
    return physics_position;
}

float32 RigidRectangle::ImportAngle() {
    return RW2PWAngle(owner_->GetAngle());
}
