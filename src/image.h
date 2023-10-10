#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include <vector>

namespace Chotra_RT {

    class Color256 {
    public:

        Color256() = default;
        Color256(unsigned char r, unsigned char g, unsigned char b);

        unsigned char r;
        unsigned char g;
        unsigned char b;
    };

    class ImagePPM {
    public:
        ImagePPM(unsigned int image_width, unsigned int image_height);
        
        unsigned int GetWidth();
        unsigned int GetHeight();

        unsigned int AddPixel(Color256 pixel);
        Color256 GetPixel(unsigned int row, unsigned int col);

    private:
        unsigned int image_width_;
        unsigned int image_height_;
    public:
        std::vector<Color256> pixels_;

    };

} // namespace Chotra_RT
#endif