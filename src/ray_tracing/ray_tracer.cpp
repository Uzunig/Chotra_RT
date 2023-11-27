#include "ray_tracer.h"

#include <iostream>
#include <cstdlib>
#include <thread>
#include <mutex>



#include "utils/image.h"
#include "utils/image_file.h"
#include "ray_tracing/camera.h"
#include "ray_tracing/ray.h"
#include "resource_manager/sphere.h"
#include "ray_tracing/hittable_list.h"
#include "utils/interval.h"
#include "materials/material.h"

namespace Chotra_RT {

    double RandomDouble() {
        return rand() / (RAND_MAX + 1.0);
    }

    double RandomSignedDouble() {
        return -1.0 + 2.0 * rand() / (RAND_MAX + 1.0);
    }

    RayTracer::RayTracer() {


    }

    glm::dvec3 RayTracer::ToneMapping(glm::dvec3& hdr_color) {

        return hdr_color / (hdr_color + glm::dvec3(1.0));
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
            return hit_data.material->Emitted();
        }
        return glm::dvec3(0.0, 0.0, 0.0); // 0.5, 0.7, 1.0
    }

    void RayTracer::RenderLine(const unsigned int i,ImagePPM& resultImage, const Camera& camera, HittableList& world) {
      
        for (int j = 0; j < resultImage.GetWidth(); ++j) {
            glm::dvec3 color(0.0);
            for (unsigned int sample = 0; sample < samples_per_pixel_; ++sample) {
                glm::dvec3 sample_delta_u = (-0.5 + RandomDouble()) * delta_u_;
                glm::dvec3 sample_delta_v = (-0.5 + RandomDouble()) * delta_v_;

                Ray ray(camera.GetCameraCenter(), glm::normalize(pixel_00_center_ + ((double)j * delta_u_) + ((double)i * delta_v_) + sample_delta_u + sample_delta_v));
                color += RayColor(ray, max_ray_bounces, world);
            }
            color = color / static_cast<double>(samples_per_pixel_);
            color = ToneMapping(color);
            color = GammaCorrection(color);
            Color256 pixel(color.r * 255, color.g * 255, color.b * 255);
            resultImage.SetPixel(i, j, pixel);
        }
    }

    void RayTracer::RayTracing(ImagePPM& resultImage, const Camera& camera, HittableList& world) {

        std::clog << "\nRendering:\n";

        delta_u_ = glm::dvec3(camera.GetViewportWidth() / resultImage.GetWidth(), 0.0f, 0.0f);
        delta_v_ = glm::dvec3(0.0f, -camera.GetViewportHeight() / resultImage.GetHight(), 0.0f);

        pixel_00_center_ = glm::dvec3(-camera.GetViewportWidth() / 2, camera.GetViewportHeight() / 2, -camera.GetFocalLength()) + 0.5 * (delta_u_ + delta_v_);

        std::vector <std::thread> th_vec;
        unsigned int thread_count = 0;

        for (unsigned int i = 0; i < resultImage.GetHight(); ++i) {
            std::clog << "\rScanlines remaining: " << (resultImage.GetHight() - i) << ' ' << std::flush;
            th_vec.push_back(std::thread([&](const int x) {RenderLine(x, resultImage, camera, world); }, i));
            ++thread_count;
            if (thread_count == 100 || i == resultImage.GetHight() - 1) {
                for (unsigned int j = th_vec.size() - thread_count; j < th_vec.size(); ++j) {
                    th_vec[j].join();
                }
                thread_count = 0;
            }
        }
    }
} // namespace Chotra_RT
