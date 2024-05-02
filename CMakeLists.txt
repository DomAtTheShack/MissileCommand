cmake_minimum_required(VERSION 3.22)
project(MissileCommand)

set(CMAKE_CXX_STANDARD 14)
list(APPEND CMAKE_PREFIX_PATH "${PROJECT_SOURCE_DIR}/SDL2/SDL2-2.30.2")


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

target_include_directories(${PROJECT_NAME} PRIVATE ${SDL2_INCLUDE_DIRS})

if(WIN32)
    # set variables
    set(SDL2_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/SDL2/SDL2-2.30.2/include")
    set(SDL2_LIBRARY "${PROJECT_SOURCE_DIR}/SDL2/SDL2-2.30.2/lib/x64/SDL2.lib")  # change this accordingly
    set(SDL2_IMAGE_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/SDL2_image/Windows/SDL2_image-2.8.2/include")
    set(SDL2_IMAGE_LIBRARIES "${PROJECT_SOURCE_DIR}/SDL2_image/Windows/SDL2_image-2.8.2/lib/x64/SDL2_image.lib")

    # include directories
    include_directories("${SDL2_INCLUDE_DIR}")
    include_directories("${SDL2_IMAGE_INCLUDE_DIRS}")

    target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARIES})

    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/SDL2/SDL2-x64-Windows/SDL2.dll
            ${CMAKE_CURRENT_BINARY_DIR}/SDL2.dll
            COPYONLY)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/SDL2_image/Windows/SDL2_image-2.8.2/lib/x64/SDL2_image.dll
            ${CMAKE_CURRENT_BINARY_DIR}/SDL2_image.dll
            COPYONLY)
elseif(APPLE)
    find_library(SDL2_LIBRARY SDL2)
    find_library(SDL2_IMAGE_LIBRARY SDL2_image)
    include_directories("SDL2/SDL2x64-macOS/include")
    target_include_directories(${PROJECT_NAME} PUBLIC "SDL2/SDL2x64-macOS/include")
    find_package(PNG REQUIRED)
    target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL2_LIBRARIES} ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} PNG::PNG)
elseif(UNIX)
    # set linux-specific variables
    set(SDL2_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/SDL2/SDL2-2.30.2/include")
    set(SDL2_LIBRARY "${PROJECT_SOURCE_DIR}/SDL2/x86_64-w64-mingw32/lib")  # <- verify this path
    set(SDL2_IMAGE_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/SDL2_image/x86_64-w64-mingw32/include")
    set(SDL2_IMAGE_LIBRARIES "${PROJECT_SOURCE_DIR}/SDL2_image/x86_64-w64-mingw32/lib/libSDL2_image.a")
    find_package(PNG REQUIRED)
    target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL2_LIBRARIES} ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} PNG::PNG)
endif()


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/)