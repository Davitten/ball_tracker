#include "camera/camera.hpp"
#include "camera/realsense_cam.hpp"
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

int main() {
  try {
    std::vector<int> a;
    std::unique_ptr<camera::Camera> cam =
        std::make_unique<camera::RealsenseCamera>();
    cam->get_stream();
  } catch (std::runtime_error &e) {
    std::cerr << e.what() << std::endl;
    return -1;
  }
  return 0;
}
