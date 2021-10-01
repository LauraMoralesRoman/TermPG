#ifndef CANVAS_HPP
#define CANVAS_HPP

#include "../framebuffer/FrameBuffer.hpp"

namespace tpg {
    template<typename Color>
    class FrameBuffer;

    template<typename Color = tpg::Color>
    class Canvas : public tpg::FrameBuffer<Color> {
        public:
        /**
         * @brief Implement default constructor from base class
         */
        using FrameBuffer<Color>::FrameBuffer;

        /**
         * @brief Renders the internal frame buffer one time
         */
        void render();
        /**
         * @brief Runs the loop fuction and then renders the canvas indefinitively until stopped with Canvas::stop().
         * The rate at which the canvas wants to render, 0 if no limits. 
         */
        void begin(void (*loop)(tpg::Canvas<Color>&));
        /**
         * Stops the execution of the running loop. For it to take effect begin() has to be called before.
         */
        void stop() { running_ = false; }

        // Timing
        const size_t& frame_rate = frame_rate_;
        void set_frame_rate(const size_t desired_frame_rate) { frame_rate_ = desired_frame_rate; }
        private:
        /**
         * Desired frame rate at which the canvas wants to run
         */
        size_t frame_rate_ = 60;
        /**
         * If the execution loop is being run
         */
        bool running_ = false;
    };
}

#endif