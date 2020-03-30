#include <numcpp.h>
#include <numcpp/explicit_instantiate.h>
#include <numcpp/shape.h>

namespace numcpp {
    template<typename T>
    ndarray<T> numcpp<T>::eye(int N, int M, int k) {
        if (M == 0) {
            M = N;
        }

        auto result{ zeros(shape{ N, M }) };

        for (int i = 0; i < N; i++) {
            if (i + k >= M) {
                break;
            } else if (i + k < 0) {
                continue;
            }

            result[i][i + k] = 1;
        }

        return result;
    }

    NUMCPP_EXPLICIT_INSTANTIATE_CLASS(numcpp);
}
