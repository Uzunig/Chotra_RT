#include "vulkan_context.h"

#include <iostream>

namespace Chotra_RT {

    VulkanContext& VulkanContext::GetInstance() {

        static VulkanContext instance;
        if (!instance.vk_instance_) {
            instance.InitVulkan();
        }
        return instance;
    }

    VulkanContext::VulkanContext() {
        InitVulkan();
    }

    VulkanContext::~VulkanContext() {
        TerminateVulkan();
    }

    void VulkanContext::InitVulkan() {
            VkApplicationInfo appInfo{};
            appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
            appInfo.pApplicationName = "Hello Triangle";
            appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
            appInfo.pEngineName = "No Engine";
            appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
            appInfo.apiVersion = VK_API_VERSION_1_0;

            VkInstanceCreateInfo createInfo{};
            createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
            createInfo.pApplicationInfo = &appInfo;

            uint32_t glfwExtensionCount = 0;
            const char** glfwExtensions;
            glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

            createInfo.enabledExtensionCount = glfwExtensionCount;
            createInfo.ppEnabledExtensionNames = glfwExtensions;

            createInfo.enabledLayerCount = 0;

            if (vkCreateInstance(&createInfo, nullptr, &vk_instance_) != VK_SUCCESS) {
                //throw std::runtime_error("failed to create instance!");
                std::cerr << "Failed to initialize Vulkan" << std::endl;
            }
    }

    void VulkanContext::TerminateVulkan() {
            vkDestroyInstance(vk_instance_, nullptr);
    }

} // namespace Chotra_RT