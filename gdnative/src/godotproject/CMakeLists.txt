# Header and src files.
file (GLOB GODOTPROJECT_HEADERS
    "${MODULES_DIR}/godotproject/*.hpp"
    "${MODULES_DIR}/godotproject/controllers/*.hpp"
    "${MODULES_DIR}/godotproject/entity/*.hpp"
)

file (GLOB GODOTPROJECT_SRC
    "${MODULES_DIR}/godotproject/*.cpp"
    "${MODULES_DIR}/godotproject/controllers/*.cpp"
    "${MODULES_DIR}/godotproject/entity/*.cpp"
)

add_library(
    GodotProjectLib SHARED
    ${GODOTPROJECT_HEADERS} ${GODOTPROJECT_SRC}
)

target_link_libraries(
    GodotProjectLib
    ${GodotAppleLibs}
    GodotCppLib
)

if (WIN32)
    set_property(TARGET GodotProjectLib PROPERTY IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/builds/${CMAKE_BUILD_TYPE}/GodotProject.dll)
    set_property(TARGET GodotProjectLib PROPERTY IMPORTED_IMPLIB ${PROJECT_SOURCE_DIR}/builds/${CMAKE_BUILD_TYPE}/GodotProject.a)
else ()
    set_property(TARGET GodotProjectLib PROPERTY IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/builds/${CMAKE_BUILD_TYPE}/GodotProject.dylib)
endif ()
