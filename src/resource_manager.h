#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <memory>
#include <vector>

namespace Chotra_RT {

    class Camera;

    class ResourceManager {
    public:
        static size_t AddCamera();

    private:
        static std::vector<std::shared_ptr<Camera>> cameras_;

    };
} // namespace Chotra_RT
#endif
