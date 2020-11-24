//
// Created by EunwooSong on 2020-11-08.
//

#include "include/stdafx.h"
#include "include/VulkanRenderer.h"
#include "include/EngineAttribute.h"
#include "include/VulkanApplication.h"
#include "include/VulkanWrappers.h"

VulkanRenderer::VulkanRenderer(VulkanApplication *app, VulkanDevice *device) {

    appObj = app;
    deviceObj	= device;

    swapChainObj = new VulkanSwapChain(this);
}

VulkanRenderer::~VulkanRenderer() {
    SAFE_DELETE(swapChainObj);
}


void VulkanRenderer::CreatePresentationWindow() {
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
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    CreatePresentationWindow();

    swapChainObj->InitializeSwapChain();

    CreateCommandPool();

    BuildSwapChainAndDepthImage();
}

void VulkanRenderer::Prepare() {

}

void VulkanRenderer::Update() {

}

bool VulkanRenderer::Render() {
    return true;
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
            // 이 이미지로부터의 모든 복사가 완료된 것을 보장한다.
            // 이 레이이아웃의 이미지는 명령의 대상으로만 사용할 수 있다(Destination)
        case VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL:
        case VK_IMAGE_LAYOUT_PRESENT_SRC_KHR:
            imgMemoryBarrier.dstAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
            break;

            // 이 이미지로의 복사 또는 CPU 쓰기 작업이 완료된 것을 보장한다.
            // 이 레이아웃의 이미지는 읽기 전용 셰이더 리소스로만 사용할 수 있다.
        case VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL:
            imgMemoryBarrier.srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
            imgMemoryBarrier.dstAccessMask = VK_ACCESS_SHADER_READ_BIT;
            break;

            // 이 레이아웃의 이미지는 프레임 버퍼의 생상 첨부로만 사용할 수 있다.
        case VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL:
            imgMemoryBarrier.dstAccessMask = VK_ACCESS_COLOR_ATTACHMENT_READ_BIT;
            break;

            // 이 레이아웃의 이미지는 프레임 버퍼의 깊이 / 스텐실 첨부에만 사용할 수 있다.
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
    swapChainObj->CreateSwapChain(cmdDepthImage);

    // 깊이 이미지 생성
    CreateDepthImage();
}

