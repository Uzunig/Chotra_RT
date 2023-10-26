#include "diffuse_light.h"

#include "hittable.h"

namespace Chotra_RT {

    DiffuseLight::DiffuseLight(const glm::dvec3& light_color) 
        : light_color_(light_color) {
    }

    bool DiffuseLight::Scatter(const Ray& ray_in, const HitData& hit_data, glm::dvec3& attenuation, Ray& scattered) const {
                
        return false;
    }

    glm::dvec3 DiffuseLight::Emitted() const {
        return light_color_;
    }



} //namespace Chatra_RT