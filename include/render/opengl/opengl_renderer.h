#pragma once

#include <vector>
#include <memory>

// Opengl related includes
#include <SDL.h>
#include <GL/glew.h>
#include <SDL_opengl.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "util/definitions.h"
#include "render/renderer.h"
#include "render/opengl/opengl_camera.h"

class Sprite;

class OpenGLRenderer : public Renderer {
protected:
    SDL_Window* window_;
    SDL_GLContext context_;
    OpenGlCamera* camera_;
    GLuint mvp_uniform_;

    uint32 width_;
    uint32 height_;

public:
    OpenGLRenderer();
    OpenGLRenderer(uint32 screen_width, uint32 screen_height);

    ~OpenGLRenderer();

    bool Initialize();

    inline void PreDraw();
    inline void Draw();
    inline void PostDraw();

    RENDER_TYPE type();
    uint32 width();
    uint32 height();
};
