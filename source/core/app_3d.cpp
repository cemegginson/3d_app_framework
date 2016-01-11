#include <iostream>
#include <string>

#include "core/app_3d.h"
#include "core/PugiXML/pugixml.hpp"

#include "render/opengl/gl_drawable.h"

App3D::App3D() {
    // component_factories_ = nullptr;
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
    // if (component_factories_ != nullptr) {
    //     delete component_factories_;
    //     component_factories_ = nullptr;
    // }
    if (model_store_ != nullptr) {
        delete model_store_;
        model_store_ = nullptr;
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
    renderer_ = static_cast<OpenGLRenderer*>(renderer);
    input_device_ = input_device;

    camera_ = new GlCamera();
    camera_->Initialize();

    renderer_->set_camera(camera_);

    model_store_ = new GlModelStore();
    model_store_->LoadAssets();

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
    // component_factories_ = new ComponentLibrary();

    // component_factories_->AddFactory("GlDrawable", reinterpret_cast<ComponentFactory*>(new GlDrawableFactory()));

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
    // pugi::xml_document doc;
    // pugi::xml_parse_result result = doc.load_file(file.c_str());
    // if (result) {
    //     pugi::xml_node Level = doc.child("Level");
    //
    //     // Loop through Actor XML nodes
    //     for (pugi::xml_node actor_node : Level.children("Actor")) {
    //         std::string name = actor_node.attribute("name").value();
    //         bool controllable = std::stoi(actor_node.attribute("controllable").value());
    //
    //         Vector2 position;
    //         position.x = std::stof(actor_node.attribute("x").value());
    //         position.y = std::stof(actor_node.attribute("y").value());
    //         float32 angle = std::stof(actor_node.attribute("angle").value());
    //
    //         Actor* new_actor = new Actor();
    //         new_actor->Initialize(name, position, angle, controllable);
    //
    //         // Loop through Component XML nodes
    //         for (pugi::xml_node component_node : actor_node.children("Component")) {
    //             std::string type = component_node.attribute("type").value();
    //             Component* new_component = reinterpret_cast<Component*>(component_factories_->Search(type)->Create(new_actor, component_node));
    //             new_actor->AddComponent(new_component);
    //         }
    //         actors_.push_back(new_actor);
    //     }
    // }

    Actor3D* new_actor = new Actor3D();
    // new_actor->Initialize("cube")
    std::string model = "cube";

    GlDrawable* new_gldrawable = new GlDrawable(new_actor);
    new_gldrawable->Initialize(renderer_, model_store_->Search(model));
    Component* new_component = static_cast<Component*>(new_gldrawable);
    new_actor->AddComponent(new_component);

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
    std::cout << "App3D::Update -> FPS = " << 1/delta_time << "\r";

    Dispatcher::GetInstance()->DispatchEvent("EVENT_COMPONENT_UPDATE", std::make_shared<float32>(delta_time));
    // Dispatcher::GetInstance()->DispatchEvent("EVENT_PHYSICS_UPDATE", std::make_shared<float32>(delta_time));

    Dispatcher::GetInstance()->Pump();
    Dispatcher::GetInstance()->NonSerialProcess();

    // We have to wait for all threads to finish before terminating this function
    // otherwise updating and rendering might access the same variables simultaniously
    // this is a work around while a better solution is put into Dispatcher
    while (Dispatcher::GetInstance()->QueueSize() > 0) {
        // std::cout << "Thread queue is too full...  waiting a bit" << std::endl;
        sleep(1);
    }

    // Cycle through every objects' Update method
    // for (auto iter = actors_.begin(); iter != actors_.end(); ++iter) {
    //    (*iter)->Update(delta_time);
    // }
}
