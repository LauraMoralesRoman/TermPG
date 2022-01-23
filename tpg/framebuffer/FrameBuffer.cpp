#include "FrameBuffer.hpp"

#include <stdio.h>
#include <math.h>
// Linux implementation
#ifdef __linux__
    #include <sys/ioctl.h>
    #include <unistd.h>
#endif
// Windows implementation (TODO)
#ifdef _WIN32

#endif

/**
 * Configuration code that runs before main();
 */
size_t tpg::termW, tpg::termH;

char tpg::__impl::start_code() {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    termW = w.ws_col;
    termH = w.ws_row;

    return 0;
};

char start_result = tpg::__impl::start_code();

// Frame Buffer constructors

template<typename Color>
tpg::FrameBuffer<Color>::FrameBuffer()
    : width_(termW), height_(termH * 2) { common_start_code_(); }

template<typename Color>
tpg::FrameBuffer<Color>::FrameBuffer(const size_t width, const size_t height)
    : width_(width), height_(height) { common_start_code_(); }

template<typename Color>
void tpg::FrameBuffer<Color>::common_start_code_() {
    internal_ = new Color[width_ * height_];
    prev_internal_ = new Color[width_ * height_];
}

template<typename Color>
tpg::FrameBuffer<Color>::~FrameBuffer() {
    delete[] internal_;
    delete[] prev_internal_;
}

// ######################################
// Rendering
// ######################################

char change_position[] = "\033[000;000H";

/*
Es posible que de problemas cambindo la posición cuando el tamaño de las 
coordenadas sea mayor a 999 en cualquiera de los ejes
TODO: arreglar esto
*/
void insert_uint8_t(char*, uint8_t);

template<typename Color>
void tpg::FrameBuffer<Color>::render() {
    // Black color for bottom
    Color black;
    int last_changed_y, last_changed_x;
    bool changed = true;

    // Reset cursor position
    fputs("\033[0;0H", stdout);
    // ---------------------
    for (int y = 0; y < height_; y += 2) {
        for (int x = 0; x < width_; x++) {
            Color* top = internal_ + (y * width_ + x);
            Color* bottom = (y == height_) ? &black:(internal_ + ((y + 1) * width_ + x)); 

            // Force render
            if (force_full_render_) {
                render_pixels_(top, bottom);
                prev_internal_[x + y * width_] = *top;
                prev_internal_[x + (y + 1) * width_] = *bottom;
                continue;
            }

            Color prev_top = prev_internal_[y * width_ + x];
            Color prev_bottom = (y == height_) ? black:(prev_internal_[(y + 1) * width_ + x]); 

            if ((Color::diff(*top, prev_top) >= minimum_change_) || (Color::diff(*bottom, prev_bottom) >= minimum_change_)) {
                if (changed) {
                    insert_uint8_t(change_position + 2, y);
                    insert_uint8_t(change_position + 6, x);
                    fputs(change_position, stdout);
                }
                changed = false;
                render_pixels_(top, bottom);
                prev_internal_[x + y * width_] = *top;
                prev_internal_[x + (y + 1) * width_] = *bottom;
            } else {
                last_changed_x = x;
                last_changed_y = y;
                changed = true;
            }
        }
        if ((y < height_ - 2) && !changed)
            fputs("\033[0m\n", stdout);
    }
    fflush(stdout);
    force_full_render_ = false;
}


char Color_ansi[] = "\033[38;2;000;000;000m\033[48;2;000;000;000m▄";
//                              ^   ^  ^    ^     ^   ^   ^  
//                       lower  r   g  b    upper r   g   b 
// index   :                    7   11 15         26  30  34
//                                       
template<>
void tpg::FrameBuffer<tpg::Color>::render_pixels_(const Color* top_color, const Color* bottom_color) {
    insert_uint8_t(Color_ansi + 7, bottom_color->r);
    insert_uint8_t(Color_ansi + 11, bottom_color->g);
    insert_uint8_t(Color_ansi + 15, bottom_color->b);

    insert_uint8_t(Color_ansi + 26, top_color->r);
    insert_uint8_t(Color_ansi + 30, top_color->g);
    insert_uint8_t(Color_ansi + 34, top_color->b);

    fputs(Color_ansi, stdout);
}

template<>
void tpg::FrameBuffer<tpg::ColorBW>::render_pixels_(const ColorBW* top_color, const ColorBW* bottom_color) {
    printf("Hola desde el color BW");
}

void insert_uint8_t(char* text, uint8_t n) {
    text[2] = (n % 10) + '0';
    n /= 10;
    text[1] = (n % 10) + '0';
    n /= 10;
    text[0] = n + '0';
}

// Color setting 
template<typename Color>
void tpg::FrameBuffer<Color>::set_pixel(const size_t x, const size_t y, const Color& color) {
    if (x >= width_ || y >= height_)
        return;

    internal_[x + y * width_].apply(color);
}

// Utility methods

// Color implementation
tpg::Color::Color()
    : r(0), g(0), b(0), a(255) {}

tpg::Color::Color(const uint8_t r, const uint8_t g, const uint8_t b, const uint8_t a)
    : r(r), g(g), b(b), a(a) {}

tpg::Color::Color(const uint8_t bw, const uint8_t alpha)
    : r(bw), g(bw), b(bw), a(alpha) {}

// Operators
bool tpg::Color::operator==(const Color& other) {
    return (r == other.r) && (g == other.g) && (b == other.b);
}

bool tpg::Color::operator!=(const Color& other) {
    return (r != other.r) && (g != other.g) && (b == other.b);
}

float tpg::Color::diff(const Color& a, const Color& b) {
    float vr = a.r - b.r, vg = a.g - b.g , vb = a.b - b.b;
    return sqrt(vr * vr + vg * vg + vb * vb) / 441.67f;
}

float tpg::ColorBW::diff(const ColorBW& a, const ColorBW& b) {
    return abs(a.value - b.value) / 255.0f;
}

tpg::ColorBW::ColorBW(const int value)
    : value(value) {}

// Alpha blending implementation for colors
// RGBA Color
void tpg::Color::apply(const Color& other) {
    float source = (float)other.a / 255.0f;
    float destination = 1.0f - source;
    
    a = other.a + a * (255 - other.a);

    r = (r * destination + other.r * source);
    g = (g * destination + other.g * source);
    b = (b * destination + other.b * source);

    // Posible implementation
    // r -= (float)other.r * source;
    // g -= (float)other.g * source;
    // b -= (float)other.b * source;

}

// Declare available template types
template class tpg::FrameBuffer<tpg::Color>;
template class tpg::FrameBuffer<tpg::ColorBW>;
