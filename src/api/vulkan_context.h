#ifndef VULKAN_CONTEXT_H
#define VULKAN_CONTEXT_H

#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>

namespace Chotra_RT {

   
    class VulkanContext {
    public:
        static VulkanContext& GetInstance();
      

    private:
        VulkanContext();
        ~VulkanContext();
               
        void InitVulkan();
        void TerminateVulkan();

        VkInstance vk_instance_;

    };

} // namespace Chotra_RT
#endif
