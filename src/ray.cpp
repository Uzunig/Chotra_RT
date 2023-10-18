#include "ray.h"

namespace Chotra_RT {

    Ray::Ray(const glm::dvec3 origin, const glm::dvec3 direction) 
            : origin_(origin), direction_(direction) {

    }

    glm::dvec3 Ray::GetOrigin() const {
        return origin_;
    }

    glm::dvec3 Ray::GetDirection() const {
        return direction_;
    }

    glm::dvec3 Ray::Func(double t) const {
        return origin_ + t * direction_;
    }

}