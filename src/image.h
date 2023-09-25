#ifndef IMAGE_H
#define IMAGE_H

#include <string>

namespace Chotra_RT {

    class Image
    {
    public:
        Image(int image_width, int image_height);
        int GetWidth();
        int GetHeight();

    private:
        int image_width_;
        int image_height_;

    };

} // namespace Chotra_RT
#endif