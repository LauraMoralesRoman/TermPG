#include "vertex.hpp"
#include <memory>

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
