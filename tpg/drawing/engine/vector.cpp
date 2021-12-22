#include "vector.hpp"
#include <math.h>

tpg::Vector3::Vector3(const float x, const float y, const float z) 
    : x_(x), y_(y), z_(z) {
    update_();
}

void tpg::Vector3::update_() {
    mag_ = std::sqrt(x_*x_ + y_*y_ + z_*z_);
    norm_x_ = x_ / mag_;
    norm_y_ = y_ / mag_;
    norm_z_ = z_ / mag_;
}
