//
// Created by EunwooSong on 2020-11-08.
//

#include "include/VulkanLayerExtension.h"
#include "include/VulkanApplication.h"
#include <iostream>

VulkanLayerAndExtension::VulkanLayerAndExtension() {

}

VulkanLayerAndExtension::~VulkanLayerAndExtension() {

}

VkResult VulkanLayerAndExtension::GetInstanceLayerProperties() {
    uint32_t						instanceLayerCount;		// 인스턴스 레이어의 수 저장
    std::vector<VkLayerProperties>	layerProperties;		// 레이어 속성을 저장하기 위한 벡터
    VkResult						result;					// Vulkan API 명령의 결과 상태를 점검

    // 모든 레이어 쿼리
    do {
        result = vkEnumerateInstanceLayerProperties(&instanceLayerCount, NULL);

        if (result)
            return result;

        if (instanceLayerCount == 0)
            return VK_INCOMPLETE;

        layerProperties.resize(instanceLayerCount);
        result = vkEnumerateInstanceLayerProperties(&instanceLayerCount, layerProperties.data());
    } while (result == VK_INCOMPLETE);

    // 각 레이어에 대한 모든 확장판을 쿼리하고 이를 저장
    std::cout << "\nInstanced Layers" << std::endl;
    std::cout << "===================" << std::endl;
    for (auto globalLayerProp: layerProperties) {
        // 레이어 이름과 설명을 출력
        std::cout <<"\n"<< globalLayerProp.description <<"\n\t|\n\t|---[Layer Name]--> " << globalLayerProp.layerName <<"\n";

        LayerProperties layerProps;
        layerProps.properties = globalLayerProp;

        // 해당 레이어 속성을 위한 인스턴스 레벨 확장판을 가져옴
        result = GetExtensionProperties(layerProps);

        if (result){
            continue;
        }

        layerPropertyList.push_back(layerProps);
        // 각 인스턴스 레이어에 대한 확장판 이름을 출력
        for (auto j : layerProps.extensions) {
            std::cout << "\t\t|\n\t\t|---[Layer Extension]--> " << j.extensionName << "\n";
        }
    }
    return result;
}

//제공되는 확장판의 수를 얻기 위함
// 이 함수는 확장판과 확장판의 속성을 인스턴스와 장치 레벨에서 가져온다
// 유효한 장치 포인터를 보내 장치 레벨의 확장을 가져오거나, NULL을 사용해 인스턴스 레벨의 확장판을 특정해 가져온다
VkResult VulkanLayerAndExtension::GetExtensionProperties(LayerProperties &layerProps, VkPhysicalDevice *gpu) {
    uint32_t	extensionCount;
    VkResult	result;
    char*		layerName = layerProps.properties.layerName;

    do {
        // Layer의 확장판의 총 수를 가져온다
        if(gpu)
            result = vkEnumerateDeviceExtensionProperties(*gpu, layerName, &extensionCount, NULL);
        else
            result = vkEnumerateInstanceExtensionProperties(layerName, &extensionCount, NULL);

        if (result || extensionCount == 0)
            continue;

        layerProps.extensions.resize(extensionCount);

        // 모든 호가장판의 속성을 수집한다.
        if (gpu)
            result = vkEnumerateDeviceExtensionProperties(*gpu, layerName, &extensionCount, layerProps.extensions.data());
        else
            result = vkEnumerateInstanceExtensionProperties(layerName, &extensionCount, layerProps.extensions.data());
    } while (result == VK_INCOMPLETE);

    return result;
}

VkResult VulkanLayerAndExtension::GetDeviceExtensionProperties(VkPhysicalDevice *gpu) {
    VkResult						result;					// Variable to check Vulkan API result status

    // Query all the extensions for each layer and store it.
    std::cout << "Device extensions" << std::endl;
    std::cout << "===================" << std::endl;
    VulkanApplication* appObj = VulkanApplication::GetInstance();
    std::vector<LayerProperties>* instanceLayerProp = &appObj->GetInstance()->instanceObj.layerExtension.layerPropertyList;
    for (auto globalLayerProp : *instanceLayerProp) {
        LayerProperties layerProps;
        layerProps.properties = globalLayerProp.properties;

        if (result = GetExtensionProperties(layerProps, gpu))
            continue;

        std::cout << "\n" << globalLayerProp.properties.description << "\n\t|\n\t|---[Layer Name]--> " << globalLayerProp.properties.layerName << "\n";
        layerPropertyList.push_back(layerProps);

        if (layerProps.extensions.size()) {
            for (auto j : layerProps.extensions) {
                std::cout << "\t\t|\n\t\t|---[Device Extesion]--> " << j.extensionName << "\n";
            }
        }
        else {
            std::cout << "\t\t|\n\t\t|---[Device Extesion]--> No extension found \n";
        }
    }
    return result;
}
