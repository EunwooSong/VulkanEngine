//
// Created by EunwooSong on 2020-11-08.
//

#ifndef ENGINE_VULKANLAYEREXTENSION_H
#define ENGINE_VULKANLAYEREXTENSION_H

#include "VulkanInclude.h"
#include <vector>

//Notion

struct LayerProperties {
    VkLayerProperties properties;
    std::vector<VkExtensionProperties> extensions;
};

class VulkanLayerAndExtension {
public:
    VulkanLayerAndExtension();
    ~VulkanLayerAndExtension();

    VkResult GetInstanceLayerProperties();
    VkResult GetExtensionProperties(LayerProperties& layerProps, VkPhysicalDevice* gpu = nullptr);
    VkResult GetDeviceExtensionProperties(VkPhysicalDevice* gpu);

    VkBool32 AreLayersSupported(std::vector<const char *> &layerNames);

    VkResult CreateDebugReportCallback();

    void	DestroyDebugReportCallback();

    static VKAPI_ATTR VkBool32 VKAPI_CALL DebugCallbackFunc( VkFlags msgFlags,
                                                         VkDebugReportObjectTypeEXT objType,
                                                         uint64_t srcObject,
                                                         size_t location,
                                                         int32_t msgCode,
                                                         const char *layerPrefix,
                                                         const char *msg,
                                                         void *userData);
public:
    // 필요한 Layer, Extension 이름
    std::vector<const char*> appRequestedLayerNames;
    std::vector<const char* > appRequestedExtensionNames;

    // 레이어와 해당한는 확장판 리스트
    std::vector<LayerProperties> layerPropertyList;


    // 디버깅 보고서의 콜백 함수는 정보 제어 구조체를 생성
    VkDebugReportCallbackCreateInfoEXT dbgReportCreateInfo = {};
private:
    // 생성과 삭제 함수 포인터 선언
    PFN_vkCreateDebugReportCallbackEXT dbgCreateDebugReportCallback;
    PFN_vkDestroyDebugReportCallbackEXT dbgDestroyDebugReportCallback;

    // 디버깅 보고서 콜백 함수의 핸들
    VkDebugReportCallbackEXT debugReportCallback;
};


#endif //ENGINE_VULKANLAYEREXTENSION_H
