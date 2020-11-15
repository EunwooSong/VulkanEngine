cmake_minimum_required(VERSION 3.17)
project(Engine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(ROOTSRC ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(main src/main.cpp src/core/Graphic/VulkanInstance.cpp src/include/VulkanInstance.h src/core/Graphic/VulkanApplication.cpp src/include/VulkanApplication.h src/core/Graphic/VulkanDevice.cpp src/include/VulkanDevice.h src/core/Graphic/VulkanPipeline.cpp src/include/VulkanPipeline.h src/core/Graphic/VulkanRenderer.cpp src/include/VulkanRenderer.h src/core/Graphic/VulkanSwapChain.cpp src/include/VulkanSwapChain.h src/core/Graphic/VulkanLayerExtension.cpp src/include/VulkanLayerExtension.h src/include/VulkanInclude.h src/include/stdafx.h src/include/EngineAttribute.h)

target_include_directories(main PRIVATE src)

find_package(glm CONFIG REQUIRED)
target_link_libraries(main PRIVATE glm)

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(main PRIVATE glfw)

find_package(Vulkan REQUIRED)
target_include_directories(main PUBLIC ${Vulkan_INCLUDE_DIRS})
target_link_libraries(main PRIVATE Vulkan::Vulkan)

find_path(STB_INCLUDE_DIRS "stb.h")
target_include_directories(main PRIVATE ${STB_INCLUDE_DIRS})

find_package(tinyobjloader CONFIG REQUIRED)
target_link_libraries(main PRIVATE tinyobjloader::tinyobjloader)

find_package(OpenAL CONFIG REQUIRED)
target_link_libraries(main PRIVATE OpenAL::OpenAL)

find_package(gli CONFIG REQUIRED)
target_link_libraries(main PRIVATE gli)