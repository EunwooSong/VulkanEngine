//
// Created by EunwooSong on 2020-11-08.
//

#ifndef ENGINE_VULKANDEVICE_H
#define ENGINE_VULKANDEVICE_H

#include "VulkanLayerExtension.h"

/*
 * 시스템의 실제 컴퓨팅 장치, gpu를 연결
 */

/*
 * Queue는 응용 프로그램과 물리적 장치가 통신하는 수단이다.
 * 응용 프로그램은 큐에 커맨드 버퍼를 제출하는 형식으로 원하는
 * 작업을 시키고, 이 작업을 물리적 장치가 읽어 비동기적으로 처리
 * */
class VulkanDevice {
public:
    explicit VulkanDevice(VkPhysicalDevice* gpu);
    ~VulkanDevice();

    //
    VkResult CreateDevice(std::vector<const char *>& layers, std::vector<const char *>& extensions);
    void DestroyDevice();
    void GetPhysicalDeviceQueuesAndProperties();
    uint32_t GetGraphicsQueueHandle();

public:
    VkDevice							device;		// Logical device
    VkPhysicalDevice*					gpu;		// Physical device
    VkPhysicalDeviceProperties			gpuProps;	// Physical device attributes
    VkPhysicalDeviceMemoryProperties	memoryProperties;

    VkQueue									queue;							// 큐 개체
    std::vector<VkQueueFamilyProperties>	queueFamilyProps;				// 물리적 장치에 의해 공개된 모든 큐 페밀리를 저장
    uint32_t								graphicsQueueIndex;				// 그래픽스 큐의 인덱스를 저장
    uint32_t								graphicsQueueWithPresentIndex;  // 장치 지정 확장판
    uint32_t								queueFamilyCount;				// 장치에 의해 공개된 큐 패밀리의 수

    // 장치 지정 확장판
    VulkanLayerAndExtension		layerExtension;
};


#endif //ENGINE_VULKANDEVICE_H
