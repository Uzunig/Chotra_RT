#include "image.h"

namespace Chotra_RT {

    Image::Image(int image_width, int image_height)
        : image_width_(image_width), image_height_(image_height) {

    }

    int Image::GetWidth() {
        return image_width_;
    }

    int Image::GetHeight() {
        return image_height_;
    }

} // namespace Chotra_RT