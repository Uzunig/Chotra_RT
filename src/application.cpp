#include "application.h"

#include <chrono>

#include "resource_manager.h"
#include "image_file.h"
#include "image.h"


namespace Chotra_RT {

    Application::Application(ApplicationSpecification applicationSpecification)
        : applicationSpecification_(applicationSpecification) {

    }

    Application::~Application() {

    }

    void Application::Run() {

        ResourceManager::AddCamera();

        ImagePPM image(1024, 1024);
        renderer_.Render(image);
        const char* filename = "image.ppm";
        FilePPM file(filename);
        file.SaveFile(image);
       
        while (running_) {
            float currentTime = GetTime();
            float deltaTime = currentTime - lastTime_;
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