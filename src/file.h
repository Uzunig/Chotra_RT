#ifndef FILE_H
#define FILE_H

#include <string>
#include <fstream>

namespace Chotra_RT {

    class File {
    public:
        File() = delete;
        File(std::string filename);

    private:
        std::string filename_;
        std::ofstream outf_;

        int CreateFile();
    };

} //namespace Chatra_RT
#endif

