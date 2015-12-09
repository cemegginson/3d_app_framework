#include "render/opengl/gl_model.h"

GlModel::GlModel() {}

GlModel::~GlModel() {
    glInvalidateBufferData();
}
