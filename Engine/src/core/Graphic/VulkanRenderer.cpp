//
// Created by EunwooSong on 2020-11-08.
//

#include "include/VulkanRenderer.h"
#include "include/EngineAttribute.h"

void VulkanRenderer::InitializeWindow() {
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window = glfwCreateWindow(
                EngineAttribute::SCREEN_WIDTH,
                EngineAttribute::SCREEN_HEIGHT,
                EngineAttribute::APPLICATION_NAME,
                nullptr, nullptr);
    glfwSetWindowUserPointer(window, this);
    glfwSetFramebufferSizeCallback(window, );
}
