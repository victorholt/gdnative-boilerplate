cmake_minimum_required(VERSION 3.10)
project(GodotProject) # Change to your project name

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 99)

# Setup the build locations.
if (CMAKE_BUILD_TYPE MATCHES Debug)
    add_definitions(-DSYMPL_DEBUG)
    set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/gdnative/builds/debug)
    set (CMAKE_LIBRARY_OUTPUT_DIRECTORY  ${PROJECT_SOURCE_DIR}/gdnative/builds/debug)
    set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/gdnative/builds/debug)
else ()
    set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/gdnative/builds/release)
    set (CMAKE_LIBRARY_OUTPUT_DIRECTORY  ${PROJECT_SOURCE_DIR}/gdnative/builds/release)
    set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/gdnative/builds/release)
endif ()

# Apple-specific libraries.
list (APPEND GodotAppleLibs "")
if (APPLE)
    if (IOS OR TVOS)
        list (APPEND GodotAppleLibs
            "-framework Foundation"
            "-framework QuartzCore"
        )
    else ()
        list (APPEND GodotAppleLibs
            "-framework CoreFoundation"
            "-framework SystemConfiguration"
            "-framework CoreServices"
        )
    endif ()
endif ()

# Set the base directory for the source.
set (GODOT_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/gdnative/godot-cpp")
set (GODOT_HEADERS_DIR "${GODOT_SOURCE_DIR}/godot_headers")
set (MODULES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/gdnative/src")

# Setup our common directory.
set (GODOT_INCLUDES
    "${GODOT_SOURCE_DIR}/include"
    "${GODOT_SOURCE_DIR}/include/core"
    "${GODOT_SOURCE_DIR}/include/gen"
    "${GODOT_HEADERS_DIR}"
    "${MODULES_DIR}/godotproject"
)
set (GODOT_SOURCES)

# Setup our includes.
include_directories(${GODOT_INCLUDES})

include(${MODULES_DIR}/godotlib/CMakeLists.txt)
include(${MODULES_DIR}/godotproject/CMakeLists.txt)

# Custom command.
# Uncomment if you're on Windows and have Go installed
# if (WIN32)
#     add_custom_command(TARGET GodotProjectLib POST_BUILD
#             COMMAND go run ${CMAKE_CURRENT_SOURCE_DIR}/gdnative/bin/postbuild.go
#             COMMENT "Running postbuild.go script"
#     )
# endif ()
