#include "render/opengl/gl_model_store.h"

GlModelStore::GlModelStore() {

}

GlModelStore::~GlModelStore() {

}

bool GlModelStore::LoadAssets() {
    // Hard coded cube
    library_.insert(std::pair<std::string, GlModel*>("cube", new GlModel()));

    return true;
)

GlModel* GlModelStore::Search(std::string model_name) {
    return model_store_.at(name)
}

void GlModelStore::FetchBufferNames() {
    GLuint* names;

    // I've just picked 20 arbitrarily, maybe I should do this differently.
    glGenBuffers(20, names);

    for (GLuint name : names) {
        buffer_names_.push(name);
    }

    free(names);
}
