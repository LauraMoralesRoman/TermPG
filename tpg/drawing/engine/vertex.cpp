#include "vertex.hpp"
#include <memory>

template<typename Color>
typename tpg::Vertex<Color>::V3 tpg::Vertex<Color>::get_aprox() {
    V3 tmp;
    tmp.x = ((v_type)(x - (size_t)x) < 0.5) ? (size_t)x:(size_t)x+1;
    tmp.y = ((v_type)(y - (size_t)y) < 0.5) ? (size_t)y:(size_t)y+1;
    tmp.z = ((v_type)(z - (size_t)z) < 0.5) ? (size_t)z:(size_t)z+1;
    return tmp;
}
// Vertex bundle

template<typename Color>
tpg::VertexBundle<Color>::VertexBundle(const size_t num_indices, const size_t num_vertices, const std::shared_ptr<Vertex<Color>> vertices, const std::shared_ptr<size_t> indices)
    : num_indices_(num_indices), num_vertices_(num_vertices), indices_(indices), vertices_(vertices) {
    this->indices = indices.get();
}

template<typename Color>
tpg::VertexBundle<Color>::VertexBundle(const size_t num_vertices, std::shared_ptr<Vertex<Color>> vertices, VGroupModes mode)
    : num_vertices_(num_vertices), vertices_(vertices) {
    // Automatically create vertices
    switch (mode) {
        case VGroupModes::TRIS: {
                                    // TODO: implement automatic creation of indices
                                    break;
                                }
    }
    this->indices = indices_.get();
}

template<typename Color>
tpg::VertexBundle<Color>::VertexBundle(const size_t num_vertices, const size_t num_indices)
    : num_indices_(num_indices), num_vertices_(num_vertices) {
    vertices_ = std::shared_ptr<tpg::Vertex<Color>>(new tpg::Vertex<Color>[num_vertices], std::default_delete<tpg::Vertex<Color>[]>());
    indices_ = std::shared_ptr<tpg::size_t>(new tpg::size_t[num_indices], std::default_delete<tpg::size_t[]>());
    indices = indices_.get();
}

// VertexBundleIterator
tpg::VertexBundleIndexIterator::VertexBundleIndexIterator(size_t* current)
    : current(current) {}

void tpg::VertexBundleIndexIterator::operator++() {
    current++;
}

bool tpg::VertexBundleIndexIterator::operator!=(const VertexBundleIndexIterator &other) {
    return current != other.current;
}

tpg::size_t tpg::VertexBundleIndexIterator::operator*() {
    return *current;
}

// Array aiding methods
template<typename Color>
std::shared_ptr<tpg::Vertex<Color>> tpg::create_vertex_array(const size_t size) {
    return std::shared_ptr<tpg::Vertex<Color>>(new tpg::Vertex<Color>[size], std::default_delete<tpg::Vertex<Color>[]>());
}

std::shared_ptr<tpg::size_t> tpg::create_index_array(const size_t size) {
    return std::shared_ptr<tpg::size_t>(new tpg::size_t[size], std::default_delete<tpg::size_t[]>());
}


template class tpg::Vertex<tpg::Color>;
template class tpg::Vertex<tpg::ColorBW>;
template class tpg::VertexBundle<tpg::Color>;
template class tpg::VertexBundle<tpg::ColorBW>;
