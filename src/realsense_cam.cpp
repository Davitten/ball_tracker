#include "realsense_cam.hpp"
#include <iostream>
#include <memory>

using namespace camera;

RealsenseCamera::RealsenseCamera() {
  // Check if any realsense device is connected
  rs2::context ctx;
  auto list =
      ctx.query_devices(); // Get a snapshot of currently connected devices
  if (list.size() == 0)
    throw std::runtime_error("No device detected. Is it plugged in?");
  // setup streams
  const int HEIGHT = 480;
  const int C_WIDTH = 640;
  const int D_WIDTH = 640;
  const int FPS = 30;
  _cfg.enable_stream(RS2_STREAM_COLOR, C_WIDTH, HEIGHT, RS2_FORMAT_RGB8, FPS);
  _cfg.enable_stream(RS2_STREAM_DEPTH, D_WIDTH, HEIGHT, RS2_FORMAT_Z16, FPS);
  _pipe.start(_cfg);
  _align_to_depth = std::make_unique<rs2::align>(RS2_STREAM_DEPTH);
  _align_to_color = std::make_unique<rs2::align>(RS2_STREAM_COLOR);
  std::cout << "Realsense camera started!" << std::endl;
};

void RealsenseCamera::get_stream() {
  rs2::frameset frameset = _pipe.wait_for_frames();
  frameset = _align_to_depth->process(frameset);
  auto depth = frameset.get_depth_frame();
  auto color = frameset.get_color_frame();
  return;
}
