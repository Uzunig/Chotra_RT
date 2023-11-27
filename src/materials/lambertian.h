#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H

#include <glm/glm.hpp>
#include <glm/gtc/random.hpp>

#include "material.h"

namespace Chotra_RT {
 
    class Material;
    class Ray;
    class HitData;

    class Lambertian : public Material {
    public:
        Lambertian(const glm::dvec3& albedo);

        bool Scatter(const Ray& r_in, const HitData& hit_data, glm::dvec3& attenuation, Ray& scattered) const override;
      
    private:
        glm::dvec3 albedo_;

    };

} //namespace Chatra_RT
#endif

