cmake_minimum_required(VERSION 3.10)

project("Simulation" VERSION 1.0)
set(SFML_STATIC_LIBRARIES TRUE)
set(TGUI_STATIC_LIBRARIES TRUE)
set(SFML_DIR libs/SFML-2.5.1/lib/cmake/SFML)
set(TGUI_DIR libs/TGUI-0.9/lib/cmake/TGUI)
find_package(SFML 2.5 COMPONENTS graphics REQUIRED)  # system window graphics network audio
find_package(TGUI REQUIRED)

if(NOT SFML_FOUND)
    message(FATAL_ERROR "Could not find SFML")
endif()

if(NOT TGUI_FOUND)
    message(FATAL_ERROR "Could not find TGUI")
endif()

set(SOURCES src/main.cpp)
file(GLOB SOURCES src/*.cpp)
set(HEADERS include/Boid.hpp)
file(GLOB HEADERS include/*.hpp)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

target_link_libraries(${PROJECT_NAME} sfml-graphics tgui)
add_custom_target(copy_assets
     COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/assets ${CMAKE_CURRENT_BINARY_DIR}/Debug/assets
)
add_dependencies(${PROJECT_NAME} copy_assets)

target_include_directories(${PROJECT_NAME} PUBLIC include)
