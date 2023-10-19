#include <GLFW/glfw3.h>

#include <iostream>

#include "application.h"

// Constants

const double pi = 3.1415926535897932385;

// Utility Functions

inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}


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