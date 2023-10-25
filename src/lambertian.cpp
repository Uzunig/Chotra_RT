#include "lambertian.h"

#include "hittable.h"

namespace Chotra_RT {

    Lambertian::Lambertian(const glm::dvec3& albedo)
        : albedo_(albedo) {
    
    }

    bool Lambertian::Scatter(const Ray& ray_in, const HitData& hit_data, glm::dvec3& attenuation, Ray& scattered) const {

        glm::dvec3 scatter_direction = glm::normalize(hit_data.normal + glm::normalize(glm::ballRand(1.0)));

        if (glm::length(scatter_direction) * glm::length(scatter_direction) < std::numeric_limits<double>::epsilon() * std::numeric_limits<double>::epsilon()) {
            scatter_direction = hit_data.normal;
        }

        scattered = Ray(hit_data.p, scatter_direction);
        attenuation = albedo_;
        return true;
    }


} //namespace Chatra_RT