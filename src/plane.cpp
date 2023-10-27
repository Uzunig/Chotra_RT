#include "plane.h"

#include "interval.h"
#include "material.h"

namespace Chotra_RT {

    Plane::Plane(glm::dvec3 point, glm::dvec3 u, glm::dvec3 v, std::shared_ptr<Material> material)
        : point_(point), u_(u), v_(v), material_(material) {

        n_ = glm::cross(u_, v_);
        normal_ = glm::normalize(n_);
        D_ = glm::dot(normal_, point_);

    }

    bool Plane::Hit(const Ray& ray, Interval interval_t, HitData& hit_data) const {

        auto denom = glm::dot(normal_, ray.GetDirection());

        // No hit if the ray is parallel to the plane.
        if (fabs(denom) < 1e-8)
            return false;

        // Return false if the hit point parameter t is outside the ray interval.
        auto t = (D_ - glm::dot(normal_, ray.GetOrigin())) / denom;
        if (!interval_t.Contains(t))
            return false;

        auto intersection = ray.Func(t);

        hit_data.t = t;
        hit_data.p = intersection;
        hit_data.SetFaceNormal(ray, normal_);
        hit_data.material = material_;

        return true;
    }

} // namespace Chotra_RT