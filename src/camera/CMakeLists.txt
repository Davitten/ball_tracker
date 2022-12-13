cmake_minimum_required(VERSION 3.1.0)

project(camera)

# Find librealsense2 installed package
find_package(realsense2 REQUIRED)

# Enable C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

file(GLOB SRC "*.cpp" "*.hpp")

# Create library target camera
add_library(${PROJECT_NAME} ${SRC})

# Link librealsense2 to the target
target_link_libraries(${PROJECT_NAME} ${realsense2_LIBRARY})
