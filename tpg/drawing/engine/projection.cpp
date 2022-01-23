#include "projection.hpp"

#include <math.h>

tpg::__impl::V3& tpg::__impl::V3::operator+=(const V3 &other) {
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

tpg::__impl::V3& tpg::__impl::V3::operator*=(const V3 &other) {
    x *= other.x;
    y *= other.y;
    z *= other.z;
    return *this;
}

tpg::TMatrix::TMatrix(const m_type aa, const m_type ab, const m_type ac, const m_type ad,
                      const m_type ba, const m_type bb, const m_type bc, const m_type bd,
                      const m_type ca, const m_type cb, const m_type cc, const m_type cd,
                      const m_type da, const m_type db, const m_type dc, const m_type dd)
    : values{aa, ab, ac, ad, ba, bb, bc, bd, ca, cb, cc, cd, da, db, dc, dd}{
}

tpg::m_type* tpg::TMatrix::operator[](const size_t index) {
    return values[index];
}

tpg::TMatrix tpg::TMatrix::operator*(const TMatrix &other) {
    TMatrix tmp;
    tmp[0][0] = values[0][0] * other.values[0][0] + values[0][1] * other.values[1][0] + values[0][2] * other.values[2][0] + values[0][3] * other.values[3][0];
	tmp[0][1] = values[0][0] * other.values[0][1] + values[0][1] * other.values[1][1] + values[0][2] * other.values[2][1] + values[0][3] * other.values[3][1];
	tmp[0][2] = values[0][0] * other.values[0][2] + values[0][1] * other.values[1][2] + values[0][2] * other.values[2][2] + values[0][3] * other.values[3][2];
	tmp[0][3] = values[0][0] * other.values[0][3] + values[0][1] * other.values[1][3] + values[0][2] * other.values[2][3] + values[0][3] * other.values[3][3];
	tmp[1][0] = values[1][0] * other.values[0][0] + values[1][1] * other.values[1][0] + values[1][2] * other.values[2][0] + values[1][3] * other.values[3][0];
	tmp[1][1] = values[1][0] * other.values[0][1] + values[1][1] * other.values[1][1] + values[1][2] * other.values[2][1] + values[1][3] * other.values[3][1];
	tmp[1][2] = values[1][0] * other.values[0][2] + values[1][1] * other.values[1][2] + values[1][2] * other.values[2][2] + values[1][3] * other.values[3][2];
	tmp[1][3] = values[1][0] * other.values[0][3] + values[1][1] * other.values[1][3] + values[1][2] * other.values[2][3] + values[1][3] * other.values[3][3];
	tmp[2][0] = values[2][0] * other.values[0][0] + values[2][1] * other.values[1][0] + values[2][2] * other.values[2][0] + values[2][3] * other.values[3][0];
	tmp[2][1] = values[2][0] * other.values[0][1] + values[2][1] * other.values[1][1] + values[2][2] * other.values[2][1] + values[2][3] * other.values[3][1];
	tmp[2][2] = values[2][0] * other.values[0][2] + values[2][1] * other.values[1][2] + values[2][2] * other.values[2][2] + values[2][3] * other.values[3][2];
	tmp[2][3] = values[2][0] * other.values[0][3] + values[2][1] * other.values[1][3] + values[2][2] * other.values[2][3] + values[2][3] * other.values[3][3];
	tmp[3][0] = values[3][0] * other.values[0][0] + values[3][1] * other.values[1][0] + values[3][2] * other.values[2][0] + values[3][3] * other.values[3][0];
	tmp[3][1] = values[3][0] * other.values[0][1] + values[3][1] * other.values[1][1] + values[3][2] * other.values[2][1] + values[3][3] * other.values[3][1];
	tmp[3][2] = values[3][0] * other.values[0][2] + values[3][1] * other.values[1][2] + values[3][2] * other.values[2][2] + values[3][3] * other.values[3][2];
	tmp[3][3] = values[3][0] * other.values[0][3] + values[3][1] * other.values[1][3] + values[3][2] * other.values[2][3] + values[3][3] * other.values[3][3];
    return tmp;
}

tpg::TMatrix& tpg::TMatrix::operator*=(const TMatrix &other) {
    TMatrix tmp;
    tmp[0][0] = values[0][0] * other.values[0][0] + values[0][1] * other.values[1][0] + values[0][2] * other.values[2][0] + values[0][3] * other.values[3][0];
	tmp[0][1] = values[0][0] * other.values[0][1] + values[0][1] * other.values[1][1] + values[0][2] * other.values[2][1] + values[0][3] * other.values[3][1];
	tmp[0][2] = values[0][0] * other.values[0][2] + values[0][1] * other.values[1][2] + values[0][2] * other.values[2][2] + values[0][3] * other.values[3][2];
	tmp[0][3] = values[0][0] * other.values[0][3] + values[0][1] * other.values[1][3] + values[0][2] * other.values[2][3] + values[0][3] * other.values[3][3];
	tmp[1][0] = values[1][0] * other.values[0][0] + values[1][1] * other.values[1][0] + values[1][2] * other.values[2][0] + values[1][3] * other.values[3][0];
	tmp[1][1] = values[1][0] * other.values[0][1] + values[1][1] * other.values[1][1] + values[1][2] * other.values[2][1] + values[1][3] * other.values[3][1];
	tmp[1][2] = values[1][0] * other.values[0][2] + values[1][1] * other.values[1][2] + values[1][2] * other.values[2][2] + values[1][3] * other.values[3][2];
	tmp[1][3] = values[1][0] * other.values[0][3] + values[1][1] * other.values[1][3] + values[1][2] * other.values[2][3] + values[1][3] * other.values[3][3];
	tmp[2][0] = values[2][0] * other.values[0][0] + values[2][1] * other.values[1][0] + values[2][2] * other.values[2][0] + values[2][3] * other.values[3][0];
	tmp[2][1] = values[2][0] * other.values[0][1] + values[2][1] * other.values[1][1] + values[2][2] * other.values[2][1] + values[2][3] * other.values[3][1];
	tmp[2][2] = values[2][0] * other.values[0][2] + values[2][1] * other.values[1][2] + values[2][2] * other.values[2][2] + values[2][3] * other.values[3][2];
	tmp[2][3] = values[2][0] * other.values[0][3] + values[2][1] * other.values[1][3] + values[2][2] * other.values[2][3] + values[2][3] * other.values[3][3];
	tmp[3][0] = values[3][0] * other.values[0][0] + values[3][1] * other.values[1][0] + values[3][2] * other.values[2][0] + values[3][3] * other.values[3][0];
	tmp[3][1] = values[3][0] * other.values[0][1] + values[3][1] * other.values[1][1] + values[3][2] * other.values[2][1] + values[3][3] * other.values[3][1];
	tmp[3][2] = values[3][0] * other.values[0][2] + values[3][1] * other.values[1][2] + values[3][2] * other.values[2][2] + values[3][3] * other.values[3][2];
	tmp[3][3] = values[3][0] * other.values[0][3] + values[3][1] * other.values[1][3] + values[3][2] * other.values[2][3] + values[3][3] * other.values[3][3];
    *this = tmp;
    return *this;
}

void tpg::TMatrix::transform(Vertex &v) {
    Vertex tmp;
    tmp.x = values[0][0] * v.x + values[0][1] * v.y + values[0][2] * v.z + values[0][3];
    tmp.y = values[1][0] * v.x + values[1][1] * v.y + values[1][2] * v.z + values[1][3];
    tmp.z = values[2][0] * v.x + values[2][1] * v.y + values[2][2] * v.z + values[2][3];

    v = tmp;
}

// Transforms
void tpg::Transform::translate(const m_type x, const m_type y, const m_type z) {
    translate_ += {x, y, z};
    calculated_ = false;
}

void tpg::Transform::rotate(const m_type x, const m_type y, const m_type z) {
    rotate_ += {x, y, z};
    calculated_ = false;
}

void tpg::Transform::scale(const m_type x, const m_type y, const m_type z) {
    scale_ *= {x, y, z};
    calculated_ = false;
}

tpg::TMatrix tpg::Transform::get_matrix() {
    // Translate matrix
    if (!calculated_) {
        calculated_ = true;
        calculated_matrix_ = {
            1, 0, 0, translate_.x,
            0, 1, 0, translate_.y,
            0, 0, 1, translate_.z,
            0, 0, 0, 1
        };
        // Rotation matrix
        calculated_matrix_ *= { // X axis
            1, 0, 0, 0,
            0, std::cos(rotate_.x), -std::sin(rotate_.x), 0,
            0, std::sin(rotate_.x), std::cos(rotate_.x), 0,
            0, 0, 0, 1
        };
        calculated_matrix_ *= { // Y axis
            std::cos(rotate_.y), 0, std::sin(rotate_.y), 0,
            0, 1, 0, 0,
            -std::sin(rotate_.y), 0, std::cos(rotate_.y), 0,
            0, 0, 0, 1
        };
        calculated_matrix_ *= { // Z axis
            std::cos(rotate_.z), -std::sin(rotate_.z), 0, 0,
            std::sin(rotate_.z), std::cos(rotate_.z), 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
        };
        // Scale matrix
        calculated_matrix_ *= {
            scale_.x, 0, 0, 0,
            0, scale_.y, 0, 0,
            0, 0, scale_.x, 0,
            0, 0, 0, 1
        };
    }

    return calculated_matrix_;
}

