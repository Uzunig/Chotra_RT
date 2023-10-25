#include "metal.h"

#include "hittable.h"

namespace Chotra_RT {

    bool Metal::Scatter(const Ray& ray_in, const HitData& hit_data, glm::dvec3& attenuation, Ray& scattered) const {

        glm::dvec3 reflection_direction = glm::reflect(ray_in.GetDirection(), hit_data.normal);
        
        scattered = Ray(hit_data.p, reflection_direction);
        attenuation = albedo_;
        return true;
    }


} //namespace Chatra_RT