#include "render/opengl/gl_drawable.h"

GlDrawable::GlDrawable(Actor* owner) {
    owner_ = owner;
}

GlDrawable::~GlDrawable() {

}

void GlDrawable::Update(float32 delta_time) {

}

void GlDrawable::Draw() {
    model_->Draw();
}
