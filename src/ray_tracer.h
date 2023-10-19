#ifndef RAY_TRACER_H
#define RAY_TRACER_H

#include <glm/glm.hpp>

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
        int samples_per_pixel_ = 10;
        int max_ray_bounces = 10;

        glm::dvec3 RayColor(Ray& ray, int depth, HittableList& world) const;
        glm::dvec3 RandomVecOnHemisphere(const glm::dvec3& normal) const;
        
    };

} //namespace Chotra_RT

#endif
