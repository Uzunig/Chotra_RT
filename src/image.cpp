#include "image.h"

namespace Chotra_RT {

    Color256::Color256(unsigned char r, unsigned char g, unsigned char b) 
        : r(r),  g(g), b(b){
        
    }

    ImagePPM::ImagePPM(unsigned int image_width, unsigned int image_height)
        : image_width_(image_width), image_height_(image_height) {
        pixels_.resize(image_width_ * image_height_);
    }

    unsigned int ImagePPM::GetWidth() {
        return image_width_;
    }

    unsigned int ImagePPM::GetHeight() {
        return image_height_;
    }

    void ImagePPM::SetPixel(unsigned int row, unsigned int col, Color256 pixel) {
        pixels_[row * image_height_ + col] = pixel;
    }

    Color256 ImagePPM::GetPixel(unsigned int row, unsigned int col) {
        return pixels_[row * image_width_ + col];
    }
        

} // namespace Chotra_RT