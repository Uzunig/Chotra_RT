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

        std::cout << "P3\n" << image.GetWidth() << ' ' << image.GetHeight() << "\n255\n";

        for (int i = 0; i < image.GetHeight(); ++i) {
            for (int j = 0; j < image.GetWidth(); ++j) {
                std::cout << i << " " << j << " " << 0 << "  ";
            }
            std::cout << std::endl;
        }

        return 0;
    }

} // namespace Chotra_RT