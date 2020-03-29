#ifndef NUMCPP_ZEROS_H
#define NUMCPP_ZEROS_H

#include "ndarray.h"
#include "shape.h"

namespace numcpp {
    template <typename T = double>
    ndarray<T> zeros(int n);

    template <typename T = double>
    ndarray<T> zeros(const shape &s);
}

#endif
