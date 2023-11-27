#include "renderer.h"

#include "ray_tracing/ray_tracer.h"
#include "ray_tracing/camera.h"
#include "ray_tracing/hittable_list.h"

#include "utils/image.h"
#include "utils/image_file.h"

namespace Chotra_RT {

    Renderer::Renderer() {


    }

    void Renderer::Render(ImagePPM& resultImage, const Camera& camera, HittableList& world) {

        RayTracer ray_tracer;
        ray_tracer.RayTracing(resultImage, camera, world);
    }

    void Renderer::RenderToImageFile() {
        ImagePPM image(400, 400);
        Camera camera = Camera();
        HittableList world;

        Render(image, camera, world);
        //renderer_.Render(image, camera, world);
        FilePPM file("image.ppm");
        file.SaveFile(image);
    }
} // namespace Chotra_RT
