#ifndef RENDERER_H
#define RENDERER_H

#include <glm/glm.hpp>


namespace Chotra_RT {

    class ImagePPM;
    class Camera;
    class HittableList;

    class Renderer {
    public:
        Renderer();
        void Render(ImagePPM& resultImage, const Camera& camera, HittableList& world);
        void RenderToImageFile();

    private:
        

    };

} //namespace Chotra_RT

#endif
