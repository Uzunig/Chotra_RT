#ifndef APPLICATION_H
#define APPLICATION_H

#include <string>
#include <GLFW/glfw3.h>

namespace Chotra_RT {

    class Renderer;

    struct ApplicationSpecification {
        std::string name = "Chotra_RT";
        std::string workingDirectory;
    };

    class Application {

    public:
        Application(const ApplicationSpecification applicationSpecification);
        virtual ~Application();

        Application(const Application&) = delete;
        Application(Application&&) = delete;

        Application& operator=(const Application&) = delete;
        Application& operator=(Application&&) = delete;

        void Run();
        void OnUpdate();
        float GetTime();


    private:
        ApplicationSpecification applicationSpecification_;

        bool running_ = true;
        float lastTime_ = 0.0f;

        Renderer renderer_;
    };
} // namespace Chotra_RT

#endif;

