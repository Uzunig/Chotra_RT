#ifndef DIFFUSE_LIGHT_H
#define DIFFUSE_LIGHT_H

#include <glm/glm.hpp>
#include <glm/gtc/random.hpp>

#include "material.h"

namespace Chotra_RT {
 
    class Material;
    class Ray;
    class HitData;

    class DiffuseLight : public Material {
    public:
        DiffuseLight(const glm::dvec3& light_color);

        bool Scatter(const Ray& r_in, const HitData& hit_data, glm::dvec3& attenuation, Ray& scattered) const override;

        glm::dvec3 Emitted() const override; 
      
    private:
        glm::dvec3 light_color_;

    };

} //namespace Chatra_RT
#endif

