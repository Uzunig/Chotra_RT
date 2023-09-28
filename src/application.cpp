#include "application.h"

#include "image.h"
#include "image_file.h"

namespace Chotra_RT {

    Application::Application() {

    }

    Application::~Application() {

    }

    int Application::Start() {

        Image image(256, 256); // width, height
        ImageFile image_file("image.ppm");

        std::string s = "P3\n" + std::to_string(image.GetWidth()) + ' ' + std::to_string(image.GetHeight()) + "\n255\n";
        image_file.Append(s.c_str());

        for (int i = 0; i < image.GetHeight(); ++i) {
            for (int j = 0; j < image.GetWidth(); ++j) {
                s = std::to_string(i) + " " + std::to_string(j) + " " + std::to_string(0) + "  ";
                image_file.Append(s.c_str());
            }
            s = "\n";
            image_file.Append(s.c_str());
        }
        std::cout << "Done\n"; 
        return 0; 
    }

} // namespace Chotra_RT