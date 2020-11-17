//
// Created by EunwooSong on 2020-11-08.
//

#ifndef ENGINE_VULKANSWAPCHAIN_H
#define ENGINE_VULKANSWAPCHAIN_H

#include "VulkanInclude.h"

class VulkanInstance;
class VulkanDevice;
class VulkanRenderer;
class VulkanApplication;


struct SwapChainBuffer {
    VkImage image;
    VkImageView view;
};

//스와프 체인의 private과 public 함수가 사용하는 private 변수들
struct SwapChainPrivateVariables
{
    // Store the image surface capabilities
    VkSurfaceCapabilitiesKHR	surfCapabilities;

    // Stores the number of present mode support by the implementation
    uint32_t					presentModeCount;

    // Arrays for retrived present modes
    std::vector<VkPresentModeKHR> presentModes;

    // Size of the swap chain color images
    VkExtent2D					swapChainExtent;

    // Number of color images supported by the implementation
    uint32_t					desiredNumberOfSwapChainImages;

    VkSurfaceTransformFlagBitsKHR preTransform;

    // Stores present mode bitwise flag for the creation of swap chain
    VkPresentModeKHR			swapchainPresentMode;

    // The retrived drawing color swap chain images
    std::vector<VkImage>		swapchainImages;

    std::vector<VkSurfaceFormatKHR> surfFormats;
};

//스와프 체인의 private과 public 함수가 사용하는 public 변수들
struct SwapChainPublicVariables
{
    // The logical platform dependent surface object
    VkSurfaceKHR surface;

    // Number of buffer image used for swap chain
    uint32_t swapchainImageCount;

    // Swap chain object
    VkSwapchainKHR swapChain;

    // List of color swap chain images
    std::vector<SwapChainBuffer> colorBuffer;

    // Semaphore for sync purpose
    VkSemaphore presentCompleteSemaphore;

    // Current drawing surface index in use
    uint32_t currentColorBuffer;

    // Format of the image
    VkFormat format;
};

class VulkanSwapChain {
    // Public
public:
    VulkanSwapChain(VulkanRenderer* renderer);
    ~VulkanSwapChain();
    void intializeSwapChain();
    void createSwapChain(const VkCommandBuffer& cmd);
    void destroySwapChain();
};


#endif //ENGINE_VULKANSWAPCHAIN_H
