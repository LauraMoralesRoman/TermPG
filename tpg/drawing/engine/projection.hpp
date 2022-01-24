#ifndef MATRICES_HPP
#define MATRICES_HPP

#include "vertex.hpp"

namespace tpg {
    typedef double m_type;
    namespace __impl {
        struct V3 {
            m_type x = 0, y = 0, z = 0;
            V3& operator+=(const V3& other);
            V3& operator*=(const V3& other);
        };
    }
    /**
     * @brief Simple transformation matrix used for calculations
     */
    class TMatrix {
        public:
        TMatrix() = default; 
        TMatrix(const m_type aa, const m_type ab, const m_type ac, const m_type ad,
                const m_type ba, const m_type bb, const m_type bc, const m_type bd,
                const m_type ca, const m_type cb, const m_type cc, const m_type cd,
                const m_type da, const m_type db, const m_type dc, const m_type dd);

        TMatrix operator*(const TMatrix& other);
        TMatrix& operator*=(const TMatrix& other);

        void transform(Vertex& v);

        m_type* operator[](const size_t index);

        private:
        m_type values[4][4] = {
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
        };
    };

    /**
      * @brief Wrapper class for all 3D transformations (scale, rotate, translate) 
      */
    class Transform {
        public:
            /**
              * @brief Gets matrix with all transformations applied to it
              * @return Matrix with all transformations
              */
            TMatrix get_matrix();

            void rotate(const m_type x, const m_type y, const m_type z);
            void translate(const m_type x, const m_type y, const m_type z);
            void scale(const m_type x, const m_type y, const m_type z);
        private:
            __impl::V3 translate_;
            __impl::V3 rotate_;
            __impl::V3 scale_{1, 1, 1};

            bool calculated_ = false;
            TMatrix calculated_matrix_;
    };
}

#endif
