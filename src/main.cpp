
#include <iostream>

#include "application.h"

// Constants

const double pi = 3.1415926535897932385;

// Utility Functions

inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}


int main() {

    Chotra_RT::ApplicationProperties application_properties;

    std::unique_ptr<Chotra_RT::Application> application = std::make_unique<Chotra_RT::Application>(application_properties);
    application->Run();

    return 0;
}