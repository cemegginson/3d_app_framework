#pragma once

#include "virtual/component.h"

#include "render/opengl/gl_model.h"
#include "render/opengl/actor_3d.h"

class GlDrawable : public Component {
protected:
    Actor3D* owner_;
    std::vector<Subscriber*> subscribers_;
    GlModel* model_;

public:
    GlDrawable(Actor3D*);
    ~GlDrawable();

    void Initialize(GlModel*);
    void Update(std::shared_ptr<void> delta_time);
    void Draw();
};
