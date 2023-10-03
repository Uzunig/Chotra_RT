#include "application.h"

#include <chrono>

#include "renderer.h"
#include "resource_manager.h"


namespace Chotra_RT {

    Application::Application(ApplicationSpecification applicationSpecification)
        : applicationSpecification_(applicationSpecification) {

    }

    Application::~Application() {

    }

    void Application::Run() {

        ResourceManager::AddCamera();
        renderer_.Render();


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