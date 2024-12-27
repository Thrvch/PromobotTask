cmake_minimum_required(VERSION 3.5.0)
project(PromobotTask VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SOURCES
    src/sort.cpp
    src/shapeClasses.cpp
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
add_library(list_lib STATIC ${SOURCES})
target_include_directories(list_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(PromobotTask main.cpp src/sort.cpp src/shapeClasses.cpp)
