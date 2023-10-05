#include "file.h"

#include <iostream>

namespace Chotra_RT {

    File::File(std::string filename) 
        : filename_(filename) {
        CreateFile();
    }

    int File::CreateFile() {
        outf_ = std::ofstream(filename_);

        if (!outf_)
        {
            // то выводим сообщение об ошибке и выполняем функцию exit()
            std::cerr << "Uh oh, SomeText.txt could not be opened for writing!" << std::endl;
            return 1;
        }
        outf_.close();
        return 0;
    }

} //namespace Chatra_Rt