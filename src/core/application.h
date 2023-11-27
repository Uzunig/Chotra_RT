#ifndef APPLICATION_H
#define APPLICATION_H

#include <string>

#include "api/glfw_context.h"
#include "renderer.h"
#include "utils/timer.h"

namespace Chotra_RT {

    class Application {
    public:
        Application();
        virtual ~Application() = default;

        Application(const Application&) = delete;
        Application(Application&&) = delete;

        Application& operator=(const Application&) = delete;
        Application& operator=(Application&&) = delete;

        void Run();
        void OnUpdate(float delta_time);
        

    private:
        struct ApplicationProperties {
            std::string name = "Chotra_RT";
            std::string working_directory;
        } application_properties_;

        bool running_ = true;

        GLFWContext& glfw_context_;
        Timer timer_;
        Renderer renderer_;

        void MainLoop();
          
    };
} // namespace Chotra_RT

#endif

