//
// Created by EunwooSong on 2020-11-08.
//

#include "include/VulkanInstance.h"

VulkanInstance::VulkanInstance() {

}

VulkanInstance::~VulkanInstance() {

}

VkResult VulkanInstance::CreateInstance(std::vector<const char *> &layers, std::vector<const char *> &extensionNames,
                                        char const*const &appName) {
    layerExtension.appRequestedExtensionNames	= extensionNames;
    layerExtension.appRequestedLayerNames		= layers;

    // Vulkan 응용 구조체 정의
    VkApplicationInfo appInfo	= {};
    appInfo.sType				= VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pNext				= NULL;
    appInfo.pApplicationName	= appName;
    appInfo.applicationVersion	= 1;
    appInfo.pEngineName			= appName;
    appInfo.engineVersion		= 1;
    appInfo.apiVersion			= VK_MAKE_VERSION(1, 0, 0);

    // Vulkan 인스턴스 생성 정보 구조체 정의
    VkInstanceCreateInfo instInfo	= {};
    instInfo.sType					= VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    instInfo.pNext					= VK_NULL_HANDLE;
    instInfo.flags					= 0;
    instInfo.pApplicationInfo		= &appInfo;

    // Specify the list of layer name to be enabled.
    instInfo.enabledLayerCount		= (uint32_t)layers.size();
    instInfo.ppEnabledLayerNames	= layers.size() ? layers.data() : NULL;

    // Specify the list of extensions to be used in the application.
    instInfo.enabledExtensionCount	= (uint32_t)extensionNames.size();
    instInfo.ppEnabledExtensionNames = extensionNames.size() ? extensionNames.data() : NULL;

    VkResult result = vkCreateInstance(&instInfo, NULL, &instance);
    assert(result == VK_SUCCESS);

    return result;
}

void VulkanInstance::DestroyInstance() {

}