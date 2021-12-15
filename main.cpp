#include "tpg/framebuffer/FrameBuffer.hpp"
#include "tpg/canvas/canvas.hpp"
#include "tpg/drawing/draw.hpp"

#include <iostream>

#include <chrono>
#include <thread>

using namespace std::chrono_literals;

int cnt = 0;
void loop(tpg::Canvas<tpg::Color>& canvas) {
    for (int y = 0; y < canvas.height; y++) {
        for (int x = 0; x < canvas.width; x++) {
            canvas.set_pixel(x, y, tpg::Color(x * 255 / canvas.width, y * 255 / canvas.height, cnt % 255));
        }
    }
    cnt++;
}

float tri[] = {
    1
};
int main() {

    tpg::DrawingCanvas<tpg::Color> canvas;
    canvas.set_frame_rate(24);

    canvas.debug_flags |= canvas.FPS;   

    canvas.begin(loop);

    return 0;
}
