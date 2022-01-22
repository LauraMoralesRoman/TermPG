#include "tpg/framebuffer/FrameBuffer.hpp"
#include "tpg/canvas/canvas.hpp"
#include "tpg/drawing/draw.hpp"
#include "tpg/drawing/renderable.hpp"
#include "tpg/drawing/vertex.hpp"
#include "tpg/drawing/engine/vector.hpp"
#include "tpg/drawing/engine/projection.hpp"

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

    canvas.draw(vb);
    canvas.debug_flags |= canvas.FPS;   

    // Pruebas con vértices
    //canvas.begin(loop);

    tpg::TMatrix m{ 1, 2, 3, 4,
                    5, 6, 7, 8,
                    9, 10, 11, 12,
                    13, 14, 15, 16};
    tpg::TMatrix m2{16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    m *= m2;

    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            std::cout << m[y][x] << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}
