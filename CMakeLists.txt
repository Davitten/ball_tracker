cmake_minimum_required(VERSION 3.1)

project(ball_tracker)

# Find librealsense2 installed package
find_package(realsense2 REQUIRED)

# Enable C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(SRC_DIR "${PROJECT_SOURCE_DIR}/src/")

file(GLOB SRC "${SRC_DIR}/*.cpp")
file(GLOB HEADERS "${SRC_DIR}/*.hpp")

# Add the application sources to the target
add_executable(${PROJECT_NAME} ${SRC} ${HEADERS})

# Link librealsense2 to the target
target_link_libraries(${PROJECT_NAME} ${realsense2_LIBRARY})