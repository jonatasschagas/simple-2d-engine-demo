# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.22.1)

# Declares and names the project.

project("samplegame")

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../../../../../)
message(STATUS "PROJECT_SOURCE_DIR is: ${PROJECT_SOURCE_DIR}")

set(ANDROID_STL "c++_shared")

set(OPENGL_BACKEND_IMPL ${PROJECT_SOURCE_DIR}/simple-2d-engine/service-implementation/graphics/opengl)
set(INPUT_BACKEND_IMPL ${PROJECT_SOURCE_DIR}/simple-2d-engine//service-implementation/input/android)
set(SOUNDS_BACKEND_IMPL ${PROJECT_SOURCE_DIR}/simple-2d-engine/service-implementation/sounds/android)
set(RESOURCE_PROVIDER_IMPL ${PROJECT_SOURCE_DIR}/simple-2d-engine/service-implementation/disk/android)
set(ENGINE_IMPL ${PROJECT_SOURCE_DIR}/simple-2d-engine/engine)
set(UTILS_IMPL ${PROJECT_SOURCE_DIR}/simple-2d-engine/service-implementation/utils/android)
set(ASSETS ${PROJECT_SOURCE_DIR}/assets)
set(SAMPLE_GAME ${PROJECT_SOURCE_DIR}/src)

message(STATUS "ASSETS is: ${ASSETS}")

# third party libs
set(GLM ${PROJECT_SOURCE_DIR}/simple-2d-engine/third-party/glm)
set(STB ${PROJECT_SOURCE_DIR}/simple-2d-engine/third-party/stb)
set(AUDIO_FILE ${PROJECT_SOURCE_DIR}/simple-2d-engine/third-party/AudioFile)

# adding source files
set(SOURCE_FILES    main.cpp)
file(GLOB_RECURSE SOURCE_FILES *.cpp)
file(GLOB_RECURSE
        OTHER_MODULES_SOURCE_FILES
        ${UTILS_IMPL}/*.cpp
        ${OPENGL_BACKEND_IMPL}/*.cpp
        ${RESOURCE_PROVIDER_IMPL}/*.cpp
        ${INPUT_BACKEND_IMPL}/*.cpp
        ${SOUNDS_BACKEND_IMPL}/*.cpp
        ${ENGINE_IMPL}/*.cpp
        ${SAMPLE_GAME}/*.cpp
        ${AUDIO_FILE}/AudioFile.h
        )
list(APPEND SOURCE_FILES ${OTHER_MODULES_SOURCE_FILES})

# adding third-party deps source code
file(GLOB_RECURSE GLM_CODE ${GLM}/*.h ${GLM}/*.hpp ${GLM}/*.inl)
list(APPEND SOURCE_FILES ${GLM_CODE})
list(APPEND SOURCE_FILES ${STB}/stb_image.h)

# copying assets folder to the "assets" folder from Android
# so we can read the images/shader files
file(MAKE_DIRECTORY ${PROJECT_SOURCE_DIR}/projects/android/app/src/main/assets)
file(COPY ${PROJECT_SOURCE_DIR}/assets DESTINATION ${PROJECT_SOURCE_DIR}projects/android/app/src/main/assets)

add_library( # Sets the name of the library.
        samplegame

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        ${SOURCE_FILES}
        )

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)

# Searches for a package provided by the game activity dependency

find_package(game-activity REQUIRED CONFIG)

# sound lib
find_package(oboe REQUIRED CONFIG)

# include
include_directories(${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
        ${GLM}
        ${RESOURCE_PROVIDER_IMPL}
        ${ENGINE_IMPL}
        ${UTILS_IMPL}
        ${INPUT_BACKEND_IMPL}
        ${OPENGL_BACKEND_IMPL}
        ${SOUNDS_BACKEND_IMPL}
        ${SAMPLE_GAME}
        ${AUDIO_FILE}
        ${STB})


# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
        samplegame

        android

        # The game activity
        game-activity::game-activity

        # EGL, required for configuring the display context
        EGL

        # GL ES 3, used for the sample renderer
        GLESv3

        # for AImageDecoder, to load images from resources
        jnigraphics

        oboe::oboe

        # Links the target library to the log library
        # included in the NDK.
        ${log-lib})