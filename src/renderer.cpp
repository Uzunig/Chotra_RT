#include "renderer.h"

#include <iostream>

#include "image.h"
#include "image_file.h"

namespace Chotra_RT {

    Renderer::Renderer() {

    }

    void Renderer::Render() {
/*
        ImagePPM image(256, 256); // width, height
        FilePPM image_file("image.ppm");

        std::string s = "P3\n" + std::to_string(image.GetWidth()) + ' ' + std::to_string(image.GetHeight()) + "\n255\n";
        image_file.Append(s.c_str());

        for (int i = 0; i < image.GetHeight(); ++i) {
            std::clog << "\rScanlines remaining: " << (image.GetHeight() - i) << ' ' << std::flush;
            for (int j = 0; j < image.GetWidth(); ++j) {
                s = std::to_string(i) + " " + std::to_string(j) + " " + std::to_string(0) + "  ";
                image_file.Append(s.c_str());
            }
            s = "\n";
            image_file.Append(s.c_str());
        }
        std::clog << "\nDone\n";*/
    }

} // namespace Chotra_RT
