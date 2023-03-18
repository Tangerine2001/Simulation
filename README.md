# Simulations

## Setup Directions For Windows (From Scratch)
These steps assume you have C++ installed along with some compiler (MinGW | g++) and cmake. 
1. Create the following folder setup:
```
.
├── build/
│   └── Windows
├── src
├── include
├── libs
└── assets
```
2. Download SFML and TGUI and put them under libs. This is what the folder should look like. Make sure the TGUI version is a precompiled version.
```
.
└── libs/
    ├── SFML-2.5.1
    └── TGUI-0.9
```
3. Open up `cmake-gui` and compile TGUI. Source directory should be the parent TGUI folder, and build directory should be `TGUI-0.9/build`
    - This is a multi-step process. It will ask what backend to use for `TGUI`. The default `SFML-Graphics` is what we want so just move on from there.
    - You will then need to specify SFML_DIR in the GUI as the folder path to where SFMLConfig.cmake is located. For SFML-2.5.1, its `SFML-2.5.1/lib/cmake/SFML`.
    - Make sure that `TGUI_BUILD_AS_CXX_MODULE` is unchecked.
    - Configure one last time and then generate.

4. Then create CMakeLists.txt under the root directory.
```cmake
cmake_minimum_required(VERSION 3.10)

project("Simulation" VERSION 1.0)
set(SFML_STATIC_LIBRARIES TRUE)
set(TGUI_STATIC_LIBRARIES TRUE)
set(SFML_DIR libs/SFML-2.5.1/lib/cmake/SFML)
set(TGUI_DIR libs/TGUI-0.9/lib/cmake/TGUI)
find_package(SFML 2.5 COMPONENTS graphics REQUIRED)
find_package(TGUI REQUIRED)

if(NOT SFML_FOUND)
    message(FATAL_ERROR "Could not find SFML")
endif()

if(NOT TGUI_FOUND)
    message(FATAL_ERROR "Could not find TGUI")
endif()

set(SOURCES src/main.cpp)
file(GLOB SOURCES src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

target_link_libraries(${PROJECT_NAME} sfml-graphics tgui)
add_custom_target(copy_assets
     COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/assets ${CMAKE_CURRENT_BINARY_DIR}/Debug/assets
)
add_dependencies(${PROJECT_NAME} copy_assets)

target_include_directories(${PROJECT_NAME} PUBLIC include)
```
This file is enough for the entirety of the project.

## Boid Simulation
