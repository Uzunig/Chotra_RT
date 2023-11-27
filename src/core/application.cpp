#include "application.h"

#include <iostream>
#include <chrono>
#include <memory>
#include <thread>

#include "gui/window.h"

namespace Chotra_RT {

    Application::Application() : glfw_context_(GLFWContext::GetInstance()){

    }

    
    void Application::Run() {
                
        Window main_window = Window(600, 600);
        
        std::thread th([&]() {renderer_.RenderToImageFile(); });

        MainLoop();

        th.join();
    }

    void Application::MainLoop() {
        timer_.ResetTimer();
        while (running_) {
            
            OnUpdate(timer_.GetTimer());
            timer_.ResetTimer();
        }
    }

    void Application::OnUpdate(float delta_time) {


    }
        
} // namespace Chotra_RT