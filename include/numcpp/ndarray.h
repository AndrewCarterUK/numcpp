#ifndef NUMCPP_NDARRAY_H
#define NUMCPP_NDARRAY_H

#include "shape.h"

#include <string>

namespace numcpp {
    template <typename T = double> 
    class ndarray
    {
        public:
            T * const m_data;
            const shape m_shape;

            ndarray(T * const data, const shape &s, bool delete_on_destruct = false);
            ~ndarray();

            // Overload implicit cast to scalar
            operator T() const;

            // Overload scalar assignment
            ndarray<T>& operator= (T v);

            // Overload array assignment
            ndarray<T>& operator= (ndarray<T> v);

            // Overload index subscript lookup
            ndarray<T> operator[] (int index);

            // Return a string representation of the array (useful for debugging)
            std::string as_string();
        private:
            bool m_delete_on_destruct;
    };
}

#endif
