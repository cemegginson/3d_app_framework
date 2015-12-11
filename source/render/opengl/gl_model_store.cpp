#include <string>
#include <utility>

#include "render/opengl/gl_model_store.h"

GlModelStore::GlModelStore() {
    // FetchBufferNames();
}

GlModelStore::~GlModelStore() {

}

bool GlModelStore::LoadAssets() {
    // Hard coded cube
    model_store_.insert(std::pair<std::string, GlModel*>("cube", new GlModel()));
    model_store_.at("cube")->Initialize();
    return true;
}

GlModel* GlModelStore::Search(std::string model_name) {
    return model_store_.at(model_name);
}

// void GlModelStore::FetchBufferNames() {
//     GLuint* names;
//
//     // I've just picked 20 arbitrarily, maybe I should do this differently.
//     glGenBuffers(20, names);
//
//     for (GLuint name : names) {
//         buffer_names_.push(name);
//     }
//
//     free(names);
// }
