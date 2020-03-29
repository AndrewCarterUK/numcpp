#include <numcpp/zeros.h>

namespace numcpp {
    template<typename T>
    ndarray<T> zeros(int n) {
        return ndarray<T>{ new T[n] {}, shape{ n }, true };
    }

    template ndarray<char> zeros<char>(int n);
    template ndarray<unsigned char> zeros<unsigned char>(int n);
    template ndarray<short> zeros<short>(int n);
    template ndarray<unsigned short> zeros<unsigned short>(int n);
    template ndarray<int> zeros<int>(int n);
    template ndarray<unsigned int> zeros<unsigned int>(int n);
    template ndarray<long> zeros<long>(int n);
    template ndarray<unsigned long> zeros<unsigned long>(int n);
    template ndarray<long long> zeros<long long>(int n);
    template ndarray<unsigned long long> zeros<unsigned long long>(int n);
    template ndarray<float> zeros<float>(int n);
    template ndarray<double> zeros<double>(int n);
    template ndarray<long double> zeros<long double>(int n);

    template<typename T>
    ndarray<T> zeros(const shape &s) {
        return ndarray<T>{ new T[s.size()] {}, s, true };
    }

    template ndarray<char> zeros<char>(const shape &s);
    template ndarray<unsigned char> zeros<unsigned char>(const shape &s);
    template ndarray<short> zeros<short>(const shape &s);
    template ndarray<unsigned short> zeros<unsigned short>(const shape &s);
    template ndarray<int> zeros<int>(const shape &s);
    template ndarray<unsigned int> zeros<unsigned int>(const shape &s);
    template ndarray<long> zeros<long>(const shape &s);
    template ndarray<unsigned long> zeros<unsigned long>(const shape &s);
    template ndarray<long long> zeros<long long>(const shape &s);
    template ndarray<unsigned long long> zeros<unsigned long long>(const shape &s);
    template ndarray<float> zeros<float>(const shape &s);
    template ndarray<double> zeros<double>(const shape &s);
    template ndarray<long double> zeros<long double>(const shape &s);
}
