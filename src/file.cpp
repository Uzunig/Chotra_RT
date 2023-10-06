#include "file.h"

#include <iostream>

namespace Chotra_RT {

    File::File(const char* filename) 
        : filename_(filename) {
        CreateFile();
    }

    File::File(const File& file) 
        : filename_(file.filename_) {
        CreateFile();
    }

    File::~File() {
        DeleteFile();
    }


    int File::CreateFile() {
        outf_ = std::ofstream(filename_);

        if (!outf_) {
            std::cerr << "Uh oh, file could not be opened for writing!" << std::endl;
            return 1;
        }
        outf_.close();
        return 0;
    }

    int File::DeleteFile() {

        if (std::remove(filename_)) {
            std::cerr << "Uh oh, file could not be deleted!" << std::endl;
            return 1;
        }
        return 0;
    }

} //namespace Chatra_Rt