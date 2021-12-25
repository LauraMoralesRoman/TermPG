#include "tpg/framebuffer/FrameBuffer.hpp"
#include "tpg/canvas/canvas.hpp"
#include "tpg/drawing/draw.hpp"
#include "tpg/drawing/renderable.hpp"
#include "tpg/drawing/vertex.hpp"
#include "tpg/drawing/engine/vector.hpp"

#include <iostream>

#include <chrono>
#include <thread>
#include <memory>

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

int main() {
    tpg::DrawingCanvas<tpg::Color> canvas;
    canvas.set_frame_rate(24);

    tpg::VertexBundle vb(3, 3);
    vb.indices[0] = 2;
    vb[0] = {1, 2, 3};

    tpg::Vector3 v(1, 2, 3);
    tpg::Vector3 v2(2, 3, 4);
    v += v2;
    v *= 1.2;
    tpg::Vector3 res = v;
    printf("%f %f %f\n", res.x, res.y, res.z);
    printf("%f %f %f\n", res.norm.x, res.norm.y, res.norm.z);
    return 0;
}
