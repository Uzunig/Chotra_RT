#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>



namespace Chotra_RT {

    class ImagePPM;

    class Camera {
    public:
        Camera();
        double GetViewportWidth() const;
        double GetViewportHeight() const;
        double GetFocalLength() const;

        glm::dvec3 GetCameraCenter() const;

    private:

        double focal_length_ = 4.0f;
        double viewport_height_ = 2.0f;
        double viewport_width_ = 2.0f;
        
        glm::dvec3 camera_center_ = glm::dvec3(0.0f, 0.0f, 4.0f);

        glm::dvec3 front_ = glm::dvec3(0.0f, 0.0f, -1.0f);
        glm::dvec3 up_ = glm::dvec3(0.0f, 1.0f, 0.0f);
        glm::dvec3 right_ = glm::dvec3(1.0f, 0.0f, 0.0f);

    };

} // namespace Chotra_RT
#endif;

