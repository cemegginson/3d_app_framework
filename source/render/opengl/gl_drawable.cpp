#include "render/opengl/gl_drawable.h"

GlDrawable::GlDrawable(Actor* owner) : Component(owner){

}

GlDrawable::~GlDrawable() {

}

void GlDrawable::Draw() {
    model_->Draw();
}
