//
// Created by EunwooSong on 2020-11-08.
//

#ifndef ENGINE_VULKANRENDERER_H
#define ENGINE_VULKANRENDERER_H

#include "VulkanInclude.h"

class VulkanRenderer {
public:
    void Initialize();
    void Prepare();
    void Update();
    void Render();

    void InitializeWindow();

private:
    GLFWwindow* window;
};


#endif //ENGINE_VULKANRENDERER_H
