#include "ray.h"

namespace Chotra_RT {

    Ray::Ray(const glm::vec3 origin, const glm::vec3 direction) 
            : origin_(origin), direction_(direction) {

    }

    glm::vec3 Ray::GetOrigin() const {
        return origin_;
    }

    glm::vec3 Ray::GetDirection() const {
        return direction_;
    }

    glm::vec3 Ray::Func(float t) const {
        return origin_ + t * direction_;
    }

}