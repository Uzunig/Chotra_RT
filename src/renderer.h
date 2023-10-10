#ifndef RENDERER_H
#define RENDERER_H

namespace Chotra_RT {

    class ImagePPM;

    class Renderer {
    public:
        Renderer();
        void Render(ImagePPM& resultImage);
    };

} //namespace Chotra_RT

#endif
