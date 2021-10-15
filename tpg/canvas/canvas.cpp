#include "canvas.hpp"

#include <thread>
#include <chrono>

// template<typename Color>
// tpg::Canvas<Color>::Canvas(){}

// Implementation of render method
template<typename Color>
void tpg::Canvas<Color>::render() {
    FrameBuffer<Color>::render();
}

// Variables for FPS mean implementation
float fps_mean_values[FPS_MEAN_FACTOR] = {0};
size_t start_mean_ring_buffer = 0;

template<typename Color>
void tpg::Canvas<Color>::begin(void (*loop)(tpg::Canvas<Color>&)) {
    running_ = true;
    while (running_) {
        auto start = std::chrono::steady_clock::now();
        std::chrono::system_clock::time_point next_time = std::chrono::system_clock::now();
        if (frame_rate != 0)
            next_time += std::chrono::microseconds((unsigned long)(1000000.0 / (double)frame_rate_));

        loop(*this);
        render();
        // Application of debug flags
        if (debug_flags)
            fputs("\033[0m\033[1;1H", stdout);
        for (uint8_t i = 0; i < 8; i++) {
            bool value = debug_flags & (1 << i);
            if (value) {
                switch (i) {
                    case 0: // FPS
                        if (calculated_frame_rate_ < ((float)frame_rate_ * 0.9))
                            printf("\033[31m");
                        printf("%.1f fps\033[0m", calculated_frame_rate_);
                        break;
                    case 1: // DT
                        if (calculated_frame_rate_ < ((float)frame_rate_ * 0.9))
                            printf("\033[31m");
                        printf("%.2f ms", delta_time_ * 1000.0f);
                        break;
                    case 2: // Frame count
                        printf("%zd", frame_count_);
                        break;
                    default:
                        continue;
                }
                // If it's not a flag don't print the | character
                if (i != 7)
                    fputs(" | ", stdout);
            }
        }

        // Timing calculations

        frame_count_++;

        std::this_thread::sleep_until(next_time);
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - start);
        delta_time_ = duration.count() / 1000000.0f;
        // Calculate FPS (mean) O(1) complexity
        float fps = 1.0f / delta_time_;

        int num_iters = (frame_count_ >= FPS_MEAN_FACTOR) ? (FPS_MEAN_FACTOR):frame_count_;

        calculated_frame_rate_ = (calculated_frame_rate_ * (float)num_iters) - fps_mean_values[(start_mean_ring_buffer + num_iters + 1) % num_iters];
        calculated_frame_rate_ = (calculated_frame_rate_ + fps) / (float)num_iters;

        ++start_mean_ring_buffer %= FPS_MEAN_FACTOR;
        fps_mean_values[start_mean_ring_buffer] = fps;

        if (frame_count_ <= FPS_MEAN_FACTOR) {
            calculated_frame_rate_ = fps;
            if (frame_count_ == FPS_MEAN_FACTOR) { // When all of the ring buffer cells are populated
                calculated_frame_rate_ = 0;
                // When all of the ring buffer cells are populated, calculate the mean with them and restart the calculations for the next frames.
                for (size_t i = 0; i < FPS_MEAN_FACTOR; i++)
                    calculated_frame_rate_ += fps_mean_values[i];
                calculated_frame_rate_ /= (float)FPS_MEAN_FACTOR;
            }
        }
    }
}

// Declaration of all possible types
template class tpg::Canvas<tpg::Color>;
template class tpg::Canvas<tpg::ColorBW>;