#include "image.h"

namespace Chotra_RT {

    Color256::Color256(unsigned char r, unsigned char g, unsigned char b) 
        : r(r),  g(g), b(b){
        
    }

    ImagePPM::ImagePPM(unsigned int image_width, unsigned int image_hight)
        : image_width_(image_width), image_hight_(image_hight) {
        pixels_.resize(image_width_ * image_hight_);
    }

    unsigned int ImagePPM::GetWidth() {
        return image_width_;
    }

    unsigned int ImagePPM::GetHight() {
        return image_hight_;
    }

    void ImagePPM::SetPixel(unsigned int row, unsigned int col, Color256 pixel) {
        pixels_[row * image_hight_ + col] = pixel;
    }

    Color256 ImagePPM::GetPixel(unsigned int row, unsigned int col) {
        return pixels_[row * image_width_ + col];
    }
        

} // namespace Chotra_RT