#ifndef PLANE_H
#define PLANE_H

#include <memory>

#include "ray_tracing/hittable.h"

namespace Chotra_RT {

    class Material;

    class Plane : public Hittable {
    public:
        Plane(glm::dvec3 point, glm::dvec3 u, glm::dvec3 v, std::shared_ptr<Material> material);
        bool Hit(const Ray& ray, Interval interval_t, HitData& hit_data) const override;
      

    protected:
        glm::dvec3 point_;
        glm::dvec3 u_;
        glm::dvec3 v_;
        std::shared_ptr<Material> material_;

        glm::dvec3 n_;
        glm::dvec3 normal_;
        double D_;

    };

} // namespace Chotra_RT
#endif
