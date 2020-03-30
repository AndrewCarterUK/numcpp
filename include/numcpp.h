#ifndef NUMCPP_NUMCPP_H
#define NUMCPP_NUMCPP_H

#include <numcpp/ndarray.h>
#include <numcpp/shape.h>

#include <initializer_list>

namespace numcpp {
    template <typename T = double>
    class numcpp
    {
        public:
            static ndarray<T> empty(int n);
            static ndarray<T> empty(std::initializer_list<int> dimensions);
            static ndarray<T> empty(const shape &s);

            static ndarray<T> zeros(int n);
            static ndarray<T> zeros(std::initializer_list<int> dimensions);
            static ndarray<T> zeros(const shape &s);

            static ndarray<T> ones(int n);
            static ndarray<T> ones(std::initializer_list<int> dimensions);
            static ndarray<T> ones(const shape &s);

            static ndarray<T> full(int n, T v);
            static ndarray<T> full(std::initializer_list<int> dimensions, T v);
            static ndarray<T> full(const shape &s, T v);

            static ndarray<T> eye(int N, int M = 0, int k = 0);
            static ndarray<T> identity(int n);
    };
}

#endif
