#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>



namespace Chotra_RT {

    class ImagePPM;

    class Camera {
    public:
        Camera();
        float GetViewportWidth() const;
        float GetViewportHeight() const;
        float GetFocalLength() const;

        glm::vec3 GetCameraCenter() const;

    private:

        float focal_length_ = 1.0f;
        float viewport_height_ = 2.0f;
        float viewport_width_ = 2.0f;
        
        glm::vec3 camera_center_ = glm::vec3(0.0f, 0.0f, 0.0f);

        glm::vec3 front_ = glm::vec3(0.0f, 0.0f, -1.0f);
        glm::vec3 up_ = glm::vec3(0.0f, 1.0f, 0.0f);
        glm::vec3 right_ = glm::vec3(1.0f, 0.0f, 0.0f);

    };

} // namespace Chotra_RT
#endif;

