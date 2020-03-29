#ifndef NUMCPP_NUMCPP_H
#define NUMCPP_NUMCPP_H

#include <numcpp/ndarray.h>
#include <numcpp/shape.h>

namespace numcpp {
    template <typename T = double>
    class numcpp
    {
        public:
            static ndarray<T> empty(int n);
            static ndarray<T> empty(const shape &s);

            static ndarray<T> zeros(int n);
            static ndarray<T> zeros(const shape &s);

            static ndarray<T> ones(int n);
            static ndarray<T> ones(const shape &s);

            static ndarray<T> full(int n, T v);
            static ndarray<T> full(const shape &s, T v);

            static ndarray<T> eye(int N, int M = 0, int k = 0);
            static ndarray<T> identity(int n);
    };
}

#endif
