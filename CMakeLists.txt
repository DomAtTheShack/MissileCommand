cmake_minimum_required(VERSION 3.22)
project(MissileCommand)
set(CMAKE_CXX_STANDARD 14)

add_executable(${PROJECT_NAME}
        main.cpp
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
        GameHeaders/PlayerBase.h
        GameHeaders/SourceFiles/MoviableObject.cpp
        GameHeaders/MoviableObject.h
        GameHeaders/SourceFiles/MissileTrail.cpp
        GameHeaders/MissileTrail.h
        GameHeaders/SourceFiles/Missile.cpp
        GameHeaders/Missile.h
        GameHeaders/SourceFiles/City.cpp
        GameHeaders/City.h
)

add_definitions(-DSDL_MAIN_HANDLED)
message("Binary Directory: ${CMAKE_BINARY_DIR}")

# Add an option for the target architecture
option(TARGET_ARCH "Target architecture (x86 or x64)" "x64")

if(WIN32)
    # Set variables based on architecture
    if(TARGET_ARCH STREQUAL "x86")
        set(SDL2_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/SDL2/SDL2-2.30.2/include")
        set(SDL2_LIBRARY "${PROJECT_SOURCE_DIR}/SDL2/SDL2-2.30.2/lib/x86/SDL2.lib")
        set(SDL2_IMAGE_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/SDL2_image/Windows/SDL2_image-2.8.2/include")
        set(SDL2_IMAGE_LIBRARIES "${PROJECT_SOURCE_DIR}/SDL2_image/Windows/SDL2_image-2.8.2/lib/x86/SDL2_image.lib")
        set(SDL2_DLL "${PROJECT_SOURCE_DIR}/SDL2/SDL2-2.30.2/lib/x86/SDL2.dll")
        set(SDL2_IMAGE_DLL "${PROJECT_SOURCE_DIR}/SDL2_image/Windows/SDL2_image-2.8.2/lib/x86/SDL2_image.dll")
    else()
        set(SDL2_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/SDL2/SDL2-2.30.2/include")
        set(SDL2_LIBRARY "${PROJECT_SOURCE_DIR}/SDL2/SDL2-2.30.2/lib/x64/SDL2.lib")
        set(SDL2_IMAGE_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/SDL2_image/Windows/SDL2_image-2.8.2/include")
        set(SDL2_IMAGE_LIBRARIES "${PROJECT_SOURCE_DIR}/SDL2_image/Windows/SDL2_image-2.8.2/lib/x64/SDL2_image.lib")
        set(SDL2_DLL "${PROJECT_SOURCE_DIR}/SDL2/SDL2-2.30.2/lib/x64/SDL2.dll")
        set(SDL2_IMAGE_DLL "${PROJECT_SOURCE_DIR}/SDL2_image/Windows/SDL2_image-2.8.2/lib/x64/SDL2_image.dll")
    endif()

    # Include directories
    include_directories("${SDL2_INCLUDE_DIR}")
    include_directories("${SDL2_IMAGE_INCLUDE_DIRS}")
    target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARIES})

    # Copy DLL files to the same directory as the executable
    configure_file(${SDL2_DLL} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/SDL2.dll COPYONLY)
    configure_file(${SDL2_IMAGE_DLL} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/SDL2_image.dll COPYONLY)

else()
    find_package(PkgConfig REQUIRED)
    # Search for SDL2
    pkg_search_module(SDL2 REQUIRED sdl2)
    # Search for SDL2_image
    pkg_search_module(SDL2_image REQUIRED SDL2_image)
    # Include the SDL2 include directories
    include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_image_INCLUDE_DIRS})
    # Link the libraries to your project
    target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL2_LIBRARIES} ${SDL2_image_LIBRARIES})
endif()



set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/)
