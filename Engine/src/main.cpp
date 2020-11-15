#include <iostream>
#include "include/VulkanApplication.h"

int main() {
    VulkanApplication* vk_app = VulkanApplication::GetInstance();
    vk_app->Initialize();
    vk_app->Prepare();

    while(true) {
        vk_app->Update();
        if(!vk_app->Render())
            break;
    }

    vk_app->Release();
    return 0;
}