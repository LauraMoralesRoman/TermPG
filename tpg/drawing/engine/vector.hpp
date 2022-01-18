#ifndef VECTOR_HPP
#define VECTOR_HPP

namespace tpg {
    typedef double v_type;
    class Vector3 {
        private:
          struct V3 {
            v_type x, y, z;
          };
        public:
        Vector3() = default;
        Vector3(const v_type x, const v_type y, const v_type z);
        Vector3(const v_type val);

        // Fast set operators
      
        // Math operations
        Vector3 operator+(const Vector3& other);
        Vector3 operator-(const Vector3& other);
        Vector3& operator+=(const Vector3& other);
        Vector3& operator-=(const Vector3& other);
        Vector3 operator*(const v_type scalar);
        Vector3& operator*=(const v_type scalar);

        const v_type& x = x_;
        const v_type& y = y_;
        const v_type& z = z_;
        
        const V3& norm = norm_;
        private:
        v_type x_ = 0, y_ = 0, z_ = 0;
        v_type mag_ = 0;
        V3 norm_;

        void update_();
    };
}

#endif
