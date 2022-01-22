#ifndef MATRICES_HPP
#define MATRICES_HPP

#include "../vertex.hpp"

namespace tpg {
    typedef float m_type;
    namespace __impl {
        struct V3 {
            m_type x = 0, y = 0, z = 0;
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

        TMatrix& operator*(const TMatrix& other);
        TMatrix& operator*=(const TMatrix& other);

        m_type* operator[](const size_t index);

        private:
        m_type values[4][4] = { };
    };

    /**
      * @brief Transformation values, used to transform vertices with a transformation matrix
      */
    class Transform {
        public:
            TMatrix get_matrix();
        private:
        __impl::V3 euclidean_rotation;
        __impl::V3 position;
        __impl::V3 scale;
    };
}

#endif
