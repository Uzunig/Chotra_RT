#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include <vector>

namespace Chotra_RT {

    class Color256 {
        unsigned char r;
        unsigned char g;
        unsigned char b;
    };

    class ImagePPM
    {
    public:
        ImagePPM(int image_width, int image_height);
        
        unsigned int GetWidth();
        unsigned int GetHeight();

        unsigned int AddPixel(Color256 pixel);
        Color256 GetPixel(unsigned int row, unsigned int col);

    private:
        unsigned int image_width_;
        unsigned int image_height_;

        std::vector<Color256> pixels_;

    };

} // namespace Chotra_RT
#endif