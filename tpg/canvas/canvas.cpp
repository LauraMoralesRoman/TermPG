#include "canvas.hpp"

#include <thread>
#include <chrono>

// template<typename Color>
// tpg::Canvas<Color>::Canvas(){}

// Implementation of render method
template<typename Color>
void tpg::Canvas<Color>::render() {
    FrameBuffer<Color>::render();
}

template<typename Color>
void tpg::Canvas<Color>::begin(void (*loop)(tpg::Canvas<Color>&)) {
    running_ = true;
    while (running_) {
        auto next_time = std::chrono::steady_clock::now() + ((frame_rate != 0) ? (std::chrono::operator""s(1.0 / (double)frame_rate_)):(0));

        loop(*this);
        render();

        std::this_thread::sleep_until(next_time);
    }
}

// Declaration of all possible types
template class tpg::Canvas<tpg::Color>;
template class tpg::Canvas<tpg::ColorBW>;