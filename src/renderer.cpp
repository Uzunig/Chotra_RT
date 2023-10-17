#include "renderer.h"

#include <iostream>

#include "image.h"
#include "image_file.h"
#include "camera.h"
#include "ray.h"

namespace Chotra_RT {

    Renderer::Renderer() {

    }

    float HitSphere(const glm::vec3& center, float radius, const Ray& r) {
        glm::vec3 oc = r.GetOrigin() - center;
        auto a = dot(r.GetDirection(), r.GetDirection());
        auto b = 2.0 * dot(oc, r.GetDirection());
        auto c = dot(oc, oc) - radius * radius;
        auto discriminant = b * b - 4 * a * c;

        if (discriminant < 0) {
            return -1.0;
        }
        else {
            return (-b - sqrt(discriminant)) / (2.0 * a);
        }
    }

    void Renderer::Render(ImagePPM& resultImage, const Camera& camera) {

        std::clog << "\nRendering:\n";

        glm::vec3 delta_u = glm::vec3(camera.GetViewportWidth() / resultImage.GetWidth(), 0.0f, 0.0f);
        glm::vec3 delta_v = glm::vec3(0.0f, -camera.GetViewportHeight() / resultImage.GetHeight(), 0.0f);

        glm::vec3 pixel_00_center = glm::vec3(-camera.GetViewportWidth() / 2, camera.GetViewportHeight() / 2, -camera.GetFocalLength()) + 0.5f * delta_u + 0.5f * delta_v;

        for (int i = 0; i < resultImage.GetHeight(); ++i) {
            std::clog << "\rScanlines remaining: " << (resultImage.GetHeight() - i) << ' ' << std::flush;
            for (int j = 0; j < resultImage.GetWidth(); ++j) {
                Ray r(camera.GetCameraCenter(), glm::normalize(pixel_00_center + ((float)j * delta_u) + ((float)i * delta_v)));

                glm::vec3 normal = glm::vec3(0.0f);

                float t = HitSphere(glm::vec3(0, 0, -2), 1.0, r);
                if (t > 0) {
                    normal = glm::normalize(r.Func(t) - glm::vec3(0, 0, -2));
                }
                Color256 pixel(0.5 * (normal.r + 1) * 255, 0.5 * (normal.g + 1) * 255, 0.5 * (normal.b +1) * 255);
                resultImage.AddPixel(pixel);
            }
        }


        /*
        for (int i = 0; i < resultImage.GetHeight(); ++i) {
            std::clog << "\rScanlines remaining: " << (resultImage.GetHeight() - i) << ' ' << std::flush;
            for (int j = 0; j < resultImage.GetWidth(); ++j) {
                Color256 pixel(i, j, 0);
                resultImage.AddPixel(pixel);
            }
        }
        */
    }

} // namespace Chotra_RT
