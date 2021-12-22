#include "draw.hpp"
#include <cassert>
#include "../debug/tpgdebug.hpp"

template<typename Color>
void tpg::DrawingCanvas<Color>::render() {
  Canvas<Color>::render();
}

template<typename Color>
void tpg::DrawingCanvas<Color>::draw(const Renderable* renderable) {
    draw(renderable->get_bundle());
}
//#############################################
// 3D render engine
// ##############################################

template<typename Color>
void tpg::DrawingCanvas<Color>::draw(VertexBundle const& vb) const {
    if (vb.num_indices % 3) {
        tpg::debug_info::error("Number of vertices %u is not divisible by 3. This triangle won't be shown"); 
        return;
    }
    
    for (size_t i = 0; i < vb.num_indices; i+= 3) {
        Vertex v1 = vb[i];
        Vertex v2 = vb[i + 1];
        Vertex v3 = vb[i + 2];

        // Apply transforms to vertices
        
    }
}

// Possible template values
template class tpg::DrawingCanvas<tpg::Color>;
template class tpg::DrawingCanvas<tpg::ColorBW>;

