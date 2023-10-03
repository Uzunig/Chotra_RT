#include "resource_manager.h"

#include "camera.h"

namespace Chotra_RT {

    std::vector<std::shared_ptr<Camera>()> ResourceManager::cameras_;

    size_t ResourceManager::AddCamera() {

        cameras_.push_back(std::make_shared<Camera>);
        return cameras_.size() - 1;
        
    }

} // namespace Chotra_RT