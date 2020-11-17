//
// Created by EunwooSong on 2020-11-17.
//

#ifndef ENGINE_VULKANWRAPPERS_H
#define ENGINE_VULKANWRAPPERS_H

#include "VulkanInclude.h"

class CommandBufferMgr {
public:
    static void AllocCommandBuffer(const VkDevice* device, const VkCommandPool cmdPool, VkCommandBuffer* cmdBuf, const VkCommandBufferAllocateInfo* commandBufferInfo = NULL);
    static void BeginCommandBuffer(VkCommandBuffer cmdBuf, VkCommandBufferBeginInfo* inCmdBufInfo = NULL);
    static void EndCommandBuffer(VkCommandBuffer cmdBuf);
    static void SubmitCommandBuffer(const VkQueue& queue, const VkCommandBuffer* cmdBufList, const VkSubmitInfo* submitInfo = NULL, const VkFence& fence = VK_NULL_HANDLE);
};

#endif //ENGINE_VULKANWRAPPERS_H
