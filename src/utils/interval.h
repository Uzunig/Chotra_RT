#ifndef INTERVAL_H
#define INTERVAL_H

#include <iostream>

namespace Chotra_RT {

    const double infinity = std::numeric_limits<double>::infinity();

    class Interval {
    public:
        double min, max;

        Interval() : min(+infinity), max(-infinity) {} // Default interval is empty

        Interval(double _min, double _max);

        bool Contains(double x) const;
        bool Surrounds(double x) const;
        double Clamp(double x) const;

        static const Interval empty, universe;
    };

} // namespace Chotra_RT

#endif