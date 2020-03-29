#include <numcpp/explicit_instantiate.h>
#include <numcpp/numcpp.h>
#include <numcpp/shape.h>

#include <algorithm>
#include <initializer_list>

namespace numcpp {
    template<typename T>
    ndarray<T> numcpp<T>::full(int n, T v) {
        return full(shape{ n }, v);
    }

    template<typename T>
    ndarray<T> numcpp<T>::full(std::initializer_list<int> dimensions, T v) {
        return full(shape{ dimensions }, v);
    }

    template<typename T>
    ndarray<T> numcpp<T>::full(const shape &s, T v) {
        T * const data{ new T[s.size()] };

        std::fill(data, data + s.size(), v);

        return ndarray<T>{ data, s, true };
    }

    NUMCPP_EXPLICIT_INSTANTIATE_CLASS(numcpp);
}
