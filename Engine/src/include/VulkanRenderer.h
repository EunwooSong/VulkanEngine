//
// Created by EunwooSong on 2020-11-08.
//

#ifndef ENGINE_VULKANRENDERER_H
#define ENGINE_VULKANRENDERER_H

#include "VulkanInclude.h"
#include "VulkanSwapChain.h"

#define NUM_SAMPLES VK_SAMPLE_COUNT_1_BIT

//커맨드 풀 - 응용프로그램이 장치와 통신하기 위한 정보
class VulkanRenderer {
public:
    VulkanRenderer(VulkanApplication* app, VulkanDevice* device);
    ~VulkanRenderer();

    void Initialize();
    void Prepare();
    void Update();
    bool Render();

    //빈 윈도우 생성
    void CreatePresentationWindow();
    static void FramebufferResizeCallback(GLFWwindow* window, int width, int height);
    void SetImageLayout(VkImage image,
                        VkImageAspectFlags aspectMask,
                        VkImageLayout oldImageLayout,
                        VkImageLayout newImageLayout,
                        VkAccessFlagBits srcAccessMask,
                        const VkCommandBuffer& cmdBuf);

    void CreateCommandPool();               // 커맨드 풀 생성
    void BuildSwapChainAndDepthImage();     // 스와프 체인과 깊이 이미지를 생성하기 위한 시작점
    void CreateDepthImage();                // 깊이 이미지 생성

    void DestroyPresentationWindow();

    void DestroyCommandBuffer();
    void DestroyCommandPool();
    void DestroyDepthBuffer();

    inline VulkanApplication*   GetApplication()    { return appObj; }
    inline VulkanDevice*        GetDevice()         { return deviceObj; }
    inline VulkanSwapChain*     GetSwapChain()      { return swapChainObj; }
    inline GLFWwindow*          GetWindow()         { return window; }

    // 깊이 이미지에 사용할 데이터 구조체
    struct{
        VkFormat		format;
        VkImage			image;
        VkDeviceMemory	mem;
        VkImageView		view;
    } Depth;

    VkCommandBuffer cmdDepthImage;      // 깊이 이미지 커맨드 버퍼
    VkCommandPool   cmdPool;            // 커맨드 풀
    int width, height;

private:
    // 실제 화면
    GLFWwindow* window;

    //=---- 클래스 관리 ----=//
    VulkanSwapChain*    swapChainObj;

    // 이 프레젠테이션 레이어와 연결될 장치 개체
    VulkanApplication*  appObj;
    VulkanDevice*       deviceObj;
};


#endif //ENGINE_VULKANRENDERER_H
