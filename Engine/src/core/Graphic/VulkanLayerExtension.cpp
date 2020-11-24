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

// 제공되는 확장판의 수를 얻기 위함
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

    // 각 레이어의 모든 확장판을 쿼리하고 이를 저장
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

// 입력으로 들어온 레이어 이름이 시스템에서 지원하는 레이어인지 점검
VkBool32 VulkanLayerAndExtension::AreLayersSupported(std::vector<const char *> &layerNames) {
    uint32_t checkCount = (uint32_t)layerNames.size();
    uint32_t layerCount = (uint32_t)layerPropertyList.size();
    std::vector<const char*> unsupportLayerNames;

    for (uint32_t i = 0; i < checkCount; i++) {
        VkBool32 isSupported = 0;
        for (uint32_t j = 0; j < layerCount; j++) {
            if (!strcmp(layerNames[i], layerPropertyList[j].properties.layerName)) {
                isSupported = 1;
            }
        }

        if (!isSupported) {
            std::cout << "No Layer support found, removed from layer: " << layerNames[i] << std::endl;
            unsupportLayerNames.push_back(layerNames[i]);
        }
        else {
            std::cout << "Layer supported: " << layerNames[i] << std::endl;
        }
    }

    for (auto i : unsupportLayerNames) {
        auto it = std::find(layerNames.begin(), layerNames.end(), i);
        if (it != layerNames.end()) layerNames.erase(it);
    }

    return true;
}

VkResult VulkanLayerAndExtension::CreateDebugReportCallback() {
    VkResult result;

    VulkanApplication* appObj	= VulkanApplication::GetInstance();
    VkInstance* instance		= &appObj->instanceObj.instance;

    // Get vkCreateDebugReportCallbackEXT API
    dbgCreateDebugReportCallback = (PFN_vkCreateDebugReportCallbackEXT)vkGetInstanceProcAddr(*instance, "vkCreateDebugReportCallbackEXT");
    if (!dbgCreateDebugReportCallback) {
        std::cout << "Error: GetInstanceProcAddr unable to locate vkCreateDebugReportCallbackEXT function." << std::endl;
        return VK_ERROR_INITIALIZATION_FAILED;
    }
    std::cout << "GetInstanceProcAddr loaded dbgCreateDebugReportCallback function\n";

    // Get vkDestroyDebugReportCallbackEXT API
    dbgDestroyDebugReportCallback = (PFN_vkDestroyDebugReportCallbackEXT)vkGetInstanceProcAddr(*instance, "vkDestroyDebugReportCallbackEXT");
    if (!dbgDestroyDebugReportCallback) {
        std::cout << "Error: GetInstanceProcAddr unable to locate vkDestroyDebugReportCallbackEXT function." << std::endl;
        return VK_ERROR_INITIALIZATION_FAILED;
    }
    std::cout << "GetInstanceProcAddr loaded dbgDestroyDebugReportCallback function\n";

    // 디버깅 보고서 제어 구조체를 정의하고, DebugFunction의 참조를 제공
    // 이 함수는 콘솔에 디버깅 정보 출력
    dbgReportCreateInfo.sType		= VK_STRUCTURE_TYPE_DEBUG_REPORT_CREATE_INFO_EXT;
    dbgReportCreateInfo.pfnCallback = DebugCallbackFunc;
    dbgReportCreateInfo.pUserData	= NULL;
    dbgReportCreateInfo.pNext		= NULL;
    dbgReportCreateInfo.flags		= VK_DEBUG_REPORT_WARNING_BIT_EXT |
                                       VK_DEBUG_REPORT_PERFORMANCE_WARNING_BIT_EXT |
                                       VK_DEBUG_REPORT_ERROR_BIT_EXT |
                                       VK_DEBUG_REPORT_DEBUG_BIT_EXT;

    // 디버깅 보고서의 콜백 함수를 생성하고 핸들을 debugReportCallback에 저장
    result = dbgCreateDebugReportCallback(*instance, &dbgReportCreateInfo, NULL, &debugReportCallback);
    if (result == VK_SUCCESS) {
        std::cout << "Debug report callback object created successfully\n";
    }
    return result;
}

void VulkanLayerAndExtension::DestroyDebugReportCallback() {
    VulkanApplication* appObj = VulkanApplication::GetInstance();
    VkInstance& instance	= appObj->instanceObj.instance;
    dbgDestroyDebugReportCallback(instance, debugReportCallback, NULL);
}

//가져온 디버깅 정보를 보고된 메시지와 함께 디버깅 정보의 유형을 설명한다.
VkBool32 VulkanLayerAndExtension::DebugCallbackFunc(VkFlags msgFlags, VkDebugReportObjectTypeEXT objType, uint64_t srcObject,
                                       size_t location, int32_t msgCode, const char *layerPrefix, const char *msg,
                                       void *userData) {
        if (msgFlags & VK_DEBUG_REPORT_ERROR_BIT_EXT) {
            std::cout << "[ VK_DEBUG_REPORT ] ERROR: [" << layerPrefix << "] Code" << msgCode << ":" << msg << std::endl;
        }
        else if (msgFlags & VK_DEBUG_REPORT_WARNING_BIT_EXT) {
            std::cout << "[ VK_DEBUG_REPORT ] WARNING: [" << layerPrefix << "] Code" << msgCode << ":" << msg << std::endl;
        }
        else if (msgFlags & VK_DEBUG_REPORT_INFORMATION_BIT_EXT) {
            std::cout << "[ VK_DEBUG_REPORT ] INFORMATION: [" << layerPrefix << "] Code" << msgCode << ":" << msg << std::endl;
        }
        else if (msgFlags & VK_DEBUG_REPORT_PERFORMANCE_WARNING_BIT_EXT) {
            std::cout << "[ VK_DEBUG_REPORT ] PERFORMANCE: [" << layerPrefix << "] Code" << msgCode << ":" << msg << std::endl;
        }
        else if (msgFlags & VK_DEBUG_REPORT_DEBUG_BIT_EXT) {
            std::cout << "[ VK_DEBUG_REPORT ] DEBUG: [" << layerPrefix << "] Code" << msgCode << ":" << msg << std::endl;
        }
        else {
            return VK_FALSE;
        }

        fflush(stdout);
        return VK_TRUE;
}
