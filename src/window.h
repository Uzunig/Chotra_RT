#ifndef WINDOW_H
#define WINDOW_H

#include <GLFW/glfw3.h>

namespace Chotra_RT {

    class Window {

    public:
        Window(size_t width, size_t hight);
        virtual ~Window();


      

    private:
        size_t width_;
        size_t hight_;
        GLFWwindow* glfw_window_ = nullptr;
        
    };
} // namespace Chotra_RT

#endif;

