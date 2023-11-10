#include "application.h"

#include <iostream>
#include <chrono>
#include <memory>
#include <thread>

#include "camera.h"
#include "quad.h"
#include "window.h"
#include "image.h"
#include "hittable_list.h"
#include "image_file.h"

namespace Chotra_RT {

    static bool GLFW_initialized = false;

    Application::Application(ApplicationProperties application_properties)
        : application_properties_(application_properties) {

    }

    Application::~Application() {

    }

    void Application::RenderImage() {
        ImagePPM image(400, 400);
        Camera camera = Camera();
        HittableList world;

        renderer_.Render(image, camera, world);
        //renderer_.Render(image, camera, world);
        FilePPM file("image.ppm");
        file.SaveFile(image);
    }

    void Application::Run() {
        
        if (!InitGLFW()) return;
        last_time_ = GetTime();
        Window main_window = Window(600, 600);
        
        std::thread th([&]() {RenderImage(); });

        float current_time = GetTime();
        float delta_time = current_time - last_time_;

        MainLoop();

        th.join();
        TerminateGLFW();
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

    bool Application::InitGLFW() {
        if (!GLFW_initialized) {
            if (!glfwInit()) {
                std::cout << "Failed to initialize GLFW" << std::endl;
                return false;
            }
            glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
            glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
        }
        return true;
    }

    bool Application::TerminateGLFW() {
        if (!GLFW_initialized) {
            std::cout << "GLFW is not inizialised" << std::endl;
            return false;
        }
        glfwTerminate();
        return true;
    }

} // namespace Chotra_RT