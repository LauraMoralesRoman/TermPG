#ifndef FRAME_BUFFER
#define FRAME_BUFFER

typedef __SIZE_TYPE__ size_t;

// Frame Buffer
namespace tpg {
    extern size_t termW, termH;

    // FrameBuffer
    class FrameBuffer {
        public:
        FrameBuffer(size_t width, size_t height);
        FrameBuffer();

        private:
        size_t width_, height_;
    };

    namespace __impl {
        char start_code();
    }
}

// Colors TODO: color definition and implementation
namespace tpg {

    class Color {

    };


    namespace __impl {
        class ColorRGB {

        };

        class ColorRGBA {

        };
    }
}

#endif