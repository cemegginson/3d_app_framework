#pragma once

#include "virtual/component.h"
#include "render/opengl/gl_model.h"

class GlDrawable : Component {
protected:
    Actor* owner_;
    std::vector<Subscriber*> subscribers_;
    GlModel* model_;

public:
    GlDrawable(GlModel*);
    ~GlDrawable();

    void Initialize(GlModel*);
    void Update(float32);
    void Draw();
};
