# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\EunwooSong\Desktop\Git\Vulkan\VulkanEngine\Engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\EunwooSong\Desktop\Git\Vulkan\VulkanEngine\Engine\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\main.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\main.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\main.dir\flags.make

CMakeFiles\main.dir\src\main.cpp.obj: CMakeFiles\main.dir\flags.make
CMakeFiles\main.dir\src\main.cpp.obj: ..\src\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\EunwooSong\Desktop\Git\Vulkan\VulkanEngine\Engine\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main.dir/src/main.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\main.dir\src\main.cpp.obj /FdCMakeFiles\main.dir\ /FS -c C:\Users\EunwooSong\Desktop\Git\Vulkan\VulkanEngine\Engine\src\main.cpp
<<

CMakeFiles\main.dir\src\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/main.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe > CMakeFiles\main.dir\src\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\EunwooSong\Desktop\Git\Vulkan\VulkanEngine\Engine\src\main.cpp
<<

CMakeFiles\main.dir\src\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/main.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\main.dir\src\main.cpp.s /c C:\Users\EunwooSong\Desktop\Git\Vulkan\VulkanEngine\Engine\src\main.cpp
<<

CMakeFiles\main.dir\src\core\Graphic\VulkanInstance.cpp.obj: CMakeFiles\main.dir\flags.make
CMakeFiles\main.dir\src\core\Graphic\VulkanInstance.cpp.obj: ..\src\core\Graphic\VulkanInstance.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\EunwooSong\Desktop\Git\Vulkan\VulkanEngine\Engine\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/main.dir/src/core/Graphic/VulkanInstance.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\main.dir\src\core\Graphic\VulkanInstance.cpp.obj /FdCMakeFiles\main.dir\ /FS -c C:\Users\EunwooSong\Desktop\Git\Vulkan\VulkanEngine\Engine\src\core\Graphic\VulkanInstance.cpp
<<

CMakeFiles\main.dir\src\core\Graphic\VulkanInstance.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/core/Graphic/VulkanInstance.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe > CMakeFiles\main.dir\src\core\Graphic\VulkanInstance.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\EunwooSong\Desktop\Git\Vulkan\VulkanEngine\Engine\src\core\Graphic\VulkanInstance.cpp
<<

CMakeFiles\main.dir\src\core\Graphic\VulkanInstance.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/core/Graphic/VulkanInstance.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\main.dir\src\core\Graphic\VulkanInstance.cpp.s /c C:\Users\EunwooSong\Desktop\Git\Vulkan\VulkanEngine\Engine\src\core\Graphic\VulkanInstance.cpp
<<

CMakeFiles\main.dir\src\core\Graphic\VulkanApplication.cpp.obj: CMakeFiles\main.dir\flags.make
CMakeFiles\main.dir\src\core\Graphic\VulkanApplication.cpp.obj: ..\src\core\Graphic\VulkanApplication.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\EunwooSong\Desktop\Git\Vulkan\VulkanEngine\Engine\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/main.dir/src/core/Graphic/VulkanApplication.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\main.dir\src\core\Graphic\VulkanApplication.cpp.obj /FdCMakeFiles\main.dir\ /FS -c C:\Users\EunwooSong\Desktop\Git\Vulkan\VulkanEngine\Engine\src\core\Graphic\VulkanApplication.cpp
<<

CMakeFiles\main.dir\src\core\Graphic\VulkanApplication.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/core/Graphic/VulkanApplication.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe > CMakeFiles\main.dir\src\core\Graphic\VulkanApplication.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\EunwooSong\Desktop\Git\Vulkan\VulkanEngine\Engine\src\core\Graphic\VulkanApplication.cpp
<<

CMakeFiles\main.dir\src\core\Graphic\VulkanApplication.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/core/Graphic/VulkanApplication.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\main.dir\src\core\Graphic\VulkanApplication.cpp.s /c C:\Users\EunwooSong\Desktop\Git\Vulkan\VulkanEngine\Engine\src\core\Graphic\VulkanApplication.cpp
<<

