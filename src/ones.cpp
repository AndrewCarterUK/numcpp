#include <numcpp/explicit_instantiate.h>
#include <numcpp/numcpp.h>
#include <numcpp/shape.h>

#include <initializer_list>

namespace numcpp {
    template<typename T>
    ndarray<T> numcpp<T>::ones(int n) {
        return full(n, 1);
    }

    template<typename T>
    ndarray<T> numcpp<T>::ones(std::initializer_list<int> dimensions) {
        return full(shape{ dimensions }, 1);
    }

    template<typename T>
    ndarray<T> numcpp<T>::ones(const shape &s) {
        return full(s, 1);
    }

    NUMCPP_EXPLICIT_INSTANTIATE_CLASS(numcpp);
}
