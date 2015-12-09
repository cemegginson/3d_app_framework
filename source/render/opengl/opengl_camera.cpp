#include "definitions.h"
#include "render/opengl/opengl_camera.h"

#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


OpenGlCamera::OpenGlCamera() {
    input_device = nullptr;
}

OpenGlCamera::~OpenGlCamera() {}

bool OpenGlCamera::Initialize(InputDevice* input_device, float32, float32) {
    input_device_ = input_device;
    velocity_ = 1;
    up_vector_ = glm::vec3(0, 1, 0);
    position_ = glm::vec3(0, 0, 0);
}

void OpenGlCamera::Update(float32 delta_time) {
    float32 z_movement = 0;
    float32 x_movement = 0;

    if (input_device_->IsPressed(kGameUp)) {
        z_movement += velocity_ * delta_time;
    }
    if (input_device_->IsPressed(kGameDown)) {
        z_movement -= velocity_ * delta_time;
    }
    if (input_device_->IsPressed(kGameLeft)) {
        x_movement += velocity_ * delta_time;
    }
    if (input_device_->IsPressed(kGameRight)) {
        x_movement -= velocity_ * delta_time;
    }
    return;

    projection_ = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.f);
    glm::mat4 view_translate = glm::translate(glm::mat4(1), position_);
    vp_matrix_ = projection_ * view_;
}

// void OpenGlCamera::set_position() {
//
// }

glm::mat4 OpenGlCamera::vp_matrix() {
    return vp_matrix_;
}
