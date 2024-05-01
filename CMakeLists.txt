cmake_minimum_required(VERSION 3.22)
project(MissileCommand)

set(CMAKE_CXX_STANDARD 14)

add_executable(${PROJECT_NAME} main.cpp
        GameHeaders/SourceFiles/Game.cpp
        GameHeaders/Game.h
        GameHeaders/SourceFiles/TextureManager.cpp
        GameHeaders/TextureManager.h
        GameHeaders/SourceFiles/GameObject.cpp
        GameHeaders/GameObject.h
        GameHeaders/SourceFiles/Handler.cpp
        GameHeaders/Handler.h
        GameHeaders/GameID.h
        GameHeaders/SourceFiles/Background.cpp
        GameHeaders/Background.h)

add_definitions(-DSDL_MAIN_HANDLED)
message("Binary Directory: ${CMAKE_BINARY_DIR}")

if(WIN32)
    # set windows-specific variables
    set(SDL2_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/SDL2/SDL2-2.30.2/include")
    set(SDL2_LIBRARY "${PROJECT_SOURCE_DIR}/SDL2/SDL2-2.30.2/lib/x64")  # <- verify this path
    set(SDL2_IMAGE_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/SDL2_image/Windows/SDL2_image-2.8.2/include")
    set(SDL2_IMAGE_LIBRARIES "${PROJECT_SOURCE_DIR}/SDL2_image/Windows/SDL2_image-2.8.2/lib/x64")
    target_link_libraries(${PROJECT_NAME} "${SDL2_LIBRARY}/SDL2.lib")
    target_link_libraries(${PROJECT_NAME} "${SDL2_IMAGE_LIBRARIES}/SDL2_image.lib")
elseif(APPLE)
    # set macOS-specific variables
    find_package(SDL2 REQUIRED)
    include_directories(${SDL2_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})

    find_package(SDL2_image REQUIRED)
    include_directories(${SDL2_IMAGE_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME} ${SDL2_IMAGE_LIBRARIES})
elseif(UNIX)
    # set linux-specific variables
    set(SDL2_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/SDL2/SDL2-2.30.2/include")
    set(SDL2_LIBRARY "${PROJECT_SOURCE_DIR}/SDL2/x86_64-w64-mingw32/lib/x64")  # <- verify this path
    set(SDL2_IMAGE_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/SDL2_image/x86_64-w64-mingw32/include")
    set(SDL2_IMAGE_LIBRARIES "${PROJECT_SOURCE_DIR}/SDL2_image/x86_64-w64-mingw32/lib")
    target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY})
    target_link_libraries(${PROJECT_NAME} ${SDL2_IMAGE_LIBRARIES})
endif()

include_directories(${SDL2_INCLUDE_DIR})

include_directories(${SDL2_IMAGE_INCLUDE_DIRS})

link_directories(${SDL2_IMAGE_LIBRARIES})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/)
