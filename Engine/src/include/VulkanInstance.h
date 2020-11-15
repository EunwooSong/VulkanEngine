//
// Created by EunwooSong on 2020-11-08.
//

#ifndef ENGINE_VULKANINSTANCE_H
#define ENGINE_VULKANINSTANCE_H

#include "VulkanInclude.h"
#include "VulkanLayerExtension.h"
class VulkanInstance {
public:
    VulkanInstance();
    ~VulkanInstance();

    //Vulkan Instance 생성과 삭제
    VkResult CreateInstance(std::vector<const char *> &layers,
                            std::vector<const char *> &extensionNames,
                            char const*const &appName);
    void DestroyInstance();

public:
    VkInstance instance;                        //Vulkan 인스턴스 개체 변수
    VulkanLayerAndExtension layerExtension;     //Vulkan 스턴스 지정 레이어 및 확장판

};


#endif //ENGINE_VULKANINSTANCE_H
