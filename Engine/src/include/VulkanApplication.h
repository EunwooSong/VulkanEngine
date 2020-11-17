//
// Created by EunwooSong on 2020-11-08.
//

#ifndef ENGINE_VULKANAPPLICATION_H
#define ENGINE_VULKANAPPLICATION_H

#include "VulkanInstance.h"
#include "VulkanDevice.h"
#include "VulkanLayerExtension.h"

#include <memory>

class VulkanApplication {
private:
    VulkanApplication();
public:
    ~VulkanApplication();

    static VulkanApplication* GetInstance();

    void Initialize();
    void Prepare(){};
    void Update(){};
    bool Render(){ return true;};
    void Release(){};

    VulkanInstance& GetVulkanInstance() { return instanceObj; }
    VulkanDevice*   GetVulkanDevice()   { return deviceObj; }

private:
    static std::unique_ptr<VulkanApplication> instance;
    static std::once_flag onlyOnce;

    VkResult CreateVulkanInstance(std::vector<const char *>& layers, std::vector<const char *>& extensions,  const char* applicationName);
    VkResult HandShakeWithDevice(VkPhysicalDevice* gpu, std::vector<const char *>& layers, std::vector<const char *>& extensions);
    VkResult EnumeratePhysicalDevices(std::vector<VkPhysicalDevice>& gpus);

public:
    VulkanInstance  instanceObj;
    VulkanDevice*   deviceObj;
};


#endif //ENGINE_VULKANAPPLICATION_H
