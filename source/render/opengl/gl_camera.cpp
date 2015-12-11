#include "util/definitions.h"
#include "render/opengl/gl_camera.h"

#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>


GlCamera::GlCamera() {
    input_device_ = nullptr;
}

GlCamera::~GlCamera() {}

bool GlCamera::Initialize(InputDevice* input_device) {
    input_device_ = input_device;
    velocity_ = 1;
    up_vector_ = glm::vec3(0.0, 1.0, 0.0);
    position_ = glm::vec3(4, 3, -3);

    return true;
}

void GlCamera::Update(float32 delta_time) {
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

    position_.x += x_movement;
    position_.z += z_movement;

    std::cout << position_.x << " " << position_.z << std::endl;

    projection_ = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.f);
    glm::mat4 view_ = glm::lookAt(
        position_,
        glm::vec3(0.0, 0.0, 0.0),
        up_vector_
    );
    vp_matrix_ = projection_ * view_;
}

// void GlCamera::set_position() {
//
// }

glm::mat4 GlCamera::vp_matrix() {
    return vp_matrix_;
}
