#ifndef CANVAS_HPP
#define CANVAS_HPP

#include "../framebuffer/FrameBuffer.hpp"

#define FPS_MEAN_FACTOR 10

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
        void set_frame_rate(const size_t desired_frame_rate) { frame_rate_ = desired_frame_rate; }

        const float& delta_time = delta_time_;
        const float& frame_rate = calculated_frame_rate_;
        // const int& frame_count = frame_count_;
        private:
        /**
         * Desired frame rate at which the canvas wants to run
         */
        size_t frame_rate_ = 60;
        /**
         * Ammount of frames passed from begin();
         */
        size_t frame_count_ = 0;
        /**
         * If the execution loop is being run
         */
        bool running_ = false;
        /**
         * @brief Ammount of time passed between the last and the current frame
         */
        float delta_time_;
        /**
         * @brief FPS mean
         * @details The ammount of smoothing is determined by FPS_MEAN_FACTOR
         */
        float calculated_frame_rate_;

        public:
        /**
         * @brief Flags for printing debug information
         * @details Bit representation
         * 0 - FPS
         * 1 - Delta Time
         * 2 - Frame count
         */
        uint8_t debug_flags = 0x00;
        enum flags : uint8_t {
            FPS =           0b00000001, // 1
            DELTATIME =     0b00000010, // 1<<1
            FRAMECOUNT =    0b00000100  
        };

        protected:
        /**
         * @brief Function that runs before the user defined loop method
         */
        virtual void pre_loop_() {};
        /**
         * @brief Function that runs after the user defined loop method
         */
        virtual void post_loop_() {};
    };
}

#endif