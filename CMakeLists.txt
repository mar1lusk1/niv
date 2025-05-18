cmake_minimum_required(VERSION 3.6)

project("niv")

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_COMPILER "clang")

file(GLOB_RECURSE SRC_FILES src/*.c src/*.h)

add_executable(${PROJECT_NAME} src/main.c ${SRC_FILES})

find_package(SDL3 REQUIRED)
target_link_libraries(${PROJECT_NAME} ${SDL3_LIBRARIES})