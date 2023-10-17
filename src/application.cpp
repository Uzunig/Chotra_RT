#include "application.h"

#include <iostream>
#include <chrono>

#include "resource_manager.h"
#include "image_file.h"
#include "image.h"
#include "camera.h"


namespace Chotra_RT {

    Application::Application(ApplicationSpecification applicationSpecification)
        : applicationSpecification_(applicationSpecification) {

    }

    Application::~Application() {

    }

    void Application::Run() {

        lastTime_ = GetTime();
        
        ImagePPM image(3840, 2160);
        Camera camera(image);
        camera.Take()

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