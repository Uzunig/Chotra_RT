#include "ray_tracer.h"

#include <iostream>
#include <cstdlib>

#include "image.h"
#include "image_file.h"
#include "camera.h"
#include "ray.h"
#include "sphere.h"
#include "hittable_list.h"
#include "interval.h"
#include "material.h"

namespace Chotra_RT {

    double RandomDouble() {
        return rand() / (RAND_MAX + 1.0);
    }

    double RandomSignedDouble() {
        return -1.0 + 2.0 * rand() / (RAND_MAX + 1.0);
    }

    RayTracer::RayTracer() {


    }

    glm::dvec3 RayTracer::GammaCorrection(glm::dvec3& linear_color) {
        return sqrt(linear_color);
    }

    glm::dvec3 RayTracer::RandomVec() const {
        glm::dvec3 random_vec = normalize(glm::dvec3(RandomSignedDouble(), RandomSignedDouble(), RandomSignedDouble()));
        return random_vec;
    }

    glm::dvec3 RayTracer::RandomVecOnHemisphere(const glm::dvec3& normal) const {
        glm::dvec3 random_vec = normalize(glm::dvec3(RandomSignedDouble(), RandomSignedDouble(), RandomSignedDouble()));
        if (dot(random_vec, normal) > 0.0) // In the same hemisphere as the normal
            return random_vec;
        else
            return -random_vec;
    }

    glm::dvec3 RayTracer::RayColor(Ray& ray, int depth, HittableList& world) const {

        if (depth <= 0) {
            return glm::dvec3(0.0, 0.0, 0.0);
        }

        HitData hit_data;
        if (world.Hit(ray, Interval(0.001, infinity), hit_data)) {
            Ray scattered;
            glm::dvec3 attenuation;
            if (hit_data.material->Scatter(ray, hit_data, attenuation, scattered)) {
                return attenuation * RayColor(scattered, depth - 1, world);
            }
            return glm::dvec3(0.0, 0.0, 0.0);
        }
        return glm::dvec3(0.5, 0.7, 1.0);
    }

    void RayTracer::RayTracing(ImagePPM& resultImage, const Camera& camera, HittableList& world) {

        std::clog << "\nRendering:\n";

        glm::dvec3 delta_u = glm::dvec3(camera.GetViewportWidth() / resultImage.GetWidth(), 0.0f, 0.0f);
        glm::dvec3 delta_v = glm::dvec3(0.0f, -camera.GetViewportHeight() / resultImage.GetHeight(), 0.0f);

        glm::dvec3 pixel_00_center = glm::dvec3(-camera.GetViewportWidth() / 2, camera.GetViewportHeight() / 2, -camera.GetFocalLength()) + 0.5 * (delta_u + delta_v);

        for (int i = 0; i < resultImage.GetHeight(); ++i) {
            std::clog << "\rScanlines remaining: " << (resultImage.GetHeight() - i) << ' ' << std::flush;
            for (int j = 0; j < resultImage.GetWidth(); ++j) {
                glm::dvec3 color(0.0);
                for (int sample = 0; sample < samples_per_pixel_; ++sample) {
                    glm::dvec3 sample_delta_u = (-0.5 + RandomDouble()) * delta_u;
                    glm::dvec3 sample_delta_v = (-0.5 + RandomDouble()) * delta_v;

                    Ray ray(camera.GetCameraCenter(), glm::normalize(pixel_00_center + ((double)j * delta_u) + ((double)i * delta_v) + sample_delta_u + sample_delta_v));
                    color += RayColor(ray, max_ray_bounces, world);
                }
                color = color / static_cast<double>(samples_per_pixel_);
                color = GammaCorrection(color);
                Color256 pixel(color.r * 255, color.g * 255, color.b * 255);
                resultImage.AddPixel(pixel);
            }
        }
    }
} // namespace Chotra_RT