CMakeFiles\main.dir\src\core\Graphic\VulkanDevice.cpp.obj: CMakeFiles\main.dir\flags.make
CMakeFiles\main.dir\src\core\Graphic\VulkanDevice.cpp.obj: ..\src\core\Graphic\VulkanDevice.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\EunwooSong\Desktop\Git\Vulkan\VulkanEngine\Engine\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/main.dir/src/core/Graphic/VulkanDevice.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\main.dir\src\core\Graphic\VulkanDevice.cpp.obj /FdCMakeFiles\main.dir\ /FS -c C:\Users\EunwooSong\Desktop\Git\Vulkan\VulkanEngine\Engine\src\core\Graphic\VulkanDevice.cpp
<<

CMakeFiles\main.dir\src\core\Graphic\VulkanDevice.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/core/Graphic/VulkanDevice.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe > CMakeFiles\main.dir\src\core\Graphic\VulkanDevice.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\EunwooSong\Desktop\Git\Vulkan\VulkanEngine\Engine\src\core\Graphic\VulkanDevice.cpp
<<

CMakeFiles\main.dir\src\core\Graphic\VulkanDevice.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/core/Graphic/VulkanDevice.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\main.dir\src\core\Graphic\VulkanDevice.cpp.s /c C:\Users\EunwooSong\Desktop\Git\Vulkan\VulkanEngine\Engine\src\core\Graphic\VulkanDevice.cpp
<<

CMakeFiles\main.dir\src\core\Graphic\VulkanPipeline.cpp.obj: CMakeFiles\main.dir\flags.make
CMakeFiles\main.dir\src\core\Graphic\VulkanPipeline.cpp.obj: ..\src\core\Graphic\VulkanPipeline.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\EunwooSong\Desktop\Git\Vulkan\VulkanEngine\Engine\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/main.dir/src/core/Graphic/VulkanPipeline.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\main.dir\src\core\Graphic\VulkanPipeline.cpp.obj /FdCMakeFiles\main.dir\ /FS -c C:\Users\EunwooSong\Desktop\Git\Vulkan\VulkanEngine\Engine\src\core\Graphic\VulkanPipeline.cpp
<<

CMakeFiles\main.dir\src\core\Graphic\VulkanPipeline.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/core/Graphic/VulkanPipeline.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe > CMakeFiles\main.dir\src\core\Graphic\VulkanPipeline.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\EunwooSong\Desktop\Git\Vulkan\VulkanEngine\Engine\src\core\Graphic\VulkanPipeline.cpp
<<

CMakeFiles\main.dir\src\core\Graphic\VulkanPipeline.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/core/Graphic/VulkanPipeline.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\main.dir\src\core\Graphic\VulkanPipeline.cpp.s /c C:\Users\EunwooSong\Desktop\Git\Vulkan\VulkanEngine\Engine\src\core\Graphic\VulkanPipeline.cpp
<<

CMakeFiles\main.dir\src\core\Graphic\VulkanRenderer.cpp.obj: CMakeFiles\main.dir\flags.make
CMakeFiles\main.dir\src\core\Graphic\VulkanRenderer.cpp.obj: ..\src\core\Graphic\VulkanRenderer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\EunwooSong\Desktop\Git\Vulkan\VulkanEngine\Engine\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/main.dir/src/core/Graphic/VulkanRenderer.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\main.dir\src\core\Graphic\VulkanRenderer.cpp.obj /FdCMakeFiles\main.dir\ /FS -c C:\Users\EunwooSong\Desktop\Git\Vulkan\VulkanEngine\Engine\src\core\Graphic\VulkanRenderer.cpp
<<

