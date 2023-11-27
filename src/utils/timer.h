#ifndef TIMER_H
#define TIMER_H

#include <iostream>

namespace Chotra_RT {

    class Timer {
    public:
        Timer();
        ~Timer() = default;

        void ResetTimer();
        float GetTimer();

    private:
        float last_time_;
    };

} // namespace Chotra_RT

#endif