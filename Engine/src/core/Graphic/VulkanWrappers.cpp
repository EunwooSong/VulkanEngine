//
// Created by EunwooSong on 2020-11-17.
//

#include "include/VulkanWrappers.h"

// 커맨드 풀로부터 커맨드 버퍼에 필요한 메모리 할당
void CommandBufferMgr::AllocCommandBuffer(const VkDevice* device, const VkCommandPool cmdPool, VkCommandBuffer* cmdBuf, const VkCommandBufferAllocateInfo* commandBufferInfo)
{
    VkResult result;

    // 커맨드 정보를 사용할 수 있으면 그대로 사용
    if (commandBufferInfo) {
        result = vkAllocateCommandBuffers(*device, commandBufferInfo, cmdBuf);
        assert(!result);
        return;
    }

    // 기본 구현, 커맨드 버퍼 할당 정보를 생성하고 제공된 파라미터를 넣음
    VkCommandBufferAllocateInfo cmdInfo = {};
    cmdInfo.sType		= VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    cmdInfo.pNext		= NULL;
    cmdInfo.commandPool = cmdPool;
    cmdInfo.level		= VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    cmdInfo.commandBufferCount = (uint32_t) sizeof(cmdBuf) / sizeof(VkCommandBuffer);;

    // 메모리 할당
    result = vkAllocateCommandBuffers(*device, &cmdInfo, cmdBuf);
    assert(!result);
}

// 커맨드 버퍼 레코딩 시작
void CommandBufferMgr::BeginCommandBuffer(VkCommandBuffer cmdBuf, VkCommandBufferBeginInfo* inCmdBufInfo)
{
    VkResult  result;

    // 사용자의 커맨드 버퍼 사용
    if (inCmdBufInfo) {
        result = vkBeginCommandBuffer(cmdBuf, inCmdBufInfo);
        assert(result == VK_SUCCESS);
        return;
    }

    // 기본 커맨드 버퍼 구현 사용
    VkCommandBufferInheritanceInfo cmdBufInheritInfo = {};
    cmdBufInheritInfo.sType					= VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO;
    cmdBufInheritInfo.pNext					= NULL;
    cmdBufInheritInfo.renderPass			= VK_NULL_HANDLE;
    cmdBufInheritInfo.subpass				= 0;
    cmdBufInheritInfo.framebuffer			= VK_NULL_HANDLE;
    cmdBufInheritInfo.occlusionQueryEnable	= VK_FALSE;
    cmdBufInheritInfo.queryFlags			= 0;
    cmdBufInheritInfo.pipelineStatistics	= 0;

    VkCommandBufferBeginInfo cmdBufInfo = {};
    cmdBufInfo.sType				= VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
    cmdBufInfo.pNext				= NULL;
    cmdBufInfo.flags				= 0;
    cmdBufInfo.pInheritanceInfo		= &cmdBufInheritInfo;

    result = vkBeginCommandBuffer(cmdBuf, &cmdBufInfo);

    assert(result == VK_SUCCESS);
}

// 커맨드 버퍼 레코딩 종료
void CommandBufferMgr::EndCommandBuffer(VkCommandBuffer commandBuffer)
{
    VkResult  result;
    result = vkEndCommandBuffer(commandBuffer);
    assert(result == VK_SUCCESS);
}

// 실행을 위해 커맨드 버퍼 제출
void CommandBufferMgr::SubmitCommandBuffer(const VkQueue& queue, const VkCommandBuffer* commandBuffer, const VkSubmitInfo* inSubmitInfo, const VkFence& fence)
{
    VkResult result;

    // 제출된 정보를 사용할 수 있으면 이를 사용한다.
    // 커맨드 버퍼 무시
    if (inSubmitInfo){
        result = vkQueueSubmit(queue, 1, inSubmitInfo, fence);
        assert(!result);

        result = vkQueueWaitIdle(queue);
        assert(!result);
        return;
    }

    //저출한 정보를 지정된 버퍼 명령으로 생성
    VkSubmitInfo submitInfo = {};
    submitInfo.sType				= VK_STRUCTURE_TYPE_SUBMIT_INFO;
    submitInfo.pNext				= NULL;
    submitInfo.waitSemaphoreCount	= 0;
    submitInfo.pWaitSemaphores		= NULL;
    submitInfo.pWaitDstStageMask	= NULL;
    submitInfo.commandBufferCount	= (uint32_t)sizeof(commandBuffer)/sizeof(VkCommandBuffer);
    submitInfo.pCommandBuffers		= commandBuffer;
    submitInfo.signalSemaphoreCount = 0;
    submitInfo.pSignalSemaphores	= NULL;

    result = vkQueueSubmit(queue, 1, &submitInfo, fence);
    assert(!result);

    result = vkQueueWaitIdle(queue);
}
