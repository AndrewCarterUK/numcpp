#include <numcpp.h>

#include <numcpp/explicit_instantiate.h>
#include <numcpp/shape.h>

#include <initializer_list>

namespace numcpp {
    template<typename T>
    ndarray<T> numcpp<T>::zeros(int n) {
        return zeros(shape{ n });
    }

    template<typename T>
    ndarray<T> numcpp<T>::zeros(std::initializer_list<int> dimensions) {
        return zeros(shape{ dimensions });
    }

    template<typename T>
    ndarray<T> numcpp<T>::zeros(const shape &s) {
        return ndarray<T>{ new T[s.size()] {}, s, true };
    }

    NUMCPP_EXPLICIT_INSTANTIATE_CLASS(numcpp);
}
