#ifndef FRAME_BUFFER
#define FRAME_BUFFER

typedef __SIZE_TYPE__ size_t;
typedef unsigned char uint8_t;

// Frame Buffer
namespace tpg {
    class Color;

    // Width and height of the terminal used for rendering
    extern size_t termW, termH;

    namespace __impl {
        /**
         * @brief Code executed before main (used for dynamic initializations)
         */
        char start_code();
        class Color;
    }

    /**
     * @brief Allow for rendering of a internal frame buffer. This is an array 
     * storing the color of each pixel in each position, which is modifiable.
     */
    template<typename Color = tpg::Color>
    class FrameBuffer {
        public:
        /** @brief Read only the width of the frame buffer */
        const size_t& width = width_;
        /** @brief Read only the height of the frame buffer */
        const size_t& height = height_;

        FrameBuffer(const size_t width, const size_t height);
        FrameBuffer();
        ~FrameBuffer();

        /**
         * @brief Renders the colors stored internally into the terminal one time.
         */
        void render();
        /**
         * @brief Forces the complete update of the next frame buffer (without rendering optimizations)
         */
        void force_next_frame() { force_full_render_ = true; }
        /**
         * @brief Sets the color of the desired pixel
         * @param x x position of the pixel
         * @param y y position of the pixel
         */
        void set_pixel(const size_t x, const size_t y, const Color& color);

        // Utility functions
        /**
         * @brief Sets the entire screen to one color
         * @param color color to fill the screen
         * @details needed to implement here for linking issues
         */
        template<typename ClearColor>
        void clear(const ClearColor& color) {
            for (size_t y = 0; y < height_; y++) {
                for (size_t x = 0; x < width_; x++)
                    internal_[x + y * width_] = color;
            }
        }

        /**
         * @brief Sets the threashold used when comparing previous frames on the color difference optimization.
         * This optimization consists on comparing the color values on each pixel to avoid rendering it if it's only slightly differnet to the previous rendered color.
         * The threashold value is normalized and specifies the difference allowed before rendering the pixel.
         * This optimization is implemented because printing into the terminal is much more expensive than comparing two colors.
         * @param change normalized value (0 to 1) for the color comparison optimization.
         */
        void threshold_change(float change) { minimum_change_ = change; }
        private:
        void common_start_code_();
        /**
         * @brief Internal function defined different for each color and used to render two pixels (one char) into the screen.
         */
        __inline void render_pixels_(const Color* top_color, const Color* bottom_color);

        protected:
        /** @brief width and height of the internal frame buffer */
        size_t width_, height_;
        /** @brief Internal array containing the colors to be rendered */
        Color* internal_;
        /** @brief Internal array containing the colors of the previous rendered frame (used for optimization purposes) */
        Color* prev_internal_;
        private:

        /** @brief Threshold for the color comparison optimization */
        float minimum_change_ = 0.01f;
        /** @brief Forces the next frame to be rendered completly (without rendering optimizations) */
        bool force_full_render_ = true;
    };

}

// Colors TODO: color definition and implementation
namespace tpg {
    namespace __impl {
        /**
         * @brief Interfaced used by all color clases. If creating a new color it must implement this interface.
         * It's used for internal optimizations.
         */
        class Color {
            public:
            /**
             * @brief Returns the difference between two colors (neccessary for some internal optimizations)
             * @return The difference (from 0 to 1) between two colors
             */
            static float diff();
            /**
             * @brief Applies one color to another. Used to allow custom implementation (ex: alpha blending) on another colors.
             * 
             * @param other Color to be applied.
             */
            template<typename Implementation>
            void apply(const Implementation& other) {*this = other;}
        };
    }

    /**
     * Default color containing RGBA components.
     */
    class Color : public virtual __impl::Color {
        public:
        /**
         * Color components
         */
        uint8_t r, g, b, a;

        Color();
        Color(const uint8_t bw, const uint8_t a = 255);
        Color(const uint8_t r, const uint8_t g, const uint8_t b, const uint8_t a = 255);

        bool operator==(const Color& other);
        bool operator!=(const Color& other);

        void apply(const Color& other);

        static float diff(const Color& a, const Color& b);
        private:
        
    };

    /**
     * @brief Black and white. Provides faster rendering than the default color.
     * @todo Implement
     */
    class ColorBW : public __impl::Color {
        public:
        ColorBW(const int value);
        ColorBW() = default;
        /**
         * Gray value of the color (0 to 16)
         */
        uint8_t value;

        static float diff(const ColorBW& a, const ColorBW& b);

        /**
          * @brief Conversion from int
          */
        
    };
}

#endif
