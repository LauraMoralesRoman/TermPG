#ifndef DRAWING_ENGINE_
#define DRAWING_ENGINE_

#include "../canvas/canvas.hpp"
#include "renderable.hpp"
#include "vertex.hpp"
#include "engine/projection.hpp"


namespace tpg {
    class Renderable;
    
    template<typename Color>
    class DrawingCanvas : public tpg::Canvas<Color> {
        public:
        void render();
        virtual void begin(void (*loop)(tpg::DrawingCanvas<Color>&));
        
        template<typename Shape, typename... Args>
        void draw(Args... constructor_args);
        void draw(const Renderable* renderable);
        void draw(const VertexBundle& vertex_bundle);

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
        TransformStackNode* transform_stack = new TransformStackNode;
        size_t transformation_matrices = 1;
    };
}

#endif
