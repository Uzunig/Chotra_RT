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
#include "dielectric.h"
#include "diffuse_light.h"
#include "plane.h"
#include "quad.h"


namespace Chotra_RT {

    Application::Application(ApplicationSpecification applicationSpecification)
        : applicationSpecification_(applicationSpecification) {

    }

    Application::~Application() {

    }

    void Application::Run() {

        lastTime_ = GetTime();
        
        ImagePPM image(400, 400); 
        Camera camera = Camera();

        HittableList world;


        // Materials
        std::shared_ptr<Material> black = std::make_shared<Lambertian>(glm::dvec3(0.0, 0.0, 0.0));
        std::shared_ptr<Material> white = std::make_shared<Lambertian>(glm::dvec3(1.0, 1.0, 1.0));
        std::shared_ptr<Material> red     = std::make_shared<Lambertian>(glm::dvec3(1.0, 0.0, 0.0));
        std::shared_ptr<Material> green   = std::make_shared<Lambertian>(glm::dvec3(0.0, 1.0, 0.0));
        std::shared_ptr<Material> blue   = std::make_shared<Lambertian>(glm::dvec3(0.0, 0.0, 1.0));
        std::shared_ptr<Material> gray = std::make_shared<Lambertian>(glm::dvec3(0.7, 0.7, 0.7));
        
        std::shared_ptr<Material> glass = std::make_shared<Dielectric>(1.5);
        std::shared_ptr<Material> bronze = std::make_shared<Metal>(glm::dvec3(0.8, 0.5, 0.2), 0.0);

        std::shared_ptr<Material> material_light = std::make_shared<DiffuseLight>(glm::dvec3(5.0, 5.0, 5.0));
        
        

        // Quads
        world.Add(std::make_shared<Quad>(glm::dvec3(-3, -3, 3), glm::dvec3(0, 0, -6), glm::dvec3(0, 6, 0),  red));
        world.Add(std::make_shared<Quad>(glm::dvec3(-3, -3, -3), glm::dvec3(6, 0, 0),  glm::dvec3(0, 6, 0),  green));
        world.Add(std::make_shared<Quad>(glm::dvec3(3, -3, -3),  glm::dvec3(0, 0, 6),  glm::dvec3(0, 6, 0),  blue));
        world.Add(std::make_shared<Quad>(glm::dvec3(3, 3, -3),  glm::dvec3(0, 0, 6),  glm::dvec3(-6, 0, 0),  white));
        world.Add(std::make_shared<Quad>(glm::dvec3(-3, -3, -3), glm::dvec3(0, 0, 6),  glm::dvec3(6, 0, 0), gray));


        world.Add(std::make_shared<Quad>(glm::dvec3(-3, -3, -2), glm::dvec3(1, 0, 0), glm::dvec3(0, 1, 0), black));
        world.Add(std::make_shared<Quad>(glm::dvec3(-2, -3, -2), glm::dvec3(0, 0, -1), glm::dvec3(0, 1, 0), black));
        world.Add(std::make_shared<Quad>(glm::dvec3(-3, -2, -2), glm::dvec3(1, 0, 0), glm::dvec3(0, 0, -1), black));

        
        // Spheres
        world.Add(std::make_shared<Sphere>(glm::dvec3(-2.2, -2.5, 2.5), 0.5, glass));
        world.Add(std::make_shared<Sphere>(glm::dvec3(2.1, -2.5, 2.0), 0.5, glass));
        world.Add(std::make_shared<Sphere>(glm::dvec3(0.4, -2.5, 1.5), 0.5, bronze));
        world.Add(std::make_shared<Sphere>(glm::dvec3(-1.2, -2.5, 1.5), 0.5, black));
        world.Add(std::make_shared<Sphere>(glm::dvec3(0.0, -2.5, 0.0), 0.5, blue));
        world.Add(std::make_shared<Sphere>(glm::dvec3(1.1, -2.5, 0.0), 0.5, red));
        world.Add(std::make_shared<Sphere>(glm::dvec3(-1.3, -2.5, -1.5), 0.5, bronze));
        world.Add(std::make_shared<Sphere>(glm::dvec3(1.5, -2.5, -2.0), 0.5, glass));
        world.Add(std::make_shared<Sphere>(glm::dvec3(-2.5, -1.5, -2.5), 0.5, white));

        // Lights
        //world.Add(std::make_shared<Sphere>(glm::dvec3(0.0, 3.0, 0.0), 1.0, material_light));
        world.Add(std::make_shared<Quad>(glm::dvec3(-1, -3, -3), glm::dvec3(2, 0, 0), glm::dvec3(0, 5, 0), material_light));
        

        // Rendering
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