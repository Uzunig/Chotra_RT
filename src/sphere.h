#ifndef SPHERE_H
#define SPHERE_H

#include <memory>

#include "hittable.h"

namespace Chotra_RT {

    class Material;

    class Sphere : public Hittable {
    public:
        Sphere(glm::dvec3 center, float radius, std::shared_ptr<Material> material);
        bool Hit(const Ray& ray, Interval interval_t, HitData& hit_data) const override;
      

    private:
        glm::dvec3 center_;
        double radius_;
        std::shared_ptr<Material> material_;

    };

} // namespace Chotra_RT
#endif
