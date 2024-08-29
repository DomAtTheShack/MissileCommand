cmake_minimum_required(VERSION 3.22)
project(MissileCommand)
set(CMAKE_CXX_STANDARD 14)

add_executable(${PROJECT_NAME}
        GameHeaders/SourceFiles/TextureManager.cpp
        GameHeaders/TextureManager.h
        GameHeaders/SourceFiles/GameObject.cpp
        GameHeaders/GameObject.h
        GameHeaders/SourceFiles/Handler.cpp
        GameHeaders/Handler.h
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
        GameHeaders/SourceFiles/AudioSystem.cpp
        GameHeaders/AudioSystem.h
        GameHeaders/SourceFiles/MissileExplo.cpp
        GameHeaders/MissileExplo.h
        main.cpp
        GameHeaders/SourceFiles/Game.cpp
        GameHeaders/Game.h
        GameHeaders/SourceFiles/Timer.cpp
        GameHeaders/Timer.h
        GameHeaders/SourceFiles/EnemyMissileLauncher.cpp
        GameHeaders/EnemyMissileLauncher.h
        GameHeaders/CityTargets.h
        GameHeaders/SourceFiles/SettingsWindow.cpp
        GameHeaders/SourceFiles/SettingsWindow.h
)

add_definitions(-DSDL_MAIN_HANDLED)
message("Binary Directory: ${CMAKE_BINARY_DIR}")

# Copy assets directory
set(SOURCE_FOLDER "${CMAKE_SOURCE_DIR}/assets")
set(DESTINATION_FOLDER "${CMAKE_BINARY_DIR}")
file(COPY ${SOURCE_FOLDER} DESTINATION ${DESTINATION_FOLDER})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/)

if(WIN32)
    set(SDL2_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/SDL2/SDL2-2.30.2/include")
    set(SDL2_LIBRARY "${PROJECT_SOURCE_DIR}/SDL2/SDL2-2.30.2/lib/x86/SDL2.lib")
    set(SDL2_IMAGE_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/SDL2_image/Windows/SDL2_image-2.8.2/include")
    set(SDL2_IMAGE_LIBRARIES "${PROJECT_SOURCE_DIR}/SDL2_image/Windows/SDL2_image-2.8.2/lib/x86/SDL2_image.lib")
    set(SDL2_DLL "${PROJECT_SOURCE_DIR}/SDL2/SDL2-2.30.2/lib/x86/SDL2.dll")
    set(SDL2_IMAGE_DLL "${PROJECT_SOURCE_DIR}/SDL2_image/Windows/SDL2_image-2.8.2/lib/x86/SDL2_image.dll")

    set(MINGW_BIN_DIR "/usr/x86_64-w64-mingw32/lib")
    set(MINGW_LIB_DIR "/usr/lib/gcc/i686-w64-mingw32/12-win32")

    file(COPY ${SDL2_DLL} DESTINATION ${CMAKE_BINARY_DIR})
    file(COPY ${SDL2_IMAGE_DLL} DESTINATION ${CMAKE_BINARY_DIR})

    file(COPY "${MINGW_BIN_DIR}/libwinpthread-1.dll" DESTINATION ${CMAKE_BINARY_DIR})
    file(COPY "${MINGW_LIB_DIR}/libgcc_s_dw2-1.dll" DESTINATION ${CMAKE_BINARY_DIR})
    file(COPY "${MINGW_LIB_DIR}/libstdc++-6.dll" DESTINATION ${CMAKE_BINARY_DIR})

    include_directories("${SDL2_INCLUDE_DIR}")
    include_directories("${SDL2_IMAGE_INCLUDE_DIRS}")
    target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARIES})
else()
    # Find the libzip package
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(LIBZIP REQUIRED libzip)

    include_directories(${LIBZIP_INCLUDE_DIRS})
    link_directories(${LIBZIP_LIBRARY_DIRS})

    # Find the OpenSSL package
    find_package(OpenSSL REQUIRED)

    # Add include directories for OpenSSL
    include_directories(${OPENSSL_INCLUDE_DIR})
    find_package(PkgConfig REQUIRED)
    pkg_search_module(SDL2 REQUIRED sdl2)
    pkg_search_module(SDL2_image REQUIRED SDL2_image)
    pkg_search_module(SDL2_mixer REQUIRED SDL2_mixer)
    include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_image_INCLUDE_DIRS} ${SDL2_mixer_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR}/AssetsLib)
    link_directories(${CMAKE_SOURCE_DIR}/AssetsLib)
    target_link_libraries(MissileCommand PRIVATE ${SDL2_LIBRARIES} ${SDL2_image_LIBRARIES} ${SDL2_mixer_LIBRARIES} ${CMAKE_SOURCE_DIR}/AssetsLib/libdarwAssets.a ${LIBZIP_LIBRARIES} OpenSSL::SSL OpenSSL::Crypto)
endif()



set(SOURCE_FOLDER "${CMAKE_SOURCE_DIR}/assets")
set(DESTINATION_FOLDER "${CMAKE_BINARY_DIR}")

file(COPY ${SOURCE_FOLDER} DESTINATION ${DESTINATION_FOLDER})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/)