void VulkanRenderer::CreateDepthImage() {
    VkResult  result;
    bool  pass;

    VkImageCreateInfo imageInfo = {};

    //깊이 포맷이 정의되지 않은 경우 16bit 값을 사용함
    if (Depth.format == VK_FORMAT_UNDEFINED) {
        Depth.format = VK_FORMAT_D16_UNORM;
    }

    const VkFormat depthFormat = Depth.format;

    VkFormatProperties props;
    vkGetPhysicalDeviceFormatProperties(*deviceObj->gpu, depthFormat, &props);
    if (props.optimalTilingFeatures & VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT) {
        imageInfo.tiling = VK_IMAGE_TILING_OPTIMAL;
    }
    else if (props.linearTilingFeatures & VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT) {
        imageInfo.tiling = VK_IMAGE_TILING_LINEAR;
    }
    else {
        std::cout << "Unsupported Depth Format, try other Depth formats.\n";
        exit(-1);
    }

    imageInfo.sType			= VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
    imageInfo.pNext			= NULL;
    imageInfo.imageType		= VK_IMAGE_TYPE_2D;
    imageInfo.format		= depthFormat;
    imageInfo.extent.width	= width;
    imageInfo.extent.height = height;
    imageInfo.extent.depth	= 1;
    imageInfo.mipLevels		= 1;
    imageInfo.arrayLayers	= 1;
    imageInfo.samples		= NUM_SAMPLES;
    imageInfo.queueFamilyIndexCount = 0;
    imageInfo.pQueueFamilyIndices	= NULL;
    imageInfo.sharingMode			= VK_SHARING_MODE_EXCLUSIVE;
    imageInfo.usage					= VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT;
    imageInfo.flags					= 0;

    // 사용자가 이미지 정보와 이미지 개체를 생성
    result = vkCreateImage(deviceObj->device, &imageInfo, NULL, &Depth.image);
    assert(result == VK_SUCCESS);

    // 이미지 메모리의 요구사항 가져오기
    VkMemoryRequirements memRqrmnt;
    vkGetImageMemoryRequirements(deviceObj->device,	Depth.image, &memRqrmnt);

    VkMemoryAllocateInfo memAlloc = {};
    memAlloc.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    memAlloc.pNext = NULL;
    memAlloc.allocationSize = 0;
    memAlloc.memoryTypeIndex = 0;
    memAlloc.allocationSize = memRqrmnt.size;
    // 메모리 속성에 따라 메모리 유형을 결정함
    pass = deviceObj->MemoryTypeFromProperties(memRqrmnt.memoryTypeBits, 0, /* No requirements */ &memAlloc.memoryTypeIndex);
    assert(pass);

    // 물리적 메모리를 깊이 이미지로 할장
    result = vkAllocateMemory(deviceObj->device, &memAlloc, NULL, &Depth.mem);
    assert(result == VK_SUCCESS);

    // 깊이 이미지로 할당된 메모리를 바인딩
    result = vkBindImageMemory(deviceObj->device, Depth.image, Depth.mem, 0);
    assert(result == VK_SUCCESS);


    VkImageViewCreateInfo imgViewInfo = {};
    imgViewInfo.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
    imgViewInfo.pNext = NULL;
    imgViewInfo.image = VK_NULL_HANDLE;
    imgViewInfo.format = depthFormat;
    imgViewInfo.components = { VK_COMPONENT_SWIZZLE_IDENTITY };
    imgViewInfo.subresourceRange.aspectMask = VK_IMAGE_ASPECT_DEPTH_BIT;
    imgViewInfo.subresourceRange.baseMipLevel = 0;
    imgViewInfo.subresourceRange.levelCount = 1;
    imgViewInfo.subresourceRange.baseArrayLayer = 0;
    imgViewInfo.subresourceRange.layerCount = 1;
    imgViewInfo.viewType = VK_IMAGE_VIEW_TYPE_2D;
    imgViewInfo.flags = 0;

    if (depthFormat == VK_FORMAT_D16_UNORM_S8_UINT ||
        depthFormat == VK_FORMAT_D24_UNORM_S8_UINT ||
        depthFormat == VK_FORMAT_D32_SFLOAT_S8_UINT) {
        imgViewInfo.subresourceRange.aspectMask |= VK_IMAGE_ASPECT_STENCIL_BIT;
    }

    // 커맨드 버퍼를 이용해 깊이 이미지 생성
    // 여기에는 커맨드 버퍼 할당, 레코딩의 시작/종료 위치와 제출이 포함됨
    CommandBufferMgr::AllocCommandBuffer(&deviceObj->device, cmdPool, &cmdDepthImage);
    CommandBufferMgr::BeginCommandBuffer(cmdDepthImage);
    {
        //깊이 스텐실 이미지 레이아웃을 optimal로 설정
        SetImageLayout(Depth.image,
                       imgViewInfo.subresourceRange.aspectMask,
                       VK_IMAGE_LAYOUT_UNDEFINED,
                       VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL, (VkAccessFlagBits)0, cmdDepthImage);
    }
    CommandBufferMgr::EndCommandBuffer(cmdDepthImage);
    CommandBufferMgr::SubmitCommandBuffer(deviceObj->queue, &cmdDepthImage);

    // 이미지 뷰를 생성하고 응용 프로그램이 사용할 수 있도록 허용함
    imgViewInfo.image = Depth.image;
    result = vkCreateImageView(deviceObj->device, &imgViewInfo, NULL, &Depth.view);
    assert(result == VK_SUCCESS);
}

void VulkanRenderer::DestroyPresentationWindow() {
    glfwDestroyWindow(window);
}

void VulkanRenderer::DestroyCommandBuffer() {
    VkCommandBuffer cmdBufs[] = { cmdDepthImage };
    vkFreeCommandBuffers(deviceObj->device, cmdPool, sizeof(cmdBufs)/sizeof(VkCommandBuffer), cmdBufs);
}

void VulkanRenderer::DestroyCommandPool() {
    VulkanDevice* deviceObj		= appObj->deviceObj;

    vkDestroyCommandPool(deviceObj->device, cmdPool, NULL);
}

void VulkanRenderer::DestroyDepthBuffer() {
    vkDestroyImageView(deviceObj->device, Depth.view, NULL);
    vkDestroyImage(deviceObj->device, Depth.image, NULL);
    vkFreeMemory(deviceObj->device, Depth.mem, NULL);
}
