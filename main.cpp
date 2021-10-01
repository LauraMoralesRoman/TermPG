#include "tpg/framebuffer/FrameBuffer.hpp"
#include "tpg/canvas/canvas.hpp"

#include <iostream>

#include <chrono>
#include <thread>

using namespace std::chrono_literals;

int cnt = 0;
bool direction = true;
void loop(tpg::Canvas<tpg::Color>& canvas) {
    if (direction)
        cnt++;
    else    
        cnt--;
    if (cnt == 255 || cnt == 0) {
        direction = !direction;
    }
    for (int y = 0; y < canvas.height; y++) {
        for (int x = 0; x < canvas.width; x++) {
            canvas.set_pixel(x, y, tpg::Color(x * 255 / canvas.width, y * 255 / canvas.height, cnt));
        }
    }
}

int main() {
    tpg::Canvas canvas;
    canvas.set_frame_rate(60);

    canvas.begin(loop);

    return 0;
}