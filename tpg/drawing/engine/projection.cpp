#include "projection.hpp"

tpg::TMatrix& tpg::TMatrix::operator*(const TMatrix &other) {
    // TODO: implementation
    return *this;
}

tpg::TMatrix& tpg::TMatrix::operator*=(const TMatrix &other) {
	values[0][0] = values[0][0] * other.values[0][0] + values[0][1] * other.values[1][0] + values[0][2] * other.values[2][0] + values[0][3] * other.values[3][0];
	values[0][1] = values[0][0] * other.values[0][1] + values[0][1] * other.values[1][1] + values[0][2] * other.values[2][1] + values[0][3] * other.values[3][1];
	values[0][2] = values[0][0] * other.values[0][2] + values[0][1] * other.values[1][2] + values[0][2] * other.values[2][2] + values[0][3] * other.values[3][2];
	values[0][3] = values[0][0] * other.values[0][3] + values[0][1] * other.values[1][3] + values[0][2] * other.values[2][3] + values[0][3] * other.values[3][3];
	values[1][0] = values[1][0] * other.values[0][0] + values[1][1] * other.values[1][0] + values[1][2] * other.values[2][0] + values[1][3] * other.values[3][0];
	values[1][1] = values[1][0] * other.values[0][1] + values[1][1] * other.values[1][1] + values[1][2] * other.values[2][1] + values[1][3] * other.values[3][1];
	values[1][2] = values[1][0] * other.values[0][2] + values[1][1] * other.values[1][2] + values[1][2] * other.values[2][2] + values[1][3] * other.values[3][2];
	values[1][3] = values[1][0] * other.values[0][3] + values[1][1] * other.values[1][3] + values[1][2] * other.values[2][3] + values[1][3] * other.values[3][3];
	values[2][0] = values[2][0] * other.values[0][0] + values[2][1] * other.values[1][0] + values[2][2] * other.values[2][0] + values[2][3] * other.values[3][0];
	values[2][1] = values[2][0] * other.values[0][1] + values[2][1] * other.values[1][1] + values[2][2] * other.values[2][1] + values[2][3] * other.values[3][1];
	values[2][2] = values[2][0] * other.values[0][2] + values[2][1] * other.values[1][2] + values[2][2] * other.values[2][2] + values[2][3] * other.values[3][2];
	values[2][3] = values[2][0] * other.values[0][3] + values[2][1] * other.values[1][3] + values[2][2] * other.values[2][3] + values[2][3] * other.values[3][3];
	values[3][0] = values[3][0] * other.values[0][0] + values[3][1] * other.values[1][0] + values[3][2] * other.values[2][0] + values[3][3] * other.values[3][0];
	values[3][1] = values[3][0] * other.values[0][1] + values[3][1] * other.values[1][1] + values[3][2] * other.values[2][1] + values[3][3] * other.values[3][1];
	values[3][2] = values[3][0] * other.values[0][2] + values[3][1] * other.values[1][2] + values[3][2] * other.values[2][2] + values[3][3] * other.values[3][2];
	values[3][3] = values[3][0] * other.values[0][3] + values[3][1] * other.values[1][3] + values[3][2] * other.values[2][3] + values[3][3] * other.values[3][3];
    return *this;
}
