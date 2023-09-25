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

    std::unique_ptr<Chotra_RT::Application> application = std::make_unique<Chotra_RT::Application>();
    int return_code = application->Start();

    std::cin.get();
    return return_code;
}