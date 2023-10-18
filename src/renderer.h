#ifndef RENDERER_H
#define RENDERER_H

#include <glm/glm.hpp>

#include "ray.h"

namespace Chotra_RT {

    class ImagePPM;
    class Camera;
    class HittableList;

    class Renderer {
    public:
        Renderer();
        void Render(ImagePPM& resultImage, const Camera& camera, HittableList& world);

    private:
        glm::dvec3 RayColor(Ray& ray, HittableList& world) const;

    };

} //namespace Chotra_RT

#endif
