#ifndef MATRICES_HPP
#define MATRICES_HPP

#include "../vertex.hpp"

namespace tpg {
    typedef float m_type;
    /**
     * @brief Simple transformation matrix used for calculations
     */
    class TMatrix {
        public:
        m_type values[4][4] = { };

        TMatrix& operator*(const TMatrix& other);
        TMatrix& operator*=(const TMatrix& other);

        private:
    };

    /**
      * @brief Transformation values, used to transform vertices with a transformation matrix
      */
    class Transform {
        
    };
}

#endif
