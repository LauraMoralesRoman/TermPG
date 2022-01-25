#include "draw.hpp"
#include "../debug/tpgdebug.hpp"
#include "engine/vector.hpp"

#include "../canvas/canvas.hpp"

#include <cassert>
#include <cstring>

template<typename Color>
tpg::DrawingCanvas<Color>::DrawingCanvas(const size_t width, const size_t height)
    : tpg::Canvas<Color>(width, height) {
    depth_buffer = new v_type[width * height];
}

template<typename Color>
tpg::DrawingCanvas<Color>::DrawingCanvas()
{
    depth_buffer = new v_type[FrameBuffer<Color>::width_ * FrameBuffer<Color>::height_];
}

template<typename Color>
tpg::DrawingCanvas<Color>::~DrawingCanvas() {
    delete[] transform_stack_base;
    delete[] depth_buffer;
}

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


// TODO: revert to template values
template<typename Color>
void tpg::DrawingCanvas<Color>::draw(VertexBundle<Color> const &vb) {
  if (vb.num_indices % 3) {
    tpg::debug_info::error("Number of vertices %u is not divisible by 3. This "
                           "triangle won't be shown");
    return;
  }

  for (size_t i = 0; i < vb.num_indices; i += 3) {
    Vertex<Color> v1 = vb[i];
    Vertex<Color> v2 = vb[i + 1];
    Vertex<Color> v3 = vb[i + 2];

    // Apply transforms to vertices
    TMatrix T = transform_stack->transform.get_matrix();

    T.transform(v1);
    T.transform(v2);
    T.transform(v3);
    
    raster(v1, v2, v3);
  }
}

// Rasterization
template<typename Color>
void tpg::DrawingCanvas<Color>::raster(const Vertex<Color>& a, const Vertex<Color>& b, const Vertex<Color>& c) {
    auto line = [this](const Vertex<Color>& a, const Vertex<Color>& b) {
        Vector3 dir = Vector3(b.x, b.y, b.z) - Vector3(a.x, a.y, a.z);
        for (size_t i = 0; i < dir.mag; i++) {
            Vector3 v = Vector3(dir.norm);
            v *= -(v_type)i;
            
            Vector3 new_pos = v + Vector3(b.x, b.y, b.z);
            if ((new_pos.x >= 0) && (new_pos.x < FrameBuffer<Color>::width_) && (new_pos.y >= 0) && (new_pos.y < FrameBuffer<Color>::height_)) {
                v_type& z_index = depth_buffer[(size_t)(new_pos.x + new_pos.y * FrameBuffer<Color>::height_)];
                if (new_pos.z < z_index) {
                    FrameBuffer<Color>::set_pixel(v.x + b.x, v.y + b.y, Color::mix(a.color, b.color, (float)i / dir.mag));
                    z_index = new_pos.z;
                }
            }
        }
    };

    line(a, b);
    line(a, c);
    line(b, c);
}

// Matrix operations
template<typename Color>
void tpg::DrawingCanvas<Color>::push_matrix() {
    TransformStackNode* tmp = transform_stack; 
    transform_stack = new (transform_stack_base + transformation_matrices * sizeof(TransformStackNode)) TransformStackNode;
    transform_stack->next = tmp;

    // Apply transform
    transform_stack->transform = transform_stack->next->transform;

    transformation_matrices++;
}

template<typename Color>
void tpg::DrawingCanvas<Color>::pop_matrix() {
    if (transformation_matrices == 1)
        return;

    transform_stack = transform_stack->next;

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

template<typename Color>
void tpg::DrawingCanvas<Color>::pre_loop_() {
    memset(depth_buffer, 0b01111111, sizeof(v_type) * FrameBuffer<Color>::width_ * FrameBuffer<Color>::height_);
}

// Possible template values
template class tpg::DrawingCanvas<tpg::Color>;
template class tpg::DrawingCanvas<tpg::ColorBW>;
