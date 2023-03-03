cmake_minimum_required(VERSION 3.2)

set(PROJECT_NAME "default" CACHE INTERNAL "Project name")
set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

set(binFolder, "${CMAKE_SOURCE_DIR}/bin")
set(testFolder, "${CMAKE_SOURCE_DIR}/test")

project(${PROJECT_NAME} VERSION ${PROJECT_VESRION})
option(GTEST "Unit test via GTest" ON)

configure_file(version.h.in version.h)

add_subdirectory(src)

if (GTEST) 
    add_subdirectory(googletest)
    enable_testing()
    add_subdirectory(ut) 
endif()

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT m.nartov24@yandex.ru)
include(CPack)
