#include "window.h"


namespace Chotra_RT {

    Window::Window(int width, int hight)
        : width_(width), hight_(hight) {

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
        glfw_window_ = glfwCreateWindow(width_, hight_, "Chotra_RT", nullptr, nullptr);
    }

    Window::~Window() {
        glfwDestroyWindow(glfw_window_);
    }

} // namespace Chotra_RT