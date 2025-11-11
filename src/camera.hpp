#pragma once
#include "glw/types.hpp"
#include "glw/math.hpp"

constexpr float CAM_DEFAULT_SPEED       = 0.1f;
constexpr float CAM_DEFAULT_SENSITIVITY = 0.1f;

struct Camera {
public:
    float     speed       = CAM_DEFAULT_SPEED;
    float     sensitivity = CAM_DEFAULT_SENSITIVITY;
    glw::vec3 position    = glm::vec3(0, 0, 0);
    float     pitch       = 0.0f;
    float     yaw         = 0.0f;

    glw::mat4 GetViewMatrix() {
        return glw::LookAt(position, front);
    }
};

