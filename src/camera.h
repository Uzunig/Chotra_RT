#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>

namespace Chotra_RT {

    class Camera {
    public:
        Camera();
        
    private:
        float focalLength_ = 1.0f;
        float viewportHeight = 2.0f;
        float viewportWidth = 2.0f;
        
        glm::vec3 position_ = glm::vec3(0.0f, 0.0f, 0.0f);

        glm::vec3 front_ = glm::vec3(0.0f, 0.0f, -1.0f);
        glm::vec3 up_ = glm::vec3(0.0f, 1.0f, 0.0f);
        glm::vec3 right_ = glm::vec3(1.0f, 0.0f, 0.0f);

    };

} // namespace Chotra_RT
#endif;

