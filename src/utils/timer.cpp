#include "timer.h"

#include <GLFW/glfw3.h>

namespace Chotra_RT {

    Timer::Timer() :
        last_time_((float)glfwGetTime()) {

    }

    void Timer::ResetTimer() {
        last_time_ = (float)glfwGetTime();
    }

    float Timer::GetTimer() {

        return (float)glfwGetTime() - last_time_;
    }



} // namespace Chotra_RT