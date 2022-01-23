#include "draw.hpp"
#include "../debug/tpgdebug.hpp"
#include <cassert>

template <typename Color> void tpg::DrawingCanvas<Color>::render() {
  Canvas<Color>::render();
}

template<typename Color>
void tpg::DrawingCanvas<Color>::begin(void (*loop)(tpg::DrawingCanvas<Color> &)) {
    Canvas<Color>::begin_([&]() {
        loop(*this);
    });
}

//#############################################
// 3D render engine
// ##############################################


#include <iostream>
// TODO: revert to template values
template <>
void tpg::DrawingCanvas<tpg::Color>::draw(VertexBundle const &vb) {
  if (vb.num_indices % 3) {
    tpg::debug_info::error("Number of vertices %u is not divisible by 3. This "
                           "triangle won't be shown");
    return;
  }

  for (size_t i = 0; i < vb.num_indices; i += 3) {
    Vertex v1 = vb[i];
    Vertex v2 = vb[i + 1];
    Vertex v3 = vb[i + 2];

    // Apply transforms to vertices
    TMatrix T = transform_stack->transform.get_matrix();

    T.transform(v1);
    T.transform(v2);
    T.transform(v3);
    
    Vertex::V3 vv1 = v1.get_aprox();
    Vertex::V3 vv2 = v2.get_aprox();
    Vertex::V3 vv3 = v3.get_aprox();


    FrameBuffer<Color>::set_pixel(vv1.x, vv1.y, {255, 0, 0});
    FrameBuffer<Color>::set_pixel(vv2.x, vv2.y, {0, 255, 0});
    FrameBuffer<Color>::set_pixel(vv3.x, vv3.y, {0, 0, 255});
  }
}

template<typename Color>
void tpg::DrawingCanvas<Color>::draw(VertexBundle const &vb) {

}

// Matrix operations
template<typename Color>
void tpg::DrawingCanvas<Color>::push_matrix() {
    TransformStackNode* tmp = transform_stack; 
    transform_stack = new TransformStackNode;
    transform_stack->next = tmp;

    // Apply transform
    transform_stack->transform = transform_stack->next->transform;

    transformation_matrices++;
}

template<typename Color>
void tpg::DrawingCanvas<Color>::pop_matrix() {
    if (transformation_matrices == 1)
        return;

    TransformStackNode* tmp = transform_stack->next;
    delete transform_stack;
    transform_stack = tmp;

    transformation_matrices--;
}

template<typename Color>
void tpg::DrawingCanvas<Color>::translate(const m_type x, const m_type y, const m_type z) {
    transform_stack->transform.translate(x, y, z);
}

template<typename Color>
void tpg::DrawingCanvas<Color>::rotate(const m_type x, const m_type y, const m_type z) {
    transform_stack->transform.rotate(x, y, z);
}

template<typename Color>
void tpg::DrawingCanvas<Color>::scale(const m_type x, const m_type y, const m_type z) {
    transform_stack->transform.scale(x, y, z);
}

// Possible template values
template class tpg::DrawingCanvas<tpg::Color>;
template class tpg::DrawingCanvas<tpg::ColorBW>;
