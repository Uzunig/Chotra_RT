#include "application.h"

#include <iostream>
#include <chrono>
#include <memory>
#include <thread>

namespace Chotra_RT {

    Application::Application() 
        : glfw_context_(GLFWContext::GetInstance())
        , main_window_(Window(application_properties_.width, application_properties_.hight))
        , vulkan_context_(VulkanContext::GetInstance(main_window_.glfw_window_)) {

    }

    
    void Application::Run() {
               
        //std::thread th([&]() {renderer_.RenderToImageFile(); });

        MainLoop();

       // th.join();
    }

    void Application::MainLoop() {
        timer_.ResetTimer();
        while (running_) {
            glfwPollEvents();
            OnUpdate(timer_.GetTimer());
            timer_.ResetTimer();
        }
    }

    void Application::OnUpdate(float delta_time) {
        vulkan_context_.DrawFrame();
    }
        
} // namespace Chotra_RT