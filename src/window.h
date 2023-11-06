#ifndef WINDOW_H
#define WINDOW_H

#include <GLFW/glfw3.h>

namespace Chotra_RT {

    class Window {

    public:
        Window();
        virtual ~Window();


      

    private:
        GLFWwindow* glfw_window_ = nullptr;
        
    };
} // namespace Chotra_RT

#endif;

