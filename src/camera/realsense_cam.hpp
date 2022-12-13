#pragma once
#include "camera.hpp"
#include <librealsense2/rs.hpp> // Include Intel RealSense Cross Platform API
#include <memory>

namespace camera {
class RealsenseCamera : public Camera {
public:
  RealsenseCamera();
  RealsenseCamera(bool);
  void get_stream() override;
  void set_visualize(bool) override;

private:
  void setup_cam();
  // create ptrs to avoid making multiple objects in main loop for performance
  std::unique_ptr<rs2::align> _align_to_depth, _align_to_color;
  rs2::pipeline _pipe;
  rs2::config _cfg;
  bool _vizualize;
};
} // namespace camera
