#include "core/application.h"

// Constants

const double pi = 3.1415926535897932385;

// Utility Functions

double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}


int main() {
        
    std::unique_ptr<Chotra_RT::Application> application = std::make_unique<Chotra_RT::Application>();
    application->Run();

    return 0;
}