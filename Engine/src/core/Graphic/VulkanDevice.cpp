//
// Created by EunwooSong on 2020-11-08.
//

#include "include/VulkanDevice.h"
#include "include/VulkanApplication.h"

VulkanDevice::VulkanDevice(VkPhysicalDevice* physicalDevice)
{
    gpu = physicalDevice;
}

VulkanDevice::~VulkanDevice()
{
}

// 논리적 장치 개체를 만드는 데 도움
VkResult VulkanDevice::CreateDevice(std::vector<const char *>& layers, std::vector<const char *>& extensions)
{
    layerExtension.appRequestedLayerNames		= layers;
    layerExtension.appRequestedExtensionNames	= extensions;

    VkResult result;
    float queuePriorities[1]			= { 0.0 };

    // 개체 정보의 생성
    VkDeviceQueueCreateInfo queueInfo	= {};
    queueInfo.queueFamilyIndex			= graphicsQueueIndex;
    queueInfo.sType						= VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
    queueInfo.pNext						= NULL;
    queueInfo.queueCount				= 1;
    queueInfo.pQueuePriorities			= queuePriorities;

    VkDeviceCreateInfo deviceInfo		= {};
    deviceInfo.sType					= VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
    deviceInfo.pNext					= NULL;
    deviceInfo.queueCreateInfoCount		= 1;
    deviceInfo.pQueueCreateInfos		= &queueInfo;
    deviceInfo.enabledLayerCount		= 0;

    //장치 레이어 사용 X
    deviceInfo.ppEnabledLayerNames		= NULL;											// Device layers are deprecated
    deviceInfo.enabledExtensionCount	= (uint32_t)extensions.size();
    deviceInfo.ppEnabledExtensionNames	= extensions.size() ? extensions.data() : NULL;
    deviceInfo.pEnabledFeatures			= NULL;

    result = vkCreateDevice(*gpu, &deviceInfo, NULL, &device);
    assert(result == VK_SUCCESS);

    return result;
}

void VulkanDevice::GetPhysicalDeviceQueuesAndProperties() {
    // 두 번째 파라미터를 NULL로 해서 큐 패밀리의 수를 쿼리
    vkGetPhysicalDeviceQueueFamilyProperties(*gpu, &queueFamilyCount, NULL);

    // 큐 속성을 저장할 공간 할당
    queueFamilyProps.resize(queueFamilyCount);

    // 큐 패밀리 속성을 가져옴
    vkGetPhysicalDeviceQueueFamilyProperties(*gpu, &queueFamilyCount, queueFamilyProps.data());

}

// 논리적 장치 개체를 생성하려면 유효한 큐 핸들이 필요하며, 이를 이용해
// 연고나된 큐를 생성하게 된다. 이를 위해 쿼리된 모든 패밀리 속성을 반복해서
// VkQueueFamilyProperties::queueFlags 비트 정보를 확인해 해당 큐를 찾는다.
uint32_t VulkanDevice::GetGraphicsQueueHandle() {
    bool found = false;

    // 물리적 장치에서 지원하는 큐의 수만큼 반복
    for (unsigned int i = 0; i < queueFamilyCount; i++){
        // 그래픽스 큐 유형을 가져옴

        if (queueFamilyProps[i].queueFlags & VK_QUEUE_GRAPHICS_BIT){
            // 그래픽스 큐 패밀리의 핸들/인덱스 ID를 가져윰
            found				= true;
            graphicsQueueIndex	= i;
            break;
        }
    }

    // 아무것도 찾지 못하면 버그다 버그 디그다
    assert(found);

    return 0;
}

void VulkanDevice::DestroyDevice() {
    vkDestroyDevice(device, NULL);
}

bool VulkanDevice::MemoryTypeFromProperties(uint32_t typeBits, VkFlags requirements_mask, uint32_t *typeIndex) {
    // 이들 속성의 첫 번째 인덱스를 찾기 위해 memtypes 검색
    for (uint32_t i = 0; i < 32; i++) {
        if ((typeBits & 1) == 1) {
            // 유형이 사용 가능할 경우 사용자 속성과 일치하는가?
            if ((memoryProperties.memoryTypes[i].propertyFlags & requirements_mask) == requirements_mask) {
                *typeIndex = i;
                return true;
            }
        }
        typeBits >>= 1;
    }
    // 일치하는 메모리 유형이 없음, 실패 반환
    return false;
}

void VulkanDevice::GetDeviceQueue() {
    vkGetDeviceQueue(device, graphicsQueueWithPresentIndex, 0, &queue);
}
