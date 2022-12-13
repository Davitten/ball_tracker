#pragma once
#include "camera.hpp"
#include <librealsense2/rs.hpp> // Include Intel RealSense Cross Platform API
#include <memory>

namespace camera{
    class RealsenseCamera : public Camera
    {
    public:
        RealsenseCamera();
        void get_stream() override;
    private:
        // create ptrs to avoid making multiple objects in main loop for performance
        std::unique_ptr<rs2::align> _align_to_depth;
        std::unique_ptr<rs2::align> _align_to_color;
        rs2::pipeline _pipe;
        rs2::config _cfg;
    };
} // namespace camera