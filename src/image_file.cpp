#include "image_file.h"

#include <iostream>

#include "image.h"

namespace Chotra_RT {

    FilePPM::FilePPM(const char* filename)
        : File(filename) {

    }

    void FilePPM::SaveFile(ImagePPM& image) {
        DeleteFile();
        std::clog << "\nSaving:\n";

        std::string s = "P3\n" + std::to_string(image.GetWidth()) + ' ' + std::to_string(image.GetHeight()) + "\n255\n";
        Append(s.c_str());

        s = "";
        for (int i = 0; i < image.GetHeight(); ++i) {
            std::clog << "\rScanlines remaining: " << (image.GetHeight() - i) << ' ' << std::flush;
            for (int j = 0; j < image.GetWidth(); ++j) {
                Color256 pixel = image.GetPixel(i, j);
                s.append(std::to_string(pixel.r) + " " + std::to_string(pixel.g) + " " + std::to_string(pixel.b) + "  ");
            }
            //s.append("\n");
        }
        Append(s.c_str());

        std::clog << "\nDone\n";
    }

} // namespace Chotra_RT