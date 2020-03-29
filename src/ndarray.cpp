#include <numcpp/ndarray.h>
#include <numcpp/shape.h>

#include <cstring>
#include <stdexcept>

namespace numcpp {
    template<class T>
    ndarray<T>::ndarray(T * const v, const shape &s, bool delete_on_destruct) :
        m_data{ v },
        m_shape{ s },
        m_delete_on_destruct{ delete_on_destruct }
    { }

    template<class T>
    ndarray<T>::~ndarray() {
        if (m_delete_on_destruct) {
            delete m_data;
        }
    }

    template<class T>
    ndarray<T>::operator T() const {
        if (!m_shape.isScalar()) {
            throw std::logic_error("Implicit casting is invalid on non-scalar type");
        }

        return m_data[0];
    }

    template<class T>
    ndarray<T>& ndarray<T>::operator= (T v) {
        if (!m_shape.isScalar()) {
            throw std::logic_error("Implicit assignment is invalid on non-scaler type");
        }

        m_data[0] = v;

        return *this;
    }

    template<class T>
    ndarray<T>& ndarray<T>::operator= (ndarray<T> v) {
        if (m_shape != v.m_shape) {
            throw std::logic_error("Assignment is invalid on array of different shape");
        }

        std::memcpy(m_data, v.m_data, m_shape.size() * sizeof(T));

        return *this;
    }

    template<class T>
    ndarray<T> ndarray<T>::operator[] (int index) {
        if (m_shape.isScalar()) {
            throw std::logic_error("Array operators are invalid on scalar type");
        }

        auto sub_shape = m_shape.sub();
        T * const v = m_data + (sub_shape.size() * index);

        return ndarray<T>(v, sub_shape);
    }

    template<class T>
    ndarray<T> ndarray<T>::zeros(int n) {
        return ndarray<T>{ new T[n] {}, shape{ n }, true };
    }

    template<class T>
    ndarray<T> ndarray<T>::zeros(const shape &s) {
        return ndarray<T>{ new T[s.size()] {}, s, true };
    }

    // Explicit instantiations
    template class ndarray<char>;
    template class ndarray<unsigned char>;
    template class ndarray<short>;
    template class ndarray<unsigned short>;
    template class ndarray<int>;
    template class ndarray<unsigned int>;
    template class ndarray<long>;
    template class ndarray<unsigned long>;
    template class ndarray<long long>;
    template class ndarray<unsigned long long>;
    template class ndarray<float>;
    template class ndarray<double>;
    template class ndarray<long double>;
}
