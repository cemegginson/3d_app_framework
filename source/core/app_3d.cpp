#include <iostream>
#include <string>

#include "core/app_3d.h"
#include "core/PugiXML/pugixml.hpp"

App3D::App3D() {
    component_factories_ = nullptr;
    model_store_ = nullptr;
    renderer_ = nullptr;
    input_device_ = nullptr;
    timer_ = nullptr;
    camera_ = nullptr;
}

App3D::~App3D() {
    while (actors_.size() > 0) {
        delete actors_.back();
        actors_.pop_back();
    }
    if (component_factories_ != nullptr) {
        delete component_factories_;
        component_factories_ = nullptr;
    }
    if (model_store_ != nullptr) {
        delete art_library_;
        art_library_ = nullptr;
    }
    if (camera_ != nullptr) {
        delete camera_;
        camera_ = nullptr;
    }
    if (timer_ != nullptr) {
        delete timer_;
        timer_ = nullptr;
    }
}

bool App3D::Initialize(Renderer* renderer,
                       InputDevice* input_device) {
    renderer_ = renderer;
    input_device_ = input_device;

    camera_ = new GlCamera();
    camera_->Initialize(input_device_);

    // Load sprites
    art_library_ = new ArtAssetLibrary();
    art_library_->LoadAssets(renderer_, camera_);

    timer_ = new Timer();
    timer_->Start();

    uint32 screen_width = 800;
    uint32 screen_height = 600;

    // #ifndef NDEBUG
    //     debug_subscriber_ = new Subscriber(this);
    //     debug_subscriber_->method = std::bind(&App3D::printFrameRate, this, std::placeholders::_1);
    //     Dispatcher::GetInstance()->AddEventSubscriber(debug_subscriber_, "EVENT_COMPONENT_UPDATE");
    // #endif

    // Create Factories
    component_factories_ = new ComponentLibrary();

    component_factories_->AddFactory("Animation", reinterpret_cast<ComponentFactory*>(new AnimationFactory()));
    component_factories_->AddFactory("Carrier", reinterpret_cast<ComponentFactory*>(new CarrierFactory()));
    component_factories_->AddFactory("Infantry", reinterpret_cast<ComponentFactory*>(new InfantryFactory()));
    component_factories_->AddFactory("Player", reinterpret_cast<ComponentFactory*>(new PlayerFactory(input_device_)));
    // component_factories_->AddFactory("RigidCircle", reinterpret_cast<ComponentFactory*>new RigidCircleFactory(world_));
    component_factories_->AddFactory("RigidRectangle", reinterpret_cast<ComponentFactory*>(new RigidRectangleFactory(world_)));
    component_factories_->AddFactory("Sprite", reinterpret_cast<ComponentFactory*>(new SpriteFactory(renderer_, art_library_)));

    return true;
}

void App3D::Reset() {
    // if(!actors_.empty()){
    //     for (auto iter = actors_.begin(); iter != actors_.end(); iter++) {
    //         delete *iter;
    //     }
    // }
}

bool App3D::LoadLevel(std::string file) {
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(file.c_str());
    if (result) {
        pugi::xml_node Level = doc.child("Level");

        // Loop through Actor XML nodes
        for (pugi::xml_node actor_node : Level.children("Actor")) {
            std::string name = actor_node.attribute("name").value();
            bool controllable = std::stoi(actor_node.attribute("controllable").value());

            Vector2 position;
            position.x = std::stof(actor_node.attribute("x").value());
            position.y = std::stof(actor_node.attribute("y").value());
            float32 angle = std::stof(actor_node.attribute("angle").value());

            Actor* new_actor = new Actor();
            new_actor->Initialize(name, position, angle, controllable);

            // Loop through Component XML nodes
            for (pugi::xml_node component_node : actor_node.children("Component")) {
                std::string type = component_node.attribute("type").value();
                Component* new_component = reinterpret_cast<Component*>(component_factories_->Search(type)->Create(new_actor, component_node));
                new_actor->AddComponent(new_component);
            }
            actors_.push_back(new_actor);
        }
    }
    return true;
}

void App3D::Run() {
    Update(timer_->DeltaTime());
    timer_->Update();

    renderer_->PreDraw();
    renderer_->Draw();
    renderer_->PostDraw();
}

void App3D::Update(float32 delta_time) {
    // Update Camera position
    camera_->Update(delta_time);

    Dispatcher::GetInstance()->DispatchEvent("EVENT_COMPONENT_UPDATE",    std::make_shared<float32>(delta_time));
    Dispatcher::GetInstance()->DispatchEvent("EVENT_PHYSICS_UPDATE",      std::make_shared<float32>(delta_time));

    Dispatcher::GetInstance()->Pump();
	Dispatcher::GetInstance()->NonSerialProcess(); //do processing of subscriber objects that can't be run in the thread pool

    // keep this condition low enough to keep the game feeling non-laggy but high enough to keep threads busy
    while (Dispatcher::GetInstance()->QueueSize() > 128) {
        std::cout << "Thread queue is too full...  waiting a bit" << std::endl;
        sleep(1);
    }

    // Cycle through every objects' Update method
    // for (auto iter = actors_.begin(); iter != actors_.end(); ++iter) {
    //    (*iter)->Update(delta_time);
    // }
}
