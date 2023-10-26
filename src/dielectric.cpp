#include "dielectric.h"

#include "hittable.h"

namespace Chotra_RT {

    Dielectric::Dielectric(double refraction_index) 
        : refraction_index_(refraction_index) {
    
    }

    bool Dielectric::Scatter(const Ray& ray_in, const HitData& hit_data, glm::dvec3& attenuation, Ray& scattered) const {
                
        double refraction_ratio = hit_data.front_face ? (1.0 / refraction_index_) : refraction_index_;
        
        double cos_theta = fmin(dot(-ray_in.GetDirection(), hit_data.normal), 1.0);
        double sin_theta = sqrt(1.0 - cos_theta * cos_theta);

        bool cannot_refract = refraction_ratio * sin_theta > 1.0;
        glm::dvec3 direction;

        if (cannot_refract || (Reflectance(cos_theta, refraction_ratio) > (rand() / (RAND_MAX + 1.0)))) {

            direction = glm::normalize(glm::reflect(ray_in.GetDirection(), hit_data.normal));

        } else {
            direction = glm::normalize(glm::refract(ray_in.GetDirection(), hit_data.normal, refraction_ratio));
        }

        scattered = Ray(hit_data.p, direction);
        attenuation = glm::dvec3(1.0, 0.7, 0.9);
        return true;
    }

    double Dielectric::Reflectance(double cosine, double ref_idx) {
        // Use Schlick's approximation for reflectance.
        auto r0 = (1 - ref_idx) / (1 + ref_idx);
        r0 = r0 * r0;
        return r0 + (1 - r0) * pow((1 - cosine), 5);
    }


} //namespace Chatra_RT