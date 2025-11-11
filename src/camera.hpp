#pragma once
#include "glw/types.hpp"
#include "glw/math.hpp"

constexpr float CAM_DEFAULT_SPEED       = 0.1f;
constexpr float CAM_DEFAULT_SENSITIVITY = 0.1f;

struct Camera {
public:
    float     speed       = CAM_DEFAULT_SPEED;
    float     sensitivity = CAM_DEFAULT_SENSITIVITY;
    glw::vec3 position    = glw::vec3(0);
    float     pitch       = 0.0f; // DEGREES
    float     yaw         = 0.0f; // DEGREES
    glw::vec3 front       = glw::vec3(0);
    glw::vec3 right       = glw::vec3(0);

    void ProcessMouse(const glw::vec2& mouse_delta) {
        yaw += mouse_delta.x * sensitivity;
        pitch -= mouse_delta.y * sensitivity;
        pitch = glw::Clamp(pitch, -89.0f, 89.0f);
        UpdateCameraVectors();
    }
    glw::mat4 GetViewMatrix() {
        return glw::LookAt(position, front);
    }
    void UpdateCameraVectors() {
        front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
        front.y = sin(glm::radians(pitch));
        front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
        front = glm::normalize(front);
        right = glm::normalize(glm::cross(front, glw::vec3(0, 1, 0)));
    }
};

