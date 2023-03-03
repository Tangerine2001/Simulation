cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME "Simulation")
set(SOURCE_DIR src)
set(INCLUDE_DIR include)

set(SOURCES ${SOURCE_DIR}/main.cpp)
file(GLOB SOURCES ${SOURCE_DIR}/*.cpp)

set(HEADERS ${INCLUDE_DIR}/GameObject.hpp)
file(GLOB HEADERS ${INCLUDE_DIR}/*.hpp)

project(${PROJECT_NAME} LANGUAGES CXX)

# add_library(gameObjectLib ${SOURCE_DIR}/GameObject.cpp ${INCLUDE_DIR}/GameObject.hpp)
# target_include_directories(gameObjectLib PRIVATE ${INCLUDE_DIR})
# add_library(Vector2 ${SOURCE_DIR}/Vector2.cpp ${INCLUDE_DIR}/Vector2.hpp)
# target_include_directories(Vector2 PRIVATE ${INCLUDE_DIR})
# add_library(GameManagerLib ${SOURCE_DIR}/GameManager.cpp ${INCLUDE_DIR}/GameManager.hpp)
# target_include_directories(GameManagerLib PRIVATE ${INCLUDE_DIR})
# add_library(PreyLib ${SOURCE_DIR}/Prey.cpp ${INCLUDE_DIR}/Prey.hpp)
# target_include_directories(PreyLib PRIVATE ${INCLUDE_DIR})

# set(HEADER_FILES
    # ${INCLUDE_DIR}/GameObject.hpp
    # ${INCLUDE_DIR}/Vector2.hpp
    # ${INCLUDE_DIR}/GameManager.hpp
    # ${INCLUDE_DIR}/Prey.hpp
# )

# set(LIB_FILES
#     gameObjectLib
#     Vector2Lib
#     GameManagerLib
#     PreyLib
# )

# SFML
include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:${PROJECT_NAME}> $<TARGET_FILE_DIR:${PROJECT_NAME}> COMMAND_EXPAND_LISTS)
endif()

install(TARGETS ${PROJECT_NAME})

# Move the assets folder to the build directory
add_custom_target(copy_assets
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/assets ${CMAKE_CURRENT_BINARY_DIR}/assets
)
add_dependencies(${PROJECT_NAME} copy_assets)

# target_include_directories(${PROJECT_NAME} PRIVATE ${HEADER_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIR})
# target_include_directories(${SOURCES} PUBLIC build/_deps/sfml-src/include)
# target_link_libraries(${PROJECT_NAME} PRIVATE Vector2Lib)
