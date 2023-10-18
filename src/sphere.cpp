#include "sphere.h"

namespace Chotra_RT {

    Sphere::Sphere(glm::dvec3 center, float radius)
        : center_(center), radius_(radius) {

    }

    bool Sphere::Hit(const Ray& ray, double ray_tmin, double ray_tmax, HitData& hit_data) const {

        glm::dvec3 oc = ray.GetOrigin() - center_;
        double a = dot(ray.GetDirection(), ray.GetDirection());
        double b = 2.0 * dot(oc, ray.GetDirection());
        double c = dot(oc, oc) - radius_ * radius_;
        double discriminant = b * b - 4 * a * c;

        if (discriminant < 0) {
            return false;
        }

        double root = (-b - sqrt(discriminant)) / (2.0 * a);
        if (root <= ray_tmin || ray_tmax <= root) {
            root = (-b + sqrt(discriminant)) / (2.0 * a);
            if (root <= ray_tmin || ray_tmax <= root) {
                return false;
            }
        }

        hit_data.t = root;
        hit_data.p = ray.Func(hit_data.t);
        glm::dvec3 outward_normal = glm::normalize(hit_data.p - center_);
        hit_data.SetFaceNormal(ray, outward_normal);

        return true;
    }

} // namespace Chotra_RT