#include "image.h"

namespace Chotra_RT {

    ImagePPM::ImagePPM(int image_width, int image_height)
        : image_width_(image_width), image_height_(image_height) {

    }

    unsigned int ImagePPM::GetWidth() {
        return image_width_;
    }

    unsigned int ImagePPM::GetHeight() {
        return image_height_;
    }

    unsigned int ImagePPM::AddPixel(Color256 pixel) {
        pixels_.push_back(pixel);
        return pixels_.size() - 1;
    }

    Color256 ImagePPM::GetPixel(unsigned int row, unsigned int col) {
        return pixels_[row * image_width_ + col];
    }

} // namespace Chotra_RT