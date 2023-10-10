#ifndef IMAGE_FILE_H
#define IMAGE_FILE_H

#include <fstream>

#include "file.h"
#include "image.h"

namespace Chotra_RT {

    class FilePPM : public File {
    public:
        FilePPM(const char* filename);
        void SaveFile(ImagePPM& image);

    private:
        
   
    };
} // namespace Chotra_RT
#endif
