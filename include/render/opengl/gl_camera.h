#pragma once

#include "util/definitions.h"
#include "render/camera.h"

#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <memory>

class GlCamera : Camera {
protected:
    uint32 velocity_;

    glm::vec3 up_vector_;
    glm::vec3 position_;

    glm::mat4 projection_;
    glm::mat4 view_;
    glm::mat4 vp_matrix_;

    std::map<GameEvent, bool> tracked_keys;

public:
    GlCamera();
    ~GlCamera();

    bool Initialize();
    void OnInput(std::shared_ptr<void>);
    void Update(std::shared_ptr<void>);
    // void set_position();
    glm::mat4 vp_matrix();
};
