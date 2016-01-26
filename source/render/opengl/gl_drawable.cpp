#include "render/opengl/gl_drawable.h"

GlDrawable::GlDrawable(Actor* owner) {
    owner_ = owner;
}

GlDrawable::~GlDrawable() {
    owner_ = nullptr;
}

void GlDrawable::Initialize(OpenGLRenderer* renderer, GlModel* model) {
    renderer->AddModel(this);
    model_ = model;
}

void GlDrawable::Update() {
    model_matrix_ = glm::translate(glm::mat4(1.0f), owner_->position());
}

void GlDrawable::Draw(glm::mat4 view_projection) {
    glm::mat4 model_view_projection = view_projection * model_matrix_;
    model_->Draw(model_view_projection);
}
