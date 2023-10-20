#include "lambertian.h"

#include "hittable.h"

namespace Chotra_RT {

    bool Lambertian::Scatter(const Ray& r_in, const HitData& hit_data, glm::dvec3& attenuation, Ray& scattered) const {
        auto scatter_direction = hit_data.normal + glm::normalize(glm::ballRand(1.0));
        scattered = Ray(hit_data.p, scatter_direction);
        attenuation = albedo_;
        return true;
    }


} //namespace Chatra_RT