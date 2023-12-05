#ifndef WINDOW_H
#define WINDOW_H

#include <GLFW/glfw3.h>

namespace Chotra_RT {

    class Window {

    public:
        Window(int width, int hight);
        virtual ~Window();

        GLFWwindow* glfw_window_ = nullptr;
    private:
        int width_;
        int hight_;

    };
} // namespace Chotra_RT

#endif;

