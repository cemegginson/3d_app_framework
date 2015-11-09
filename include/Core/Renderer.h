#pragma once

#include <vector>
#include <memory>

#include "SDL.h"

#include "Util/Definitions.h"
#include "Core/Sprite.h"

class Sprite;

class Renderer {
public:
    virtual bool Initialize() = 0;
    virtual void Render() = 0;

    virtual uint32 width() = 0;
    virtual uint32 height() = 0;
};
