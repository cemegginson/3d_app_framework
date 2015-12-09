#pragma once

#include <map>
#include <string>
#include <vector>

#include <SDL.h>
#include <GL/glew.h>
#include <SDL_opengl.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "render/opengl/gl_model.h"

Class GlModelStore {
protected:
    std::map<std::string, GlModel*> model_store_;
    GLuint* buffer_names_;

public:
    GlModelStore();
    ~GlModelStore();

    bool LoadAssets();
    GlModel* Search(std::string)
}
