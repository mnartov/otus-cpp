cmake_minimum_required(VERSION 3.2)

set(projectExecute ${PROJECT_NAME}_cli)
set(projectLib ${PROJECT_NAME})

add_library(projectLib lib.cpp)

add_executable(projectExecute main.cpp)

target_link_libraries(projectExecute projectLib)

target_include_directories(projectLib PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

set_target_properties(projectExecute projectLib PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)

target_compile_options(projectExecute PRIVATE
-Wall -Wextra -pedantic -Werror
)

target_compile_options(projectLib PRIVATE
-Wall -Wextra -pedantic -Werror
)

install(TARGETS projectExecute RUNTIME DESTINATION binFolder)