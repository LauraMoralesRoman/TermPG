#ifndef DRAWING_ENGINE_
#define DRAWING_ENGINE_

#include "../canvas/canvas.hpp"

namespace tpg {
    template<typename Color>
    class DrawingCanvas : public tpg::Canvas<Color> {
        public:
        DrawingCanvas();
        ~DrawingCanvas();

        void render();
        private:
        uint8_t* z_index_;

        void internal_render_();
    };
}

// Vertex stuff
namespace tpg {
    class Vertex {
        float x, y;
    };

    class Shape {
        public:
        Shape(float* vertices, int* indices, const int num_indices, const int num_vertices, const bool copy = true);
        ~Shape();

        void render(); //Renders the shape
        private:
        float* vertices_;
        int* indices_;
        int index_len_;
    };
}

#endif