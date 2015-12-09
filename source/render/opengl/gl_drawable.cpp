#include "render/opengl/gl_drawable.h"

GlDrawable::GlDrawable(GlModel* model) {
    model_ = model;
}

GlDrawable::~GlDrawable() {

}

GlDrawable::Draw() {
    model_->Draw();
}
