#include "quad.h"

#include <cmath>

#include "utils/interval.h"
#include "materials/material.h"

namespace Chotra_RT {

    Quad::Quad(glm::dvec3 point, glm::dvec3 u, glm::dvec3 v, std::shared_ptr<Material> material)
        : Plane(point, u, v, material) {

        w_ = n_ / dot(n_, n_);
    }

    bool Quad::Hit(const Ray& ray, Interval interval_t, HitData& hit_data) const {

        auto denom = glm::dot(normal_, ray.GetDirection());

        // No hit if the ray is parallel to the plane.
        if (fabs(denom) < 1e-8)
            return false;

        // Return false if the hit point parameter t is outside the ray interval.
        auto t = (D_ - glm::dot(normal_, ray.GetOrigin())) / denom;
        if (!interval_t.Contains(t))
            return false;

        // Determine the hit point lies within the planar shape using its plane coordinates.
        auto intersection = ray.Func(t);
        glm::dvec3 planar_hitpt_vector = intersection - point_;
        auto alpha = glm::dot(w_, glm::cross(planar_hitpt_vector, v_));
        auto beta = glm::dot(w_, glm::cross(u_, planar_hitpt_vector));

        if (!IsInterior(alpha, beta, hit_data))
            return false;

        // Ray hits the 2D shape; set the rest of the hit record and return true.

        hit_data.t = t;
        hit_data.p = intersection;
        hit_data.SetFaceNormal(ray, normal_);
        hit_data.material = material_;

        return true;
    }

    bool Quad::IsInterior(double a, double b, HitData& hit_data) const {
        // Given the hit point in plane coordinates, return false if it is outside the
        // primitive, otherwise set the hit record UV coordinates and return true.

        if ((a < 0) || (1 < a) || (b < 0) || (1 < b))
            return false;
                
        return true;
    }

} // namespace Chotra_RT