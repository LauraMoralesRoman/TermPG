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

void loop(tpg::DrawingCanvas<tpg::Color>& canvas) {
    tpg::VertexBundle vb(3, 3);
    vb.indices[0] = 2;
    vb[0] = {-0.5, -0.5, 0};
    vb[1] = {-0.5, 0.5, 0};
    vb[2] = {0.5, -0.5, 0};
    
    static float angle = 0;
    tpg::Color black{0, 0, 0};
    canvas.clear(black);
    canvas.rotate(0, 0, 0.05);
    canvas.draw(vb);
}

int main() {
    tpg::DrawingCanvas<tpg::Color> canvas;
    canvas.set_frame_rate(24);
    canvas.translate(50, 30, 0);
    canvas.scale(10, 10, 10);

    //canvas.debug_flags |= canvas.FPS;   
    tpg::VertexBundle vb(3, 3);
    vb.indices[0] = 2;
    vb[0] = {-25, -25, 0};
    vb[1] = {-25, 25, 0};
    vb[2] = {25, -25, 0};


    //canvas.render();

    // Pruebas con vértices
    //canvas.begin(loop);
    canvas.begin(loop);


    return 0;
}
////////////
