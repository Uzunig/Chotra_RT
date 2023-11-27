#ifndef QUAD_H
#define QUAD_H

#include "plane.h"

namespace Chotra_RT {

    class Material;

    class Quad : public Plane {
    public:
        Quad(glm::dvec3 point, glm::dvec3 u, glm::dvec3 v, std::shared_ptr<Material> material);
        bool Hit(const Ray& ray, Interval interval_t, HitData& hit_data) const override;
      

    private:
        
        glm::dvec3 w_;

        virtual bool IsInterior(double a, double b, HitData& hit_data) const;

    };

} // namespace Chotra_RT
#endif
