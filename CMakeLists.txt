cmake_minimum_required(VERSION 3.22)
project(MissileCommand)

set(CMAKE_CXX_STANDARD 14)

# Must set the path to the main.cpp, for example: scripts/main.cpp if it is inside a folder
add_executable(${PROJECT_NAME} main.cpp
        GameObjects/Game.cpp
        GameObjects/Game.h
        GameObjects/TextureManager.cpp
        GameObjects/TextureManager.h
        GameObjects/GameObject.cpp
        GameObjects/GameObject.h
        GameObjects/Handler.cpp
        GameObjects/Handler.h
        GameObjects/GameID.h)

message("Binary Directory: ${CMAKE_BINARY_DIR}")

# --- SDL2 SETUP ---
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)
set(SDL2_PATH "SDL2/x86_64-w64-mingw32")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARIES})
