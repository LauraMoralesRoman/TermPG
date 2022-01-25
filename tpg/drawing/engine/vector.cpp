#include "vector.hpp"
#include <math.h>

tpg::Vector3::Vector3(const tpg::Vector3::V3& other)
    : x_(other.x), y_(other.y), z_(other.z) {
        update_();
    }

tpg::Vector3::Vector3(const v_type x, const v_type y, const v_type z) 
    : x_(x), y_(y), z_(z) {
    update_();
}

void tpg::Vector3::update_() {
    mag_ = std::sqrt(x_*x_ + y_*y_ + z_*z_);
    norm_.x = x_ / mag_;
    norm_.y = y_ / mag_;
    norm_.z = z_ / mag_; 
}

// Vector operations
tpg::Vector3 tpg::Vector3::operator+(const Vector3 &other) {
  Vector3 tmp;
  tmp.x_ = x_ + other.x_;
  tmp.y_ = y_ + other.y_;
  tmp.z_ = z_ + other.z_;
  tmp.update_();
  return tmp;
}

tpg::Vector3 tpg::Vector3::operator-(const Vector3 &other) {
  Vector3 tmp;
  tmp.x_ = x_ - other.x_;
  tmp.y_ = y_ - other.y_;
  tmp.z_ = z_ - other.z_;
  tmp.update_();
  return tmp;
}

tpg::Vector3 tpg::Vector3::operator*(const v_type scalar) {
  Vector3 tmp = *this;
  tmp.x_ *= scalar;
  tmp.y_ *= scalar;
  tmp.z_ *= scalar;
  tmp.update_();
  return tmp;
}

// Setting itself
tpg::Vector3& tpg::Vector3::operator+=(const Vector3 &other) {
  x_ += other.x_;
  y_ += other.y_;
  z_ += other.z_;
  return *this;
}

tpg::Vector3& tpg::Vector3::operator-=(const Vector3 &other) {
  x_ -= other.x_;
  y_ -= other.y_;
  z_ -= other.z_;
  return *this;
}

tpg::Vector3& tpg::Vector3::operator*=(const v_type scalar) {
  x_ *= scalar;
  y_ *= scalar;
  z_ *= scalar;
  return *this;
}
