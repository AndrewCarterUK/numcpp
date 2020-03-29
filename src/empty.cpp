#include <numcpp/explicit_instantiate.h>
#include <numcpp/numcpp.h>
#include <numcpp/shape.h>

namespace numcpp {
    template<typename T>
    ndarray<T> numcpp<T>::empty(int n) {
        return empty(shape{ n });
    }

    template<typename T>
    ndarray<T> numcpp<T>::empty(const shape &s) {
        return ndarray<T>{ new T[s.size()], s, true };
    }

    NUMCPP_EXPLICIT_INSTANTIATE_CLASS(numcpp);
}
