#ifndef DRAWING_ENGINE_
#define DRAWING_ENGINE_

#include "../canvas/canvas.hpp"
#include "renderable.hpp"
#include "vertex.hpp"


namespace tpg {
    class Renderable;
    
    template<typename Color>
    class DrawingCanvas : public tpg::Canvas<Color> {
        public:
        void render();
        
        template<typename Shape, typename... Args>
        void draw(Args... constructor_args);
        void draw(const Renderable* renderable);
        void draw(const VertexBundle& vertex_bundle) const;

        private:
    };
}

#endif
