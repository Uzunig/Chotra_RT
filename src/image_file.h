#ifndef IMAGE_FILE_H
#define IMAGE_FILE_H

#include <fstream>

namespace Chotra_RT {

    class ImageFile
    {
    public:
        ImageFile(std::string filename);

    private:
        std::string filename_;
        std::ofstream outf_;

        int CreateImageFile();
        void Append(const char* text);
    };
} // namespace Chotra_RT
#endif
