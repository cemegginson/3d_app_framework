#pragma once

#include <list>
#include <string>

#include "art_library/ComponentLibrary.h"
#include "render/opengl/gl_model_store.h"

#include "core/timer.h"
#include "render/sdl/sdl_camera.h"

#include "render/renderer.h"

#include "virtual/component.h"

class App3D : App {
protected:
    ComponentLibrary* component_factories_;
    InputDevice* input_device_;
    Timer* timer_;

    OpenGLRenderer* renderer_;
    GlCamera* camera_;
    GlModelStore* model_store_;

    std::list<Actor*> actors_;

public:
    App3D();
    ~App3D();
    bool Initialize(Renderer*, InputDevice*);
    void Reset();
    bool LoadLevel(std::string);
    void Run();
    void Update(float32);
}
