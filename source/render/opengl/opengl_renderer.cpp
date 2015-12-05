#include <SDL.h>
#include <GL/glew.h>
#include <SDL_opengl.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "render/opengl/opengl_renderer.h"
#include "util/game_utils.h"

OpenGLRenderer::OpenGLRenderer() {
    window_ = nullptr;
    // renderer_ = nullptr;
    width_ = 0;
    height_ = 0;
}

OpenGLRenderer::OpenGLRenderer(uint32 screen_width, uint32 screen_height) {
    window_ = nullptr;
    // renderer_ = nullptr;
    width_ = screen_width;
    height_ = screen_height;
}

OpenGLRenderer::~OpenGLRenderer() {
    SDL_GL_DeleteContext(context_);
    SDL_DestroyWindow(window_);
}

bool OpenGLRenderer::Initialize() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        LogSDLError(std::cerr, "SDL_Init");
        return false;
    }

    window_ = SDL_CreateWindow("Game Engine",
                               SDL_WINDOWPOS_UNDEFINED,
                               SDL_WINDOWPOS_UNDEFINED,
                               width_,
                               height_,
                               SDL_WINDOW_RESIZABLE
    );

    if (window_ == nullptr) {
        LogSDLError(std::cerr, "SDL_CreateWindow");
        return false;
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    context_ = SDL_GL_CreateContext(window);
    if(context_ == NULL) {
        std::cerr << "SDL_GL_CreateContext: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_GL_SetSwapInterval(1);

    return true;
}

inline void OpenGLRenderer::PreDraw() {
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

inline void OpenGLRenderer::Draw() {

}

inline void OpenGLRenderer::PostDraw() {
    SDL_GL_SwapWindow(window_);
}

inline RENDER_TYPE OpenGLRenderer::type() {
    return RENDER_TYPE::OPENGL;
}

uint32 OpenGLRenderer::width() {
    return width_;
}
uint32 OpenGLRenderer::height() {
    return height_;
}
