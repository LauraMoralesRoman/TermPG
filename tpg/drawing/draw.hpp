#ifndef DRAWING_ENGINE_
#define DRAWING_ENGINE_

#include "../canvas/canvas.hpp"
#include "renderable.hpp"
#include "engine/vertex.hpp"
#include "engine/projection.hpp"


namespace tpg {
    class Renderable;
    
    template<typename Color>
    class DrawingCanvas : public tpg::Canvas<Color> {
        public:
        using tpg::Canvas<Color>::Canvas;
        ~DrawingCanvas();

        void render();
        virtual void begin(void (*loop)(tpg::DrawingCanvas<Color>&));
        
        template<typename Shape, typename... Args>
        void draw(Args... constructor_args);
        void draw(const Renderable* renderable);
        void draw(const VertexBundle<Color>& vertex_bundle);

        // Matrix operations
        void push_matrix();
        void pop_matrix();

        void rotate(const m_type x, const m_type y, const m_type z);
        void translate(const m_type x, const m_type y, const m_type z);
        void scale(const m_type x, const m_type y, const m_type z);
        private:
        struct TransformStackNode {
            TransformStackNode* next = nullptr;
            Transform transform;
        };
        uint8_t* transform_stack_base = new uint8_t[64 * sizeof(TransformStackNode)];
        TransformStackNode* transform_stack = new (transform_stack_base) TransformStackNode;
        size_t transformation_matrices = 1;

        protected:
        void raster(const Vertex<Color>& a, const Vertex<Color>& b, const Vertex<Color>& c);
    };
}

#endif
