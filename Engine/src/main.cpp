#include <iostream>

#include "include/VulkanInclude.h"
#include "include/VulkanApplication.h"

std::vector<const char *> instanceExtensionNames = {
        VK_KHR_SURFACE_EXTENSION_NAME,
        VK_EXT_DEBUG_REPORT_EXTENSION_NAME
};

std::vector<const char *> layerNames = {
        "VK_LAYER_GOOGLE_threading",
        "VK_LAYER_LUNARG_parameter_validation",
        "VK_LAYER_LUNARG_object_tracker",
        "VK_LAYER_LUNARG_image",
        "VK_LAYER_LUNARG_core_validation",
        "VK_LAYER_LUNARG_swapchain",
        "VK_LAYER_GOOGLE_unique_objects"
};

std::vector<const char *> deviceExtensionNames = {
        VK_KHR_SWAPCHAIN_EXTENSION_NAME
};

int main(int argc, char **argv)
{
    VulkanApplication* appObj = VulkanApplication::GetInstance();
    appObj->Initialize();
    appObj->Prepare();
    appObj->Render();
    appObj->Release();
    return 0;
}