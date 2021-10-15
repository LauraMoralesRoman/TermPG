#include "draw.hpp"
#include <string.h>

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
tpg::Shape::Shape(float* vertices, int* indices, const int num_indices, const int num_vertices, const bool copy) {
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

// Template declaration
template class tpg::DrawingCanvas<tpg::Color>;
template class tpg::DrawingCanvas<tpg::ColorBW>;