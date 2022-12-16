cmake_minimum_required(VERSION 3.1.0)

project(ball_tracker)

# Enable C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(SRC_DIR "${PROJECT_SOURCE_DIR}/src")
set(THIRD_PARTY "${PROJECT_SOURCE_DIR}/third-party")


add_subdirectory("${SRC_DIR}/camera")

message("Adding third party dependencies")
add_subdirectory("${THIRD_PARTY}/opencv")

# Add the application sources to the target
add_executable(${PROJECT_NAME} "src/main.cpp")

# Link libraries to the ball_tracker target
target_link_libraries(${PROJECT_NAME}
    PUBLIC camera
    ${OpenCV_LIBS})

target_include_directories(${PROJECT_NAME}
    PUBLIC "${SRC_DIR}"
    ${OpenCV_INCLUDE_DIRS} )

find_package( OpenCV REQUIRED )
include_directories( )
