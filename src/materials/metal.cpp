#include "metal.h"

#include "ray_tracing/hittable.h"

namespace Chotra_RT {

    Metal::Metal(const glm::dvec3& albedo, double fuzz) 
        : albedo_(albedo), fuzz_(fuzz < 1 ? fuzz : 1) {
    }

    bool Metal::Scatter(const Ray& ray_in, const HitData& hit_data, glm::dvec3& attenuation, Ray& scattered) const {

        glm::dvec3 reflection_direction = glm::normalize(glm::reflect(ray_in.GetDirection(), hit_data.normal) + fuzz_ * glm::normalize(glm::ballRand(1.0)));
        
        scattered = Ray(hit_data.p, reflection_direction);
        attenuation = albedo_;
        return true;
    }


} //namespace Chatra_RT