CMakeFiles\main.dir\src\core\Graphic\VulkanRenderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/core/Graphic/VulkanRenderer.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe > CMakeFiles\main.dir\src\core\Graphic\VulkanRenderer.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\EunwooSong\Desktop\Git\Vulkan\VulkanEngine\Engine\src\core\Graphic\VulkanRenderer.cpp
<<

CMakeFiles\main.dir\src\core\Graphic\VulkanRenderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/core/Graphic/VulkanRenderer.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\main.dir\src\core\Graphic\VulkanRenderer.cpp.s /c C:\Users\EunwooSong\Desktop\Git\Vulkan\VulkanEngine\Engine\src\core\Graphic\VulkanRenderer.cpp
<<

CMakeFiles\main.dir\src\core\Graphic\VulkanSwapChain.cpp.obj: CMakeFiles\main.dir\flags.make
CMakeFiles\main.dir\src\core\Graphic\VulkanSwapChain.cpp.obj: ..\src\core\Graphic\VulkanSwapChain.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\EunwooSong\Desktop\Git\Vulkan\VulkanEngine\Engine\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/main.dir/src/core/Graphic/VulkanSwapChain.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\main.dir\src\core\Graphic\VulkanSwapChain.cpp.obj /FdCMakeFiles\main.dir\ /FS -c C:\Users\EunwooSong\Desktop\Git\Vulkan\VulkanEngine\Engine\src\core\Graphic\VulkanSwapChain.cpp
<<

CMakeFiles\main.dir\src\core\Graphic\VulkanSwapChain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/core/Graphic/VulkanSwapChain.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe > CMakeFiles\main.dir\src\core\Graphic\VulkanSwapChain.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\EunwooSong\Desktop\Git\Vulkan\VulkanEngine\Engine\src\core\Graphic\VulkanSwapChain.cpp
<<

CMakeFiles\main.dir\src\core\Graphic\VulkanSwapChain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/core/Graphic/VulkanSwapChain.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\main.dir\src\core\Graphic\VulkanSwapChain.cpp.s /c C:\Users\EunwooSong\Desktop\Git\Vulkan\VulkanEngine\Engine\src\core\Graphic\VulkanSwapChain.cpp
<<

CMakeFiles\main.dir\src\core\Graphic\VulkanLayerExtension.cpp.obj: CMakeFiles\main.dir\flags.make
CMakeFiles\main.dir\src\core\Graphic\VulkanLayerExtension.cpp.obj: ..\src\core\Graphic\VulkanLayerExtension.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\EunwooSong\Desktop\Git\Vulkan\VulkanEngine\Engine\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/main.dir/src/core/Graphic/VulkanLayerExtension.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\main.dir\src\core\Graphic\VulkanLayerExtension.cpp.obj /FdCMakeFiles\main.dir\ /FS -c C:\Users\EunwooSong\Desktop\Git\Vulkan\VulkanEngine\Engine\src\core\Graphic\VulkanLayerExtension.cpp
<<

CMakeFiles\main.dir\src\core\Graphic\VulkanLayerExtension.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/core/Graphic/VulkanLayerExtension.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe > CMakeFiles\main.dir\src\core\Graphic\VulkanLayerExtension.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\EunwooSong\Desktop\Git\Vulkan\VulkanEngine\Engine\src\core\Graphic\VulkanLayerExtension.cpp
<<

CMakeFiles\main.dir\src\core\Graphic\VulkanLayerExtension.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/core/Graphic/VulkanLayerExtension.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\main.dir\src\core\Graphic\VulkanLayerExtension.cpp.s /c C:\Users\EunwooSong\Desktop\Git\Vulkan\VulkanEngine\Engine\src\core\Graphic\VulkanLayerExtension.cpp
<<

