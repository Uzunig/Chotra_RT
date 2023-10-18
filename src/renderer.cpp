#include "renderer.h"

#include <iostream>

#include "image.h"
#include "image_file.h"
#include "camera.h"
#include "ray.h"
#include "sphere.h"
#include "hittable_list.h"

namespace Chotra_RT {

    Renderer::Renderer() {


    }

    glm::dvec3 Renderer::RayColor(Ray& ray, HittableList& world) const {

        HitData hit_data;
        if (world.Hit(ray, 0, 1000, hit_data)) {
            return 0.5 * (hit_data.normal + glm::dvec3(1, 1, 1));
        }

        return glm::dvec3(0.0);

    }

    void Renderer::Render(ImagePPM& resultImage, const Camera& camera, HittableList& world) {

        std::clog << "\nRendering:\n";

        glm::dvec3 delta_u = glm::dvec3(camera.GetViewportWidth() / resultImage.GetWidth(), 0.0f, 0.0f);
        glm::dvec3 delta_v = glm::dvec3(0.0f, -camera.GetViewportHeight() / resultImage.GetHeight(), 0.0f);

        glm::dvec3 pixel_00_center = glm::dvec3(-camera.GetViewportWidth() / 2, camera.GetViewportHeight() / 2, -camera.GetFocalLength()) + 0.5 * (delta_u + delta_v);





       
        for (int i = 0; i < resultImage.GetHeight(); ++i) {
            std::clog << "\rScanlines remaining: " << (resultImage.GetHeight() - i) << ' ' << std::flush;
            for (int j = 0; j < resultImage.GetWidth(); ++j) {
                Ray ray(camera.GetCameraCenter(), glm::normalize(pixel_00_center + ((double)j * delta_u) + ((double)i * delta_v)));
                glm::dvec3 color = RayColor(ray, world);

                Color256 pixel(color.r * 255, color.g * 255, color.b * 255);
                resultImage.AddPixel(pixel);
            }
        }
    }
} // namespace Chotra_RT
