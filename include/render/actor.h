#pragma once

#include <list>

#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "util/definitions.h"
#include "virtual/component.h"

class Actor {
protected:
    glm::vec3 position_;
    // glm::mat4 model_matrix_;

    std::list<Component*> components_;

public:
    Actor();
    ~Actor();
    void Initialize(std::string);
    void AddComponent(Component*);
    void Update();

    glm::vec3 position() const;
};
