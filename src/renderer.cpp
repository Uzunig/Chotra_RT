#include "renderer.h"

#include <iostream>

#include "image.h"
#include "image_file.h"

namespace Chotra_RT {

    Renderer::Renderer() {

    }

    void Renderer::Render(ImagePPM& resultImage) {

        std::clog << "\nRendering:\n";
        for (int i = 0; i < resultImage.GetHeight(); ++i) {
            std::clog << "\rScanlines remaining: " << (resultImage.GetHeight() - i) << ' ' << std::flush;
            for (int j = 0; j < resultImage.GetWidth(); ++j) {
                Color256 pixel(i, j, 0);
                resultImage.AddPixel(pixel);
            }
        }
    }

} // namespace Chotra_RT
