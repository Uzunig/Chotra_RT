#ifndef RAY_H
#define RAY_H

#include <glm/glm.hpp>

namespace Chotra_RT {

    class Ray {
    public:
        Ray() = default;
        Ray(const glm::dvec3 origin, const glm::dvec3 direction);

        glm::dvec3 GetOrigin() const;
        glm::dvec3 GetDirection() const;

        glm::dvec3 Func(double t) const;

    private:
        glm::dvec3 origin_;
        glm::dvec3 direction_;

    };
} // namespace Chotra_RT

#endif
