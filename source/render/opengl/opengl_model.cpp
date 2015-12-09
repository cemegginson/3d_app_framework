#include "render/opengl/opengl_model.h"

OpenGlModel::OpenGlModel() {}

OpenGlModel::~OpenGlModel() {
    glInvalidateBufferData();
}
