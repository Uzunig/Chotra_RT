#ifndef APPLICATION_H
#define APPLICATION_H

#include <string>
#include <GLFW/glfw3.h>

#include "renderer.h"

namespace Chotra_RT {


    struct ApplicationProperties {
        std::string name = "Chotra_RT";
        std::string working_directory;
    };

    class Application {

    public:
        Application(const ApplicationProperties application_properties);
        virtual ~Application();

        Application(const Application&) = delete;
        Application(Application&&) = delete;

        Application& operator=(const Application&) = delete;
        Application& operator=(Application&&) = delete;

        void Run();
        void OnUpdate();
        float GetTime();


    private:
        ApplicationProperties application_properties_;

        bool running_ = true;
        float last_time_ = 0.0f;

        Renderer renderer_;

        void RenderImage();

        void MainLoop();

        bool InitGLFW();
        bool TerminateGLFW();
    };
} // namespace Chotra_RT

#endif;

