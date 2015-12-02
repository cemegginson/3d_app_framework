#pragma once

#include <vector>
#include <memory>

#include "util/definitions.h"

class Renderer {
public:
    virtual ~Renderer() {}

    virtual bool Initialize() = 0;
    virtual RENDER_TYPE type() = 0;

    virtual inline void PreDraw() = 0;
    virtual inline void Draw() = 0;
    virtual inline void PostDraw() = 0;

    virtual uint32 width() = 0;
    virtual uint32 height() = 0;
};
