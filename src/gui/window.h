#ifndef WINDOW_H
#define WINDOW_H

#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>

namespace Chotra_RT {

    class Window {

    public:
        Window(int width, int hight);
        virtual ~Window();

    private:
        int width_;
        int hight_;
        GLFWwindow* glfw_window_ = nullptr;
        
    };
} // namespace Chotra_RT

#endif;

