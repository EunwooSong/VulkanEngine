//
// Created by EunwooSong on 2020-11-08.
//

#ifndef ENGINE_STDAFX_H
#define ENGINE_STDAFX_H

#pragma warning(disable 4819)

#include <iostream>
#include <array>
#include <random>
#include <list>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <chrono>
#include <mutex>
#include <set>
#include <functional>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <assert.h>
#include <memory>
#include <mutex>

//DELETE Macro
#define SAFE_DELETE(p)     \
    {                      \
        if (p) {           \
            delete (p);    \
            (p) = nullptr; \
        }                  \
    }

#define SAFE_DELETE_ARRAY(p) \
    {                        \
        if (p) {             \
            delete[](p);     \
            (p) = nullptr;   \
        }                    \
    }

#define SAFE_RELEASE(p)     \
    {                       \
        if (p) {            \
            (p)->Release(); \
            (p) = nullptr;  \
        }                   \
    }

#endif //ENGINE_STDAFX_H
