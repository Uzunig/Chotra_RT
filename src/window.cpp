#include "window.h"


namespace Chotra_RT {

    Window::Window(size_t width, size_t height)
        : width_(width), height_(height) {
        glfw_window_ = glfwCreateWindow(width_, height_, "Chotra_RT", nullptr, nullptr);
    }

    Window::~Window() {

    }

} // namespace Chotra_RT