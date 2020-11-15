//
// Created by EunwooSong on 2020-11-08.
//

#ifndef ENGINE_VULKANAPPLICATION_H
#define ENGINE_VULKANAPPLICATION_H


class VulkanApplication {
public:
    VulkanApplication();
    ~VulkanApplication();

    static VulkanApplication* GetInstance();

    void Initialize();
    void Prepare();
    void Update();
    bool Render();
    void Release();

private:

};


#endif //ENGINE_VULKANAPPLICATION_H
