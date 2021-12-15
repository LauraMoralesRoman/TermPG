#include "draw.hpp"
#include <string.h>

// Welcome to the internet

template<typename Color>
tpg::DrawingCanvas<Color>::DrawingCanvas()
    : tpg::Canvas<Color>() {
        z_index_ = new uint8_t[Canvas<Color>::width_ * Canvas<Color>::height_];
}

template<typename Color>
tpg::DrawingCanvas<Color>::~DrawingCanvas() {
    delete[] z_index_;
}

// Shapes
tpg::Shape::Shape(float* vertices, int* indices, const int num_vertices, const int num_indices, const bool copy) {
    if (copy) {
        indices_ = new int[num_indices];
        vertices_ = new float[num_vertices];
        memcpy(indices_, indices, sizeof(int) * num_indices);
        memcpy(vertices_, vertices, sizeof(float) * num_vertices);
    } else {
        indices_ = indices;
        vertices_ = vertices;
    }
}

tpg::Shape::~Shape() {
    delete[] indices_;
    delete[] vertices_;
}


// ###################################
// Oh boi, here comes the 3D rendering
// ###################################

template<typename Color>
void tpg::DrawingCanvas<Color>::render() {
    


    // Canvas rendering
    tpg::Canvas<Color>::render();
}

#include <stdio.h>

template<typename Color>
void tpg::DrawingCanvas<Color>::internal_render_() {
    tpg::FrameBuffer<Color>::set_pixel(1, 1, Color(255));
}

// Finishing rendering (jk. this won't end)

void tpg::Shape::render() {
    
}

// Template declaration
template class tpg::DrawingCanvas<tpg::Color>;
template class tpg::DrawingCanvas<tpg::ColorBW>;
