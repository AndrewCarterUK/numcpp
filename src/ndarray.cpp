#include <ndarray.h>
#include <shape.h>

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
        ndarray<T> result{ new T[n] {}, shape{ n }, true };
        return result;
    }

    template<class T>
    ndarray<T> ndarray<T>::zeros(const shape &s) {
        ndarray<T> result{ new T[s.size()] {}, s, true };
    }
}
