#include "image_file.h"

#include <iostream>

namespace Chotra_RT {

    ImageFile::ImageFile(std::string filename)
        : filename_(filename) {

        CreateImageFile();
    }

    int ImageFile::CreateImageFile() {

        outf_ = std::ofstream(filename_);

        if (!outf_)
        {
            // то выводим сообщение об ошибке и выполняем функцию exit()
            std::cerr << "Uh oh, SomeText.txt could not be opened for writing!" << std::endl;
            return 1;
        }
        outf_.close();

    }

    void ImageFile::Append(const char* text) {

        outf_.open("SomeText.txt", std::ios::app);
        outf_ << text;
        outf_.close();
    }

} // namespace Chotra_RT