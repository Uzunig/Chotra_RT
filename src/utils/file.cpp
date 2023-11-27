#include "file.h"

#include <iostream>

namespace Chotra_RT {

    File::File(const char* filename) 
        : filename_(filename) {
       
    }

    File::File(const File& file) 
        : filename_(file.filename_) {
        
    }

    File::~File() {

    }

    void File::SaveFile() {
        DeleteFile();
        outf_ = std::ofstream(filename_);

        if (!outf_) {
            std::cerr << "Uh oh, file could not be opened for writing!" << std::endl;
        }
        outf_.close();
    }

    void File::DeleteFile() {
        if (std::remove(filename_)) {
            std::cerr << "Uh oh, file could not be deleted!" << std::endl;
        }
    }

    void File::Append(const char* text) {

        outf_.open(filename_, std::ios::app);
        outf_ << text;
        outf_.close();
    }

} //namespace Chatra_RT