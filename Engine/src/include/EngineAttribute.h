//
// Created by EunwooSong on 2020-11-08.
//

#ifndef ENGINE_ENGINEATTRIBUTE_H
#define ENGINE_ENGINEATTRIBUTE_H

#include <cstdlib>
#include <cstdint>

namespace EngineAttribute {
    constexpr const char * APPLICATION_NAME = "SHARK_ENGINE_DEMO";
    constexpr const char * APPLICATION_VERSION = "1.0.0";
    constexpr const char * ENGINE_VERSION = "1.0.0";
    constexpr const char * ENGINE_NAME = "SharkEngine";
    constexpr const bool DEBUG = true;

    constexpr const uint32_t SCREEN_WIDTH = 1280;
    constexpr const uint32_t SCREEN_HEIGHT = 720;
    constexpr const bool FULL_SCREEN = false;

// max frame in bound on GPU, ONLY 2^n values
    constexpr const int MAX_FRAMES_IN_FLIGHT = 32;

    constexpr const bool enableValidationLayers = DEBUG;
}

#endif //ENGINE_ENGINEATTRIBUTE_H
