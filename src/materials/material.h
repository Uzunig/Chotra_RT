#ifndef MATERIAL_H
#define MATERIAL_H

#include <glm/glm.hpp>

namespace Chotra_RT {

    class HitData;
    class Ray;

    class Material {
    public:

        virtual ~Material() = default;

        virtual bool Scatter(const Ray& r_in, const HitData& hit_data, glm::dvec3& attenuation, Ray& scattered) const = 0;

        virtual glm::dvec3 Emitted() const;
                
    };

} //namespace Chatra_RT
#endif

