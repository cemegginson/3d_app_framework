#pragma once

#include "definitions.h"
#include "render/camera.h"

#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

Class GlCamera : Camera{
protected:
    InputDevice* input_device_;
    uint32 velocity_;

    glm::vec3 up_vector_;
    glm::vec3 position_;

    glm::mat4 projection_;
    glm::mat4 view_;
    glm::mat4 vp_matrix_;

public:
    GlCamera();
    ~GlCamera();

    bool Initialize(InputDevice*);
    void Update(float32);
    // void set_position();
    glm::mat4 vp_matrix();
}
