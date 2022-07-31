cmake_minimum_required(VERSION 3.2)

# Initializing of internal variables
set(PROJECT_NAME "default" CACHE INTERNAL "Project name")
set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})
project(${PROJECT_NAME} VERSION ${PROJECT_VESRION})

# Initializing of test environment option 
option(WITH_GOOGLE_TEST "Whether to build Google test" OFF)

# Checking version number 
configure_file(version.h.in version.h)

add_executable(${PROJECT_NAME}_cli main.cpp)
add_library(${PROJECT_NAME} lib.cpp)

# Adding library and test environment folders
add_subdirectory(test_env)

set_target_properties(${PROJECT_NAME}_cli ${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(${PROJECT_NAME}
    PRIVATE "${CMAKE_BINARY_DIR}"
)

target_link_libraries(${PROJECT_NAME}_cli PRIVATE
    ${PROJECT_NAME}
)

if(WITH_GOOGLE_TEST)
    #find_package(Boost COMPONENTS unit_test_framework REQUIRED)
    add_executable(test_version test_env/run_tests.cpp)

    set_target_properties(test_version PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
    )

    #set_target_properties(test_version PROPERTIES
    #    COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
    #    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
    #)

    #target_link_libraries(test_version
    #    ${Boost_LIBRARIES}
    #    ${PROJECT_NAME}
    #)
endif()

if (MSVC)
    target_compile_options(${PROJECT_NAME}_cli PRIVATE
        /W4
    )
    target_compile_options(${PROJECT_NAME} PRIVATE
        /W4
    )
    if(WITH_GOOGLE_TEST)
        target_compile_options(test_version PRIVATE
            /W4
        )
    endif()
else ()
    target_compile_options(${PROJECT_NAME}_cli PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(${PROJECT_NAME} PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    if(WITH_GOOGLE_TEST)
        target_compile_options(test_version PRIVATE
            -Wall -Wextra -pedantic -Werror
        )
    endif()
endif()

install(TARGETS ${PROJECT_NAME}_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT m.nartov24@yandex.ru)
include(CPack)

if(WITH_GOOGLE_TEST)
    enable_testing()
    add_test(test_version test_version)
endif()
