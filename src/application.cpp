#include "application.h"

#include <iostream>
#include <chrono>
#include <memory>
#include <glm/glm.hpp>

#include "resource_manager.h"
#include "image_file.h"
#include "image.h"
#include "camera.h"
#include "hittable_list.h"
#include "sphere.h"
#include "lambertian.h"
#include "metal.h"


namespace Chotra_RT {

    Application::Application(ApplicationSpecification applicationSpecification)
        : applicationSpecification_(applicationSpecification) {

    }

    Application::~Application() {

    }

    void Application::Run() {

        lastTime_ = GetTime();
        
        ImagePPM image(400, 400); //
        Camera camera = Camera();

        HittableList world;
        std::shared_ptr<Material> material_ground = std::make_shared<Lambertian>(glm::dvec3(0.8, 0.8, 0.0));
        std::shared_ptr<Material> material_center = std::make_shared<Lambertian>(glm::dvec3(0.7, 0.3, 0.3));
        std::shared_ptr<Material> material_left = std::make_shared<Metal>(glm::dvec3(0.8, 0.8, 0.8));
        std::shared_ptr<Material> material_right = std::make_shared<Metal>(glm::dvec3(0.8, 0.6, 0.2));

        world.Add(std::make_shared<Sphere>(glm::dvec3(0.0, -100.5, -1.0), 100.0, material_ground));
        world.Add(std::make_shared<Sphere>(glm::dvec3(0.0, 0.0, -1.0), 0.5, material_center));
        world.Add(std::make_shared<Sphere>(glm::dvec3(-1.0, 0.0, -1.0), 0.5, material_left));
        world.Add(std::make_shared<Sphere>(glm::dvec3(1.0, 0.0, -1.0), 0.5, material_right));

        renderer_.Render(image, camera, world);
       

        float currentTime = GetTime();
        float deltaTime = currentTime - lastTime_;
        lastTime_ = currentTime;
        std::clog << "\nTime spent on rendering: " << deltaTime << '\n' << std::flush;

        const char* filename = "image.ppm";
        FilePPM file(filename);
        file.SaveFile(image);

        currentTime = GetTime();
        deltaTime = currentTime - lastTime_;
        lastTime_ = currentTime;
        std::clog << "\nTime spent on saving: " << deltaTime << '\n' << std::flush;
               
        while (running_) {
            currentTime = GetTime();
            deltaTime = currentTime - lastTime_;
            lastTime_ = currentTime;

            //OnUpdate();
        }
    }

    void Application::OnUpdate() {

        running_ = false;
    }

    float Application::GetTime() {
        return (float)glfwGetTime();
    }

} // namespace Chotra_RT