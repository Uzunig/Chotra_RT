#ifndef FILE_H
#define FILE_H

#include <string>
#include <fstream>

namespace Chotra_RT {

    class File {
    public:
        File() = delete;
        File(const char* filename);

        File(const File& file);
        File& operator=(const File& file) = delete;
        ~File();

    private:
        const char* filename_;
        std::ofstream outf_;

        int CreateFile();
        int DeleteFile();
    };

} //namespace Chatra_RT
#endif

