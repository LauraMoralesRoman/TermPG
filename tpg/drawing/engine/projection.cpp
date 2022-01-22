#include "projection.hpp"

tpg::TMatrix::TMatrix(const m_type aa, const m_type ab, const m_type ac, const m_type ad,
                      const m_type ba, const m_type bb, const m_type bc, const m_type bd,
                      const m_type ca, const m_type cb, const m_type cc, const m_type cd,
                      const m_type da, const m_type db, const m_type dc, const m_type dd)
    : values{aa, ab, ac, ad, ba, bb, bc, bd, ca, cb, cc, cd, da, db, dc, dd}{
}

tpg::m_type* tpg::TMatrix::operator[](const size_t index) {
    return values[index];
}

tpg::TMatrix& tpg::TMatrix::operator*(const TMatrix &other) {
    // TODO: implementation
    return *this;
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


