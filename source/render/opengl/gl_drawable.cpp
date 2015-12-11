#include "render/opengl/gl_drawable.h"

GlDrawable::GlDrawable(Actor3D* owner) {
    owner_ = owner;
}

GlDrawable::~GlDrawable() {
    owner_ = nullptr;
}

void GlDrawable::Initialize(GlModel* model) {
    model_ = model;
}

void GlDrawable::Update(std::shared_ptr<void> delta_time) {

}

void GlDrawable::Draw() {
    model_->Draw();
}
