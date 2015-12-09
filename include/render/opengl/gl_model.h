#pragma once

#include <SDL.h>
#include <GL/glew.h>
#include <SDL_opengl.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "util/definitions.h"
#include "render/renderer.h"

Class GlModel {
protected:
    GLuint vertex_buffer_object_;

public:
    GlModel();
    ~GlModel();
}
