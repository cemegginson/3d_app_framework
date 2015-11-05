#pragma once

#include <memory>
#include <string>

#include "Box2D/Box2D.h"
#include "Core/PugiXML/pugixml.hpp"

#include "Library/ArtAssetLibrary.h"

#include "Component/Animation.h"
#include "Component/Bullet.h"
#include "Component/Carrier.h"
#include "Component/Infantry.h"
#include "Component/Player.h"


#include "Core/InputDevice.h"
#include "Core/Sprite.h"
#include "Core/Physics.h"

#include "Virtual/Component.h"

class ComponentFactory {
protected:

public:
    ComponentFactory();
    virtual ~ComponentFactory() = 0;
    virtual Component* Create(Actor*, pugi::xml_node) = 0;
};

class CarrierFactory : ComponentFactory {
protected:
public:
    CarrierFactory();
    ~CarrierFactory();
    Carrier* Create(Actor*, pugi::xml_node);
};

class InfantryFactory : ComponentFactory {
protected:
public:
    InfantryFactory();
    ~InfantryFactory();
    Infantry* Create(Actor*, pugi::xml_node);
};

class PlayerFactory : ComponentFactory {
protected:
    InputDevice* input_device_;

public:
    PlayerFactory(InputDevice*);
    ~PlayerFactory();
    Player* Create(Actor*, pugi::xml_node);
};

/*
class RigidCircleFactory : ComponentFactory {
protected:
    b2World* world_;

public:
    RigidCircleFactory(b2World*);
    ~RigidCircleFactory();
    RigidCircle* Create(Actor*, pugi::xml_node);
};
*/

class RigidRectangleFactory : ComponentFactory {
protected:
    b2World* world_;

public:
    RigidRectangleFactory(b2World*);
    ~RigidRectangleFactory();
    RigidRectangle* Create(Actor*, pugi::xml_node);
};

class SpriteFactory : ComponentFactory {
protected:
    GraphicsDevice* graphics_device_;
    ArtAssetLibrary* art_library_;

public:
    SpriteFactory(GraphicsDevice*, ArtAssetLibrary*);
    ~SpriteFactory();
    Sprite* Create(Actor*, pugi::xml_node);
};

class AnimationFactory : ComponentFactory {
protected:


public:
    AnimationFactory();
    ~AnimationFactory();
    Animation* Create(Actor*, pugi::xml_node);
};
