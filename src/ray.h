#ifndef RAY_H
#define RAY_H

#include <glm/glm.hpp>

namespace Chotra_RT {

    class Ray {
    public:
        Ray() = default;
        Ray(const glm::vec3 origin, const glm::vec3 direction);

        glm::vec3 GetOrigin() const;
        glm::vec3 GetDirection() const;

        glm::vec3 Func(float t) const;

    private:
        glm::vec3 origin_;
        glm::vec3 direction_;

    };
} // namespace Chotra_RT

#endif
