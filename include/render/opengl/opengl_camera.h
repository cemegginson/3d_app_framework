#pragma once

#include "definitions.h"

#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

Class OpenGlCamera {
protected:
    InputDevice* input_device_;
    uint32 velocity_;

    glm::mat4 projection_;
    glm::mat4 view_;
    

public:
    OpenGlCamera();
    ~OpenGlCamera();

    bool Initialize(InputDevice*, float32, float32);
    void Update(float32);
    void SetPosition();
}
