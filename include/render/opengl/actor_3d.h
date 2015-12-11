#pragma once

#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "render/actor.h"

class Actor3D : Actor {
protected:
    glm::vec3 position_;
    // glm::mat4 model_matrix_;

    std::vector<Component*> components_;

public:
    Actor3D();
    ~Actor3D();
    void Initialize(std::string);
    void AddComponent(Component*);
    void Update(float32);
};
