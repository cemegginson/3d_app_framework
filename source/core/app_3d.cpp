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
    if (renderer_ != nullptr) {
        delete renderer_;
        renderer_ = nullptr;
    }
    if (input_device_ != nullptr) {
        delete input_device_;
        input_device_ = nullptr;
    }

    SDL_Quit();
}

bool App3D::Initialize() {
    SDL_Init(0);

    srand((unsigned int)time(NULL));

    uint32 screen_width = 800;
    uint32 screen_height = 600;

    renderer_ = new OpenGLRenderer(screen_width, screen_height);

    if (!renderer_->Initialize()) {
        printf("Graphics Device could not initialize!");
        return false;
    }

    input_device_ = new InputDevice();

    if (!input_device_->Initialize()) {
        printf("Input Device could not initialize!");
        exit(1);
    }

    camera_ = new GlCamera();
    camera_->Initialize(input_device_);

    renderer_->set_camera(camera_);

    model_store_ = new GlModelStore();
    model_store_->LoadAssets();

    timer_ = Timer::GetInstance();

    // Create Factories
    // component_factories_ = new ComponentLibrary();

    // component_factories_->AddFactory("GlDrawable", reinterpret_cast<ComponentFactory*>(new GlDrawableFactory()));

    std::string level_config_file = "foobar.xml";
    if (!LoadLevel(level_config_file)) {
        printf("Game could not load level %s: ", level_config_file.c_str());
        return false;
    }

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
    Actor* new_actor = new Actor();
    // new_actor->Initialize("cube")
    std::string model = "cube";

    GlDrawable* new_gldrawable = new GlDrawable(new_actor);
    new_gldrawable->Initialize(renderer_, model_store_->Search(model));
    Component* new_component = static_cast<Component*>(new_gldrawable);
    new_actor->AddComponent(new_component);

    return true;
}

void App3D::Run() {
    SDL_InitSubSystem(SDL_INIT_EVENTS);
    bool quit = false;
    while (!quit) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            // Update the Input Device with the Event
            if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) {
                input_device_->Update(&event);
            }
        }
        timer_->Update();

        Update();

        renderer_->PreDraw();
        renderer_->Draw();
        renderer_->PostDraw();
    }
}

void App3D::Update() {
    camera_->Update();
    std::cout << "App3D::Update -> FPS = " << 1 / timer_->delta_time() << "\r";

    // Cycle through every objects' Update method
    for (auto iter = actors_.begin(); iter != actors_.end(); ++iter) {
       (*iter)->Update();
    }
}
