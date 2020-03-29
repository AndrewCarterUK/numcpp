#include <numcpp/explicit_instantiate.h>
#include <numcpp/ndarray.h>
#include <numcpp/shape.h>

#include <cstring>
#include <stdexcept>

namespace numcpp {
    template<typename T>
    ndarray<T>::ndarray(T * const data, const shape &s, bool delete_on_destruct) :
        m_data{ data },
        m_shape{ s },
        m_delete_on_destruct{ delete_on_destruct }
    { }

    template<typename T>
    ndarray<T>::~ndarray() {
        if (m_delete_on_destruct) {
            delete m_data;
        }
    }

    template<typename T>
    ndarray<T>::operator T() const {
        if (!m_shape.isScalar()) {
            throw std::logic_error("Implicit casting is invalid on non-scalar type");
        }

        return m_data[0];
    }

    template<typename T>
    ndarray<T>& ndarray<T>::operator= (T v) {
        if (!m_shape.isScalar()) {
            throw std::logic_error("Implicit assignment is invalid on non-scaler type");
        }

        m_data[0] = v;

        return *this;
    }

    template<typename T>
    ndarray<T>& ndarray<T>::operator= (ndarray<T> v) {
        if (m_shape != v.m_shape) {
            throw std::logic_error("Assignment is invalid on array of different shape");
        }

        std::memmove(m_data, v.m_data, m_shape.size() * sizeof(T));

        return *this;
    }

    template<typename T>
    ndarray<T> ndarray<T>::operator[] (int index) {
        if (m_shape.isScalar()) {
            throw std::logic_error("Array operators are invalid on scalar type");
        }

        auto sub_shape = m_shape.sub();
        T * const v = m_data + (sub_shape.size() * index);

        return ndarray<T>(v, sub_shape);
    }

    NUMCPP_EXPLICIT_INSTANTIATE_CLASS(ndarray);
}
