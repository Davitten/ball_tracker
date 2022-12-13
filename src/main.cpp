#include "camera.hpp"
#include "realsense_cam.hpp"
#include <iostream>
#include <memory>

using namespace std;

int main() {
  try {
    std::unique_ptr<camera::Camera> cam =
        std::make_unique<camera::RealsenseCamera>();
    cam->get_stream();
  } catch (std::runtime_error &e) {
    std::cerr << e.what() << std::endl;
    return -1;
  }
  return 0;
}
