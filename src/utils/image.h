#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include <vector>

namespace Chotra_RT {

    class Color256 {
    public:

        Color256() = default;
        Color256(unsigned char r, unsigned char g, unsigned char b);

        uint8_t r;
        uint8_t g;
        uint8_t b;
    };

    class ImagePPM {
    public:
        ImagePPM(unsigned int image_width, unsigned int image_hight);
        
        unsigned int GetWidth();
        unsigned int GetHight();

        std::vector<Color256> pixels_;

        void SetPixel(unsigned int row, unsigned int col, Color256 pixel);
        Color256 GetPixel(unsigned int row, unsigned int col);

    private:
        unsigned int image_width_;
        unsigned int image_hight_;
    };

} // namespace Chotra_RT
#endif