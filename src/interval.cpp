#include "interval.h"

namespace Chotra_RT {
        
    const static Interval empty(+infinity, -infinity);
    const static Interval universe(-infinity, +infinity);

    Interval::Interval(double _min, double _max) 
        : min(_min), max(_max) {
    
    }

    bool Interval::Contains(double x) const {
        return min <= x && x <= max;
    }

    bool Interval::Surrounds(double x) const {
        return min < x && x < max;
    }

    double Interval::Clamp(double x) const {
        if (x < min) return min;
        if (x > max) return max;
        return x;
    }
  

} // namespace Chotra_RT