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

struct SwapChainPrivateVariables
{
    // 이미지 화면의 기능 저장
    VkSurfaceCapabilitiesKHR	    surfCapabilities;

    // 프레젠테이션 모드의 수 저장
    uint32_t					    presentModeCount;

    // 프레젠테이션 모드를 가져올 배열
    std::vector<VkPresentModeKHR>   presentModes;

    //스와프 체인 색상 이미지의 크기
    VkExtent2D					    swapChainExtent;

    // 지원되는 색상 이미지의 수
    uint32_t					    desiredNumberOfSwapChainImages;
    VkSurfaceTransformFlagBitsKHR   preTransform;

    // 스와프 체인 생성을 위한 프레젠테이션 모드의 비트 플래그 저장
    VkPresentModeKHR			    swapchainPresentMode;

    // 가져온 드로잉 생상 스와프 체인 이미지들
    std::vector<VkImage>		    swapchainImages;

    std::vector<VkSurfaceFormatKHR> surfFormats;
};

struct SwapChainPublicVariables
{
    // 플랫폼에 따른 화면 개체
    VkSurfaceKHR surface;

    // 스와프 체인에 사용될 버퍼 이미지의 수
    uint32_t swapchainImageCount;

    // 스와프 체인 개체
    VkSwapchainKHR swapChain;

    // 현재 사용 중인 드로잉 화면의 인덱스
    std::vector<SwapChainBuffer> colorBuffer;
    VkSemaphore presentCompleteSemaphore;
    uint32_t currentColorBuffer;

    // 이미지 포맷
    VkFormat format;
};

class VulkanSwapChain {
    // Public
public:

    explicit VulkanSwapChain(VulkanRenderer* renderer);
    ~VulkanSwapChain();
    void InitializeSwapChain();
    void CreateSwapChain(const VkCommandBuffer& cmd);
    void DestroySwapChain();

    SwapChainPublicVariables	scPublicVars;
    PFN_vkQueuePresentKHR		fpQueuePresentKHR;
    PFN_vkAcquireNextImageKHR	fpAcquireNextImageKHR;

    // Private
private:
    VkResult CreateSwapChainExtensions();
    void GetSupportedFormats();
    VkResult CreateSurface();
    uint32_t GetGraphicsQueueWithPresentationSupport();
    void GetSurfaceCapabilitiesAndPresentMode();
    void ManagePresentMode();
    void CreateSwapChainColorImages();
    void CreateColorImageView(const VkCommandBuffer& cmd);

    // Private member variables
private:
    PFN_vkGetPhysicalDeviceSurfaceSupportKHR		fpGetPhysicalDeviceSurfaceSupportKHR;
    PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR	fpGetPhysicalDeviceSurfaceCapabilitiesKHR;
    PFN_vkGetPhysicalDeviceSurfaceFormatsKHR		fpGetPhysicalDeviceSurfaceFormatsKHR;
    PFN_vkGetPhysicalDeviceSurfacePresentModesKHR	fpGetPhysicalDeviceSurfacePresentModesKHR;
    PFN_vkDestroySurfaceKHR							fpDestroySurfaceKHR;

    // Layer Extensions Debugging
    PFN_vkCreateSwapchainKHR	fpCreateSwapchainKHR;
    PFN_vkDestroySwapchainKHR	fpDestroySwapchainKHR;
    PFN_vkGetSwapchainImagesKHR fpGetSwapchainImagesKHR;

    SwapChainPrivateVariables	scPrivateVars;
    VulkanRenderer*				rendererObj;	// parent
    VulkanApplication*			appObj;
};


#endif //ENGINE_VULKANSWAPCHAIN_H
