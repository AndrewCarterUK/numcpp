#include <numcpp/explicit_instantiate.h>
#include <numcpp/numcpp.h>
#include <numcpp/shape.h>

namespace numcpp {
    template<typename T>
    ndarray<T> numcpp<T>::ones(int n) {
        return full(n, 1);
    }

    template<typename T>
    ndarray<T> numcpp<T>::ones(const shape &s) {
        return full(s, 1);
    }

    NUMCPP_EXPLICIT_INSTANTIATE_CLASS(numcpp);
}
