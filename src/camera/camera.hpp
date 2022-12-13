#pragma once

namespace camera {
class Camera {
public:
  Camera() = default;
  virtual void get_stream() = 0;
  virtual void set_visualize(bool) = 0;
};
} // namespace camera
