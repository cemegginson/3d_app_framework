#pragma once

#include "virtual/component.h"
#include "render/opengl/gl_model.h"

class GlDrawable : Component {
protected:
    GlModel* model_;

public:
    GlDrawable(GlModel*);
    ~GlDrawable();

    void Initialize(GlModel*);
    void Draw();
};
