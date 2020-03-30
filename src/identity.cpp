#include <numcpp.h>
#include <numcpp/explicit_instantiate.h>
#include <numcpp/shape.h>

namespace numcpp {
    template<typename T>
    ndarray<T> numcpp<T>::identity(int n) {
        return eye(n);
    }

    NUMCPP_EXPLICIT_INSTANTIATE_CLASS(numcpp);
}
