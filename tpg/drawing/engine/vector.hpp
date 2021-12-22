#ifndef VECTOR_HPP
#define VECTOR_HPP

namespace tpg {
    class Vector3 {
        public:
        Vector3() = default;
        Vector3(const float x, const float y, const float z);
        Vector3(const float val);

        // Fast set operators

    
        // Math operations
        Vector3& operator+(const Vector3& other);
        Vector3& operator-(const Vector3& other);
        Vector3& operator+=(const Vector3& other);
        Vector3& operator-=(const Vector3& other);
        Vector3& operator*(const float scalar);
        Vector3& operator*=(const float scalar);
        private:
        float x_ = 0, y_ = 0, z_ = 0;
        float mag_ = 0;
        float norm_x_ = 0, norm_y_ = 0, norm_z_ = 0;

        void update_();
    };
}

#endif
