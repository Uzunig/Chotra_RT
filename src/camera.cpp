#include "camera.h"

#include "image.h"
#include "renderer.h"

namespace Chotra_RT {

    Camera::Camera(ImagePPM& image) 
            : image_(image) {

        delta_u_ = glm::vec3(viewport_width_ / image.GetWidth(), 0.0f, 0.0f);
        delta_v_ = glm::vec3(0.0f, -viewport_height_ / image.GetHeight(), 0.0f);

    }

    void Camera::Take(Renderer renderer) {
        renderer.Render(image_);
    }

}