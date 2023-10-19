#include "renderer.h"

#include "ray_tracer.h"

namespace Chotra_RT {

    Renderer::Renderer() {


    }

    void Renderer::Render(ImagePPM& resultImage, const Camera& camera, HittableList& world) {

        RayTracer ray_tracer;
        ray_tracer.RayTracing(resultImage, camera, world);
    }
} // namespace Chotra_RT
