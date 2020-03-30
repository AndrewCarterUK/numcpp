#include <numcpp.h>
#include <numcpp/explicit_instantiate.h>
#include <numcpp/shape.h>

#include <initializer_list>

namespace numcpp {
    template<typename T>
    ndarray<T> numcpp<T>::empty(int n) {
        return empty(shape{ n });
    }

    template<typename T>
    ndarray<T> numcpp<T>::empty(std::initializer_list<int> dimensions) {
        return empty(shape{ dimensions });
    }

    template<typename T>
    ndarray<T> numcpp<T>::empty(const shape &s) {
        return ndarray<T>{ new T[s.size()], s, true };
    }

    NUMCPP_EXPLICIT_INSTANTIATE_CLASS(numcpp);
}
