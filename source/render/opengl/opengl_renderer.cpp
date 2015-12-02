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
    // SDL_DestroyWindow(window_);
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

    return true;
}

inline void OpenGLRenderer::PreDraw() {
    // glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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
