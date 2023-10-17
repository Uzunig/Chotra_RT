#include "camera.h"

#include "image.h"

namespace Chotra_RT {

    Camera::Camera() {
                

    }

    float Camera::GetViewportWidth() const {
        return viewport_width_;
    }

    float Camera::GetViewportHeight() const {
        return viewport_height_;
    }

    float Camera::GetFocalLength() const {
        return focal_length_;
    }

    glm::vec3 Camera::GetCameraCenter() const {
        return camera_center_;
    }
}