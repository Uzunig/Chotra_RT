#include "camera.h"

#include "utils/image.h"

namespace Chotra_RT {

    Camera::Camera() {
                

    }

    double Camera::GetViewportWidth() const {
        return viewport_width_;
    }

    double Camera::GetViewportHeight() const {
        return viewport_height_;
    }

    double Camera::GetFocalLength() const {
        return focal_length_;
    }

    glm::dvec3 Camera::GetCameraCenter() const {
        return camera_center_;
    }
}