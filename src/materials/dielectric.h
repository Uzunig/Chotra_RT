#ifndef DIELECTRIC_H
#define DIELECTRIC_H

#include <glm/glm.hpp>
#include <glm/gtc/random.hpp>

#include "material.h"

namespace Chotra_RT {
 
    class Material;
    class Ray;
    class HitData;

    class Dielectric : public Material {
    public:
        Dielectric(double refraction_index);

        bool Scatter(const Ray& r_in, const HitData& hit_data, glm::dvec3& attenuation, Ray& scattered) const override;
      
    private:
        glm::dvec3 albedo_;
        double refraction_index_;

        static double Reflectance(double cosine, double ref_idx);

    };

} //namespace Chatra_RT
#endif

