#include "Core/OpenGLRenderer"

OpenGLRenderer::OpenGLRenderer() {
    window_ = nullptr;
    renderer_ = nullptr;
    width_ = 0;
    height_ = 0;
}

OpenGLRenderer::OpenGLRenderer(uint32 screen_width, uint32 screen_height) {
    window_ = nullptr;
    renderer_ = nullptr;
    width_ = screen_width;
    height_ = screen_height;
}

OpenGLRenderer::~OpenGLRenderer() {
    SDL_DestroyWindow(window_);
}

bool OpenGLRenderer::Initialize(){
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
}
void OpenGLRenderer::Render(){
    glClear ( GL_COLOR_BUFFER_BIT );

    SDL_GL_SwapWindow(window_);
}

int OpenGLRenderer::width(){
    return width_;
}
int OpenGLRenderer::height(){
    return height_;
}
