#pragma once

#include <list>
#include <string>

#include "art_library/ComponentLibrary.h"
#include "render/opengl/gl_model_store.h"

#include "core/timer.h"

#include "render/opengl/gl_camera.h"
#include "render/opengl/opengl_renderer.h"
// #include "render/renderer.h"
#include "render/opengl/actor_3d.h"

#include "virtual/component.h"
#include "virtual/app.h"

class App3D : public App {
protected:
    // ComponentLibrary* component_factories_;
    InputDevice* input_device_;
    Timer* timer_;

    OpenGLRenderer* renderer_;
    GlCamera* camera_;
    GlModelStore* model_store_;

    std::list<Actor3D*> actors_;

public:
    App3D();
    ~App3D();
    bool Initialize(OpenGLRenderer*, InputDevice*);
    void Reset();
    bool LoadLevel(std::string);
    void Run();
    void Update(float32);
};
