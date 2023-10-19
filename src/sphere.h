#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"

namespace Chotra_RT {

    class Sphere : public Hittable {
    public:
        Sphere(glm::dvec3 center, float radius);
        bool Hit(const Ray& ray, Interval interval_t, HitData& hit_data) const override;
      

    private:
        glm::dvec3 center_;
        double radius_;

    };

} // namespace Chotra_RT
#endif
