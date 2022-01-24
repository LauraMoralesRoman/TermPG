#ifndef RENDERABLE_HPP
#define RENDERABLE_HPP

#include "draw.hpp"
#include "engine/vertex.hpp"

namespace tpg {
    class VertexBundle;

    class Renderable {
        public:
        virtual const VertexBundle& get_bundle() const = 0;
    };
};

#endif
