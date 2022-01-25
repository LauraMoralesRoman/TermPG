#ifndef VERTEX_H
#define VERTEX_H

// TODO: Terminar el iterador, pensar si se quiere hacer el por defecto para índices o para vertices

#include <memory>
#include "../../framebuffer/FrameBuffer.hpp"

namespace tpg {
  typedef unsigned long long int size_t;

  template<typename Color = tpg::Color>
  struct Vertex {
    typedef double v_type;
    struct V3 {
        size_t x = 0, y = 0, z = 0;
    };
    v_type x = 0, y = 0, z = 0;
    Color color;
    V3 get_aprox();
  };

  enum class VGroupModes {
    /**
      * @brief Selects groups of 3 vertices and creates a tri (basically creating a sequence)
      */
    TRIS,

  };

  /**
    * @brief Stores an array of vertices and deletes it when not in use (like a shared pointer)
    */
  template<typename Color = tpg::Color>
  class VertexBundle {
    public:
    VertexBundle() = default;
    VertexBundle(const size_t num_indices, const size_t num_vertices, std::shared_ptr<Vertex<Color>> vertices, std::shared_ptr<size_t> indices);
    VertexBundle(const size_t num_vertices, std::shared_ptr<Vertex<Color>> vertices, VGroupModes mode);
    VertexBundle(const size_t num_vertices, const size_t num_indices);

    // Sintax sugar operators
    Vertex<Color>& operator[](const size_t index) { return vertices_.get()[index]; }
    const Vertex<Color>& operator[](const size_t index) const { return vertices_.get()[index]; }
    size_t * indices; 

    const size_t& num_vertices = num_vertices_;
    const size_t& num_indices = num_indices_;
    private:
    const size_t num_vertices_ = 0;
    const size_t num_indices_ = 0;
        
    std::shared_ptr<size_t> indices_;
    std::shared_ptr<Vertex<Color>> vertices_;
  };

  // Methods for aiding creation of arrays
  std::shared_ptr<size_t> create_index_array(const size_t size);
  template<typename Color>
  std::shared_ptr<Vertex<Color>> create_vertex_array(const size_t size);
    class VertexBundleIndexIterator {
        public:
        VertexBundleIndexIterator(size_t* current);

        void operator++();
        bool operator!=(const VertexBundleIndexIterator& other);
        tpg::size_t operator*();

        private:
        tpg::size_t* current;
    };
};


#endif

