//
// Created by EunwooSong on 2020-11-08.
//

#include "include/stdafx.h"
#include "include/VulkanApplication.h"
#include "include/EngineAttribute.h"

std::unique_ptr<VulkanApplication> VulkanApplication::instance;
std::once_flag VulkanApplication::onlyOnce;

extern std::vector<const char *> instanceExtensionNames;
extern std::vector<const char *> layerNames;
extern std::vector<const char *> deviceExtensionNames;

VulkanApplication::VulkanApplication()
{
    // At application start up, enumerate instance layers
    instanceObj.layerExtension.GetInstanceLayerProperties();

    deviceObj = NULL;
    rendererObj = NULL;
}

VulkanApplication::~VulkanApplication()
{
    SAFE_DELETE(rendererObj);
}

VulkanApplication* VulkanApplication::GetInstance(){
    std::call_once(onlyOnce, [](){instance.reset(new VulkanApplication()); });
    return instance.get();
}

VkResult VulkanApplication::CreateVulkanInstance( std::vector<const char *>& layers, std::vector<const char *>& extensionNames, const char* applicationName)
{
    return instanceObj.CreateInstance(layers, extensionNames, applicationName);
}

VkResult VulkanApplication::HandShakeWithDevice(VkPhysicalDevice* gpu, std::vector<const char *>& layers, std::vector<const char *>& extensions )
{

    // 이를 통해 물리적 장치와 논리적 장치, 장치의 큐와 속성을 관리한다.
    deviceObj = new VulkanDevice(gpu);
    if (!deviceObj){
        return VK_ERROR_OUT_OF_HOST_MEMORY;
    }

    // 장치에서 가용한 레이어와 레이어의 확장판을 출력
    deviceObj->layerExtension.GetDeviceExtensionProperties(gpu);

    // 물리적 장치 또는 GPU 속성을 가져옴
    vkGetPhysicalDeviceProperties(*gpu, &deviceObj->gpuProps);

    // 물리적 자치 또는 GPU에서 메모리 속성을 가져옴
    vkGetPhysicalDeviceMemoryProperties(*gpu, &deviceObj->memoryProperties);

    // 물리적 장치의 가용한 큐와 그 속성을 쿼리
    deviceObj->GetPhysicalDeviceQueuesAndProperties();

    // 그래픽스 파이프라인을 지원하는 큐를 가져옴
    deviceObj->GetGraphicsQueueHandle();

    // 논리적 장치를 생성하고 이를 확인하기 위해 그래픽스 큐와 연결함
    return deviceObj->CreateDevice(layers, extensions);
}

// 실제 장착된 물리적 장치의 수를 가져옴
VkResult VulkanApplication::EnumeratePhysicalDevices(std::vector<VkPhysicalDevice>& gpuList)
{
    //GPU의 수 보관
    uint32_t gpuDeviceCount;

    //GPU의 수 가져옴
    VkResult result = vkEnumeratePhysicalDevices(instanceObj.instance, &gpuDeviceCount, NULL);
    assert(result == VK_SUCCESS);

    assert(gpuDeviceCount);

    //가져오기 위한 공간 확보
    gpuList.resize(gpuDeviceCount);

    //물리적 장치 개체를 가져옴
    result = vkEnumeratePhysicalDevices(instanceObj.instance, &gpuDeviceCount, gpuList.data());
    assert(result == VK_SUCCESS);

    return result;
}

//레이어 열걸르 위한 생성자 응용 프로그램
void VulkanApplication::Initialize()
{
    char title[] = "Hello World!!!";

    // 지원하는지 확인
    if(EngineAttribute::DEBUG)
        instanceObj.layerExtension.AreLayersSupported(layerNames);

    // Vulkan 인스턴스를 지정한 레이어와 확장판 이름으로 생성
    CreateVulkanInstance(layerNames, instanceExtensionNames, title);

    // 디버깅 콜백 생성
    if(EngineAttribute::DEBUG)
        instanceObj.layerExtension.CreateDebugReportCallback();

    // 시스템의 물리적 장치 목록을 가져옴
    std::vector<VkPhysicalDevice> gpuList;
    EnumeratePhysicalDevices(gpuList);

    // 먼저 사용 가능한 하나의 장치만 사용
    if (gpuList.size() > 0) {
        HandShakeWithDevice(&gpuList[0], layerNames, deviceExtensionNames);
    }

    rendererObj = new VulkanRenderer(this, deviceObj);

    rendererObj->Initialize();
}

bool VulkanApplication::Render() {
    return rendererObj->Render();
}

void VulkanApplication::Release() {
    rendererObj->DestroyDepthBuffer();
    rendererObj->GetSwapChain()->DestroySwapChain();
    rendererObj->DestroyCommandBuffer();
    rendererObj->DestroyCommandPool();
    rendererObj->DestroyPresentationWindow();
    deviceObj->DestroyDevice();
    if (EngineAttribute::DEBUG) {
        instanceObj.layerExtension.DestroyDebugReportCallback();
    }
    instanceObj.DestroyInstance();
}
