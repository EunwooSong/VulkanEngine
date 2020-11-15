//
// Created by EunwooSong on 2020-11-08.
//

#ifndef ENGINE_VULKANLAYEREXTENSION_H
#define ENGINE_VULKANLAYEREXTENSION_H

#include "VulkanInclude.h"
#include <vector>

//Notion

struct LayerProperties {
    VkLayerProperties properties;
    std::vector<VkExtensionProperties> extensions;
};

class VulkanLayerAndExtension {
public:
    VulkanLayerAndExtension();
    ~VulkanLayerAndExtension();

    VkResult GetInstanceLayerProperties();

    VkResult GetExtensionProperties(LayerProperties& layerProps, VkPhysicalDevice* gpu = nullptr);

    VkResult GetDeviceExtensionProperties(VkPhysicalDevice* gpu);

public:
    // 필요한 Layer, Extension 이름
    std::vector<const char*> appRequestedLayerNames;
    std::vector<const char* > appRequestedExtensionNames;

    // 레이어와 해당한는 확장판 리스트
    std::vector<LayerProperties> layerPropertyList;
};


#endif //ENGINE_VULKANLAYEREXTENSION_H
