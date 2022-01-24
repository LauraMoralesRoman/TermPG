#include "vertex.hpp"
#include <memory>

tpg::Vertex::V3 tpg::Vertex::get_aprox() {
    V3 tmp;
    tmp.x = ((v_type)(x - (size_t)x) < 0.5) ? (size_t)x:(size_t)x+1;
    tmp.y = ((v_type)(y - (size_t)y) < 0.5) ? (size_t)y:(size_t)y+1;
    tmp.z = ((v_type)(z - (size_t)z) < 0.5) ? (size_t)z:(size_t)z+1;
    return tmp;
}
// Vertex bundle

tpg::VertexBundle::VertexBundle(const size_t num_indices, const size_t num_vertices, const std::shared_ptr<Vertex> vertices, const std::shared_ptr<size_t> indices)
    : num_indices_(num_indices), num_vertices_(num_vertices), indices_(indices), vertices_(vertices) {
    this->indices = indices.get();
}

tpg::VertexBundle::VertexBundle(const size_t num_vertices, std::shared_ptr<Vertex> vertices, VGroupModes mode)
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

tpg::VertexBundle::VertexBundle(const size_t num_vertices, const size_t num_indices)
    : num_indices_(num_indices), num_vertices_(num_vertices) {
    vertices_ = std::shared_ptr<tpg::Vertex>(new tpg::Vertex[num_vertices], std::default_delete<tpg::Vertex[]>());
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
std::shared_ptr<tpg::Vertex> tpg::create_vertex_array(const size_t size) {
    return std::shared_ptr<tpg::Vertex>(new tpg::Vertex[size], std::default_delete<tpg::Vertex[]>());
}

std::shared_ptr<tpg::size_t> tpg::create_index_array(const size_t size) {
    return std::shared_ptr<tpg::size_t>(new tpg::size_t[size], std::default_delete<tpg::size_t[]>());
}
