#include "image_file.h"

#include <iostream>

#include "image.h"

namespace Chotra_RT {

    FilePPM::FilePPM(const char* filename)
        : File(filename) {

    }

    void FilePPM::SaveFile(ImagePPM& image) {
        std::clog << "\nSaving:\n";
        DeleteFile();
        outf_ = std::ofstream(filename_);

        if (!outf_) {
            std::cerr << "Uh oh, file could not be opened for writing!" << std::endl;
        }
        
        outf_ << "P3\n" << image.GetWidth() << ' ' << image.GetHeight() << "\n255\n";

        for (int i = 0; i < image.GetHeight(); ++i) {
            std::clog << "\rScanlines remaining: " << (image.GetHeight() - i) << ' ' << std::flush;
            for (int j = 0; j < image.GetWidth(); ++j) {
                Color256 pixel = image.GetPixel(i, j);
                outf_ << pixel.r << " " << pixel.g << " " << pixel.b << " ";
            }
            outf_<< "\n";
        }
        outf_.close();
        std::clog << "\nDone\n";
    }

} // namespace Chotra_RT