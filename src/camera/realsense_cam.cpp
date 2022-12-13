#include "realsense_cam.hpp"
#include <iostream>
#include <memory>

using namespace camera;

RealsenseCamera::RealsenseCamera() : RealsenseCamera(true) {}

RealsenseCamera::RealsenseCamera(bool vizualize) : _vizualize(vizualize) {
  if (_vizualize)
    std::cout << "Started visualization" << std::endl;
  else
    std::cout << "Disabled visualization" << std::endl;
  setup_cam();
  std::cout << "Realsense camera started!" << std::endl;
};

void RealsenseCamera::setup_cam() {
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
  return;
}

void RealsenseCamera::set_visualize(bool viz) { _vizualize = viz; }

void RealsenseCamera::get_stream() {
  rs2::frameset frameset = _pipe.wait_for_frames();
  frameset = _align_to_depth->process(frameset);
  rs2::depth_frame depth = frameset.get_depth_frame();
  rs2::video_frame color = frameset.get_color_frame();
  return;
}
