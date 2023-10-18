#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"

namespace Chotra_RT {

    class HitData {
    public:
        glm::dvec3 p;
        glm::dvec3 normal;
        double t;
        bool front_face;

        void SetFaceNormal(const Ray& ray, const glm::dvec3& outward_normal);
    };

    class Hittable {
    public:
        virtual ~Hittable() = default;

        virtual bool Hit(const Ray& ray, double ray_tmin, double ray_tmax, HitData& rec) const = 0;

    };

} //namespace Chatra_RT

#endif 

