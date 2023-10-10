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

        void SaveFile();
        void DeleteFile();

        void Append(const char* text);

    private:
        const char* filename_;
        std::ofstream outf_;
                
    };

} //namespace Chatra_RT
#endif

