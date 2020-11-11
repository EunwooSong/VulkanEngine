//
// Created by EunwooSong on 2020-11-08.
//

#ifndef ENGINE_VULKANINSTANCE_H
#define ENGINE_VULKANINSTANCE_H

#include "VulkanInclude.h"

class VulkanInstance {
public:
    VulkanInstance();
    ~VulkanInstance();

public:
    VkInstance instance;

};


#endif //ENGINE_VULKANINSTANCE_H
