#include "sphere.h"

#include "interval.h"
#include "material.h"

namespace Chotra_RT {

    Sphere::Sphere(glm::dvec3 center, float radius, std::shared_ptr<Material> material)
        : center_(center), radius_(radius), material_(material) {

    }

    bool Sphere::Hit(const Ray& ray, Interval interval_t, HitData& hit_data) const {

        glm::dvec3 oc = ray.GetOrigin() - center_;
        double a = dot(ray.GetDirection(), ray.GetDirection());
        double b = 2.0 * dot(oc, ray.GetDirection());
        double c = dot(oc, oc) - radius_ * radius_;
        double discriminant = b * b - 4 * a * c;

        if (discriminant < 0) {
            return false;
        }

        double root = (-b - sqrt(discriminant)) / (2.0 * a);
        if (!interval_t.Surrounds(root)) {
            root = (-b + sqrt(discriminant)) / (2.0 * a);
            if (!interval_t.Surrounds(root)) {
                return false;
            }
        }

        hit_data.t = root;
        hit_data.p = ray.Func(hit_data.t);
        glm::dvec3 outward_normal = glm::normalize(hit_data.p - center_);
        hit_data.SetFaceNormal(ray, outward_normal);
        hit_data.material = material_;

        return true;
    }

} // namespace Chotra_RT