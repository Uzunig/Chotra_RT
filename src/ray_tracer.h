#ifndef RAY_TRACER_H
#define RAY_TRACER_H

#include <glm/glm.hpp>
#include <glm/gtc/random.hpp>

#include "ray.h"

namespace Chotra_RT {

    class ImagePPM;
    class Camera;
    class HittableList;

    class RayTracer {
    public:
        RayTracer();
        void RayTracing(ImagePPM& resultImage, const Camera& camera, HittableList& world);
        

    private:
        int samples_per_pixel_ = 1000;
        int max_ray_bounces = 1000;

        glm::dvec3 RayColor(Ray& ray, int depth, HittableList& world) const;
        glm::dvec3 RandomVec() const;
        glm::dvec3 RandomVecOnHemisphere(const glm::dvec3& normal) const;

        glm::dvec3 ToneMapping(glm::dvec3& hdr_color);
        glm::dvec3 GammaCorrection(glm::dvec3& linear_color);

        
    };

} //namespace Chotra_RT

#endif
