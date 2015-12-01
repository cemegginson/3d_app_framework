#pragma once

#include <vector>
#include <memory>

#include "util/definitions.h"

class Renderer {
public:
    virtual ~Renderer() {}

    virtual bool Initialize() = 0;
    virtual void Render() = 0;

    virtual uint32 width() = 0;
    virtual uint32 height() = 0;
};
