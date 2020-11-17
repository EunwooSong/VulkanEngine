//
// Created by EunwooSong on 2020-11-08.
//

#include "include/VulkanRenderer.h"
#include "include/EngineAttribute.h"
#include "include/VulkanApplication.h"


void VulkanRenderer::CreatePresentationWindow() {
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window = glfwCreateWindow(
            EngineAttribute::SCREEN_WIDTH,
            EngineAttribute::SCREEN_HEIGHT,
            EngineAttribute::APPLICATION_NAME,
            nullptr, nullptr);
    glfwSetWindowUserPointer(window, this);
    glfwSetFramebufferSizeCallback(window, FramebufferResizeCallback);
}

void VulkanRenderer::FramebufferResizeCallback(GLFWwindow *window, int width, int height) {
    VulkanApplication* appObj = VulkanApplication::GetInstance();
    std::cout << "[ GLFW ] Resize Window (w, h) : " << width << ',' << height << std::endl;
}

void VulkanRenderer::Initialize() {
    CreatePresentationWindow();
    swapChainObj->InitializeSwapChain();
    CreateCommandPool();
    BuildSwapChainAndDepthImage();
}

void VulkanRenderer::SetImageLayout(VkImage image, VkImageAspectFlags aspectMask, VkImageLayout oldImageLayout,
                                    VkImageLayout newImageLayout, VkAccessFlagBits srcAccessMask,
                                    VkCommandBuffer const &cmd) {
    // Dependency on cmd
    assert(cmd != VK_NULL_HANDLE);

    // The deviceObj->queue must be initialized
    assert(deviceObj->queue != VK_NULL_HANDLE);

    VkImageMemoryBarrier imgMemoryBarrier = {};
    imgMemoryBarrier.sType			= VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
    imgMemoryBarrier.pNext			= NULL;
    imgMemoryBarrier.srcAccessMask	= srcAccessMask;
    imgMemoryBarrier.dstAccessMask	= 0;
    imgMemoryBarrier.oldLayout		= oldImageLayout;
    imgMemoryBarrier.newLayout		= newImageLayout;
    imgMemoryBarrier.image			= image;
    imgMemoryBarrier.subresourceRange.aspectMask	= aspectMask;
    imgMemoryBarrier.subresourceRange.baseMipLevel	= 0;
    imgMemoryBarrier.subresourceRange.levelCount	= 1;
    imgMemoryBarrier.subresourceRange.layerCount	= 1;

    if (oldImageLayout == VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL) {
        imgMemoryBarrier.srcAccessMask = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;
    }

    switch (newImageLayout)
    {
        // Ensure that anything that was copying from this image has completed
        // An image in this layout can only be used as the destination operand of the commands
        case VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL:
        case VK_IMAGE_LAYOUT_PRESENT_SRC_KHR:
            imgMemoryBarrier.dstAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
            break;

            // Ensure any Copy or CPU writes to image are flushed
            // An image in this layout can only be used as a read-only shader resource
        case VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL:
            imgMemoryBarrier.srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
            imgMemoryBarrier.dstAccessMask = VK_ACCESS_SHADER_READ_BIT;
            break;

            // An image in this layout can only be used as a framebuffer color attachment
        case VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL:
            imgMemoryBarrier.dstAccessMask = VK_ACCESS_COLOR_ATTACHMENT_READ_BIT;
            break;

            // An image in this layout can only be used as a framebuffer depth/stencil attachment
        case VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL:
            imgMemoryBarrier.dstAccessMask = VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT;
            break;
    }

    VkPipelineStageFlags srcStages	= VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT;
    VkPipelineStageFlags destStages = VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT;

    vkCmdPipelineBarrier(cmd, srcStages, destStages, 0, 0, NULL, 0, NULL, 1, &imgMemoryBarrier);
}

void VulkanRenderer::CreateCommandPool() {
    VulkanDevice* deviceObj		= appObj->deviceObj;
    VkResult  res;

    VkCommandPoolCreateInfo cmdPoolInfo = {};
    cmdPoolInfo.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
    cmdPoolInfo.pNext = NULL;
    cmdPoolInfo.queueFamilyIndex = deviceObj->graphicsQueueWithPresentIndex;
    cmdPoolInfo.flags = 0;

    res = vkCreateCommandPool(deviceObj->device, &cmdPoolInfo, NULL, &cmdPool);
    assert(res == VK_SUCCESS);
}

void VulkanRenderer::BuildSwapChainAndDepthImage() {
    // 커맨드를 제출할 적절한 큐 가져오기
    deviceObj->GetDeviceQueue();

    // 스와프 체인을 생성하고 색상 이미지 가져오기
    swapChainObj->CreateSwapChainDepthImage();

    // 깊이 이미지 생성
    CreateDepthImage();
}
