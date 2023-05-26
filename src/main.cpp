#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

#include <iostream>

static bool GLFW_initialized = false;

int main() {

    glm::vec3 vector;

    if (!GLFW_initialized) {
        if (!glfwInit()) {
            std::cout << "Failed to initialize GLFW" << std::endl;
            return -1;
        }
    }
    int x;
    std::cin >> x;
    return 0;
}