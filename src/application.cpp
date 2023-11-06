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

    static bool GLFW_initialized = false;

    Application::Application(ApplicationProperties application_properties)
        : application_properties_(application_properties) {

    }

    Application::~Application() {

    }

    void Application::Run() {
        
        last_time_ = GetTime();

        if (!GLFW_initialized) {
            if (!glfwInit()) {
                std::cout << "Failed to initialize GLFW" << std::endl;
                return;
            }
        }
        MainLoop();
    }

    void Application::MainLoop() {

        while (running_) {
            float current_time = GetTime();
            float delta_time = current_time - last_time_;
            last_time_ = current_time;

            OnUpdate();
        }
    }

    void Application::OnUpdate() {

        
    }

    float Application::GetTime() {
        return (float)glfwGetTime();
    }

} // namespace Chotra_RT