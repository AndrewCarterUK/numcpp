#ifndef NUMCPP_NDARRAY_H
#define NUMCPP_NDARRAY_H

#include "shape.h"

namespace numcpp {
    template <class T = double> 
    class ndarray
    {
        public:
            T * const m_data;
            const shape m_shape;

            ndarray(T * const v, const shape &s, bool delete_on_destruct = false);
            ~ndarray();

            // Overload implicit cast to scalar
            operator T() const;

            // Overload scalar assignment
            ndarray<T>& operator= (T v);

            // Overload array assignment
            ndarray<T>& operator= (ndarray<T> v);

            // Overload index subscript lookup
            ndarray<T> operator[] (int index);

            // Factory method for array of zeroes
            static ndarray<T> zeros(int n);
            static ndarray<T> zeros(const shape &s);

        private:
            bool m_delete_on_destruct;
    };
}

#endif