# Object files for target main
main_OBJECTS = \
"CMakeFiles\main.dir\src\main.cpp.obj" \
"CMakeFiles\main.dir\src\core\Graphic\VulkanInstance.cpp.obj" \
"CMakeFiles\main.dir\src\core\Graphic\VulkanApplication.cpp.obj" \
"CMakeFiles\main.dir\src\core\Graphic\VulkanDevice.cpp.obj" \
"CMakeFiles\main.dir\src\core\Graphic\VulkanPipeline.cpp.obj" \
"CMakeFiles\main.dir\src\core\Graphic\VulkanRenderer.cpp.obj" \
"CMakeFiles\main.dir\src\core\Graphic\VulkanSwapChain.cpp.obj" \
"CMakeFiles\main.dir\src\core\Graphic\VulkanLayerExtension.cpp.obj"

# External object files for target main
main_EXTERNAL_OBJECTS =

main.exe: CMakeFiles\main.dir\src\main.cpp.obj
main.exe: CMakeFiles\main.dir\src\core\Graphic\VulkanInstance.cpp.obj
main.exe: CMakeFiles\main.dir\src\core\Graphic\VulkanApplication.cpp.obj
main.exe: CMakeFiles\main.dir\src\core\Graphic\VulkanDevice.cpp.obj
main.exe: CMakeFiles\main.dir\src\core\Graphic\VulkanPipeline.cpp.obj
main.exe: CMakeFiles\main.dir\src\core\Graphic\VulkanRenderer.cpp.obj
main.exe: CMakeFiles\main.dir\src\core\Graphic\VulkanSwapChain.cpp.obj
main.exe: CMakeFiles\main.dir\src\core\Graphic\VulkanLayerExtension.cpp.obj
main.exe: CMakeFiles\main.dir\build.make
main.exe: C:\vcpkg\installed\x86-windows\debug\lib\glfw3dll.lib
main.exe: C:\VulkanSDK\1.2.148.1\Lib32\vulkan-1.lib
main.exe: C:\vcpkg\installed\x86-windows\debug\lib\tinyobjloader.lib
main.exe: C:\vcpkg\installed\x86-windows\debug\lib\OpenAL32.lib
main.exe: CMakeFiles\main.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\EunwooSong\Desktop\Git\Vulkan\VulkanEngine\Engine\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable main.exe"
	"C:\Program Files\JetBrains\CLion 2020.2.3\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\main.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\main.dir\objects1.rsp @<<
 /out:main.exe /implib:main.lib /pdb:C:\Users\EunwooSong\Desktop\Git\Vulkan\VulkanEngine\Engine\cmake-build-debug\main.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console  C:\vcpkg\installed\x86-windows\debug\lib\glfw3dll.lib C:\VulkanSDK\1.2.148.1\Lib32\vulkan-1.lib C:\vcpkg\installed\x86-windows\debug\lib\tinyobjloader.lib C:\vcpkg\installed\x86-windows\debug\lib\OpenAL32.lib kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<
	powershell -noprofile -executionpolicy Bypass -file C:/vcpkg/scripts/buildsystems/msbuild/applocal.ps1 -targetBinary C:/Users/EunwooSong/Desktop/Git/Vulkan/VulkanEngine/Engine/cmake-build-debug/main.exe -installedDir C:/vcpkg/installed/x86-windows/debug/bin -OutVariable out

# Rule to build all files generated by this target.
CMakeFiles\main.dir\build: main.exe

.PHONY : CMakeFiles\main.dir\build

CMakeFiles\main.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\main.dir\cmake_clean.cmake
.PHONY : CMakeFiles\main.dir\clean

CMakeFiles\main.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\EunwooSong\Desktop\Git\Vulkan\VulkanEngine\Engine C:\Users\EunwooSong\Desktop\Git\Vulkan\VulkanEngine\Engine C:\Users\EunwooSong\Desktop\Git\Vulkan\VulkanEngine\Engine\cmake-build-debug C:\Users\EunwooSong\Desktop\Git\Vulkan\VulkanEngine\Engine\cmake-build-debug C:\Users\EunwooSong\Desktop\Git\Vulkan\VulkanEngine\Engine\cmake-build-debug\CMakeFiles\main.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\main.dir\depend

