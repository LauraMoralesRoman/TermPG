#include "tpg/framebuffer/FrameBuffer.hpp"
#include "tpg/canvas/canvas.hpp"

#include <iostream>

#include <chrono>
#include <thread>

using namespace std::chrono_literals;

int cnt = 0;
bool direction = true;
void loop(tpg::Canvas<tpg::Color>& canvas) {
    // if (direction)
    //     cnt++;
    // else    
    //     cnt--;
    // if (cnt == 255 || cnt == 0) {
    //     direction = !direction;
    // }
    // for (int y = 0; y < canvas.height; y++) {
    //     for (int x = 0; x < canvas.width; x++) {
    //         canvas.set_pixel(x, y, tpg::Color(x * 255 / canvas.width, y * 255 / canvas.height, cnt));
    //     }
    // }

    tpg::Color random(rand() % 255, rand() % 255, rand() % 255);
    canvas.set_pixel(rand() % (canvas.width - 1), rand() % (canvas.height - 1), random);

    for (int y = 0; y < canvas.height; y++) {
        for (int x = 0; x < canvas.width; x++) {
            canvas.set_pixel(x,y, tpg::Color(0, 0, 0, 1));
        }
        canvas.set_pixel(10, y, tpg::Color(255, 255, 255));
    }  


    canvas.set_pixel(1, 1, tpg::Color(0, 0, 10));
}

int main() {
    tpg::Canvas<tpg::Color> canvas;
    canvas.set_frame_rate(60);

    // canvas.begin(loop);

    for (int y = 0; y < canvas.height; y++) {
        for (int x = 0; x < canvas.width; x++) {
            canvas.set_pixel(x, y, tpg::Color(255, 255, 255, 127));
            if (x % 10 == 0)
                canvas.set_pixel(x, y, tpg::Color(255, 255, 255));
        }
    }

    canvas.render();

    return 0;
}