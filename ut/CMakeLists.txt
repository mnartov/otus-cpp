cmake_minimum_required(VERSION 3.2)

set(projectUnitTests ${PROJECT_NAME}Tests)
add_executable(projectUnitTests testMain.cpp)

target_include_directories(projectUnitTests PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(projectUnitTests projectLib)

target_include_directories(projectUnitTests PRIVATE ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
target_link_libraries(projectUnitTests gtest gtest_main)

add_test(NAME projectUnitTests COMMAND projectUnitTests)

install(TARGETS projectUnitTests
        DESTINATION testFolder)




