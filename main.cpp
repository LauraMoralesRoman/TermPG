#include "tpg/framebuffer/FrameBuffer.hpp"
#include "tpg/canvas/canvas.hpp"
#include "tpg/drawing/draw.hpp"
#include "tpg/drawing/renderable.hpp"
#include "tpg/drawing/engine/vertex.hpp"
#include "tpg/drawing/engine/vector.hpp"
#include "tpg/drawing/engine/projection.hpp"

#include <iostream>

#include <chrono>
#include <thread>
#include <memory>

#include <unistd.h>

#include <math.h>

using namespace std::chrono_literals;

float u_time = 0;
void loop(tpg::DrawingCanvas<tpg::Color>& canvas) {
    u_time += canvas.delta_time;
    float scale = (std::cos(u_time) + 1.5);

    tpg::VertexBundle vb(3, 3);
    vb.indices[0] = 2;
    vb[0] = {-0.5, -0.5, 0};
    vb[1] = {-0.5, 0.5, 0};
    vb[2] = {0.5, -0.5, 0};
    
    static float angle = 0;
    tpg::Color black{0, 0, 0};
    canvas.clear(black);
    canvas.rotate(0, 0.05, 0.05);
    canvas.push_matrix();
    canvas.scale(scale, scale, scale);
    canvas.draw(vb);
    canvas.pop_matrix();
}

int main() {
    tpg::DrawingCanvas<tpg::Color> canvas;
    canvas.set_frame_rate(24);

    canvas.translate(50, 40, 0);
    canvas.scale(30, 30, 30);
    //canvas.render();

    tpg::Color c{255, 0, 0};
    /*canvas.set_pixel(0, 0, c);
    canvas.set_pixel(canvas.width-1, 0, c);
    canvas.set_pixel(canvas.width-1, canvas.height-1, c);
    canvas.set_pixel(0, canvas.height-1, c);*/

    // Pruebas con vértices
    canvas.begin(loop);



    return 0;
}
////////////
