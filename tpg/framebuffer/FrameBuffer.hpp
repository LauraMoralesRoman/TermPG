#ifndef FRAME_BUFFER
#define FRAME_BUFFER

typedef unsigned int size_t;

namespace tpg {
    template<typename Color>
    class FrameBuffer {
        public:
        FrameBuffer(size_t width, size_t height);
        FrameBuffer();

        void render();
        private:
        Color* internal;
    };
}

// Hidden implementation details
namespace impl {
    // Run before main()
    #include <stdio.h>
    bool start() {
        printf("Hola mundo");

        return true;
    }

    volatile bool runned = start();
}

// Class implementation
template<typename Color>
tpg::FrameBuffer<Color>::FrameBuffer() {

}

template<typename Color>
tpg::FrameBuffer<Color>::FrameBuffer(size_t width, size_t height) {

}

#endif