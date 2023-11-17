#include "window.h"


namespace Chotra_RT {

    Window::Window(size_t width, size_t hight)
        : width_(width), hight_(hight) {
        glfw_window_ = glfwCreateWindow(width_, hight_, "Chotra_RT", nullptr, nullptr);
    }

    Window::~Window() {

    }

} // namespace Chotra_RT