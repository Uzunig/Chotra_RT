#include <GLFW/glfw3.h>

#include <iostream>

#include "application.h"

static bool GLFW_initialized = false;

int main() {

    if (!GLFW_initialized) {
        if (!glfwInit()) {
            std::cout << "Failed to initialize GLFW" << std::endl;
            return -1;
        }
    }

    Chotra_RT::ApplicationSpecification applicationSpecification;

    std::unique_ptr<Chotra_RT::Application> application = std::make_unique<Chotra_RT::Application>(applicationSpecification);
    application->Run();

    return 0;
}