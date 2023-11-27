#ifndef METAL_H
#define METAL_H

#include <glm/glm.hpp>
#include <glm/gtc/random.hpp>

#include "material.h"

namespace Chotra_RT {
 
    class Material;
    class Ray;
    class HitData;

    class Metal : public Material {
    public:
        Metal(const glm::dvec3& albedo, double fuzz);

        bool Scatter(const Ray& r_in, const HitData& hit_data, glm::dvec3& attenuation, Ray& scattered) const override;
      
    private:
        glm::dvec3 albedo_;
        double fuzz_;

    };

} //namespace Chatra_RT
#endif

