#ifndef RENDERER_H
#define RENDERER_H

namespace Chotra_RT {

    class ImagePPM;
    class Camera;

    class Renderer {
    public:
        Renderer();
        void Render(ImagePPM& resultImage, const Camera& camera);
    };

} //namespace Chotra_RT

#endif
