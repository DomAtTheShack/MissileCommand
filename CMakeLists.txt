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
        GameHeaders/Background.h
        GameHeaders/SourceFiles/Cursor.cpp
        GameHeaders/Cursor.h
        GameHeaders/SourceFiles/PlayerBase.cpp
        GameHeaders/PlayerBase.h)

add_definitions(-DSDL_MAIN_HANDLED)
message("Binary Directory: ${CMAKE_BINARY_DIR}")

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
else()
    find_package(PkgConfig REQUIRED)

    # search for SDL2
    pkg_search_module(SDL2 REQUIRED sdl2)
    # search for SDL2_image
    pkg_search_module(SDL2_image REQUIRED SDL2_image)

    # include the SDL2 include directories
    include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_image_INCLUDE_DIRS})

    # link the libraries to your project
    target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL2_LIBRARIES} ${SDL2_image_LIBRARIES})
endif()

# Define the source directory (your assets folder)
set(SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/assets")

# Define the destination directory in the build directory
set(DEST_DIR "${CMAKE_BINARY_DIR}")

# Copy the contents of the source directory to the destination directory
file(COPY ${SOURCE_DIR} DESTINATION ${DEST_DIR})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/)