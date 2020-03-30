#include <numcpp.h>
#include <numcpp/explicit_instantiate.h>
#include <numcpp/ndarray.h>
#include <numcpp/shape.h>

#include <algorithm>
#include <functional>
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

        if (index < 0) {
            throw std::out_of_range("Negative indicies are out of bounds");
        } else if (index >= m_shape.dimensions()[0]) {
            throw std::out_of_range("Index is out of bounds");
        }

        auto sub_shape = m_shape.sub();
        T * const v = m_data + (sub_shape.size() * index);

        return ndarray<T>(v, sub_shape);
    }

    template<typename T>
    std::string ndarray<T>::as_string(int line_offset) {
        auto line_padding{ std::string(line_offset, ' ') };

        auto dimensions{ m_shape.dimensions() };

        if (dimensions.size() == 0) {
            return line_padding + std::to_string(m_data[0]);
        }

        int root_length = dimensions[0];

        if (dimensions.size() == 1) {
            std::string result = line_padding + "[";

            for (int i = 0; i < root_length; i++) {
                result += operator[](i).as_string();

                if (i != root_length - 1) {
                    result += ", ";
                }
            }

            return result + "]";
        }

        std::string result = line_padding + "[\n";

        for (int i = 0; i < root_length; i++) {
            result += operator[](i).as_string(line_offset + 2);

            if (i != root_length - 1) {
                result += ",\n";
            } else {
                result += "\n";
            }
        }

        return result + line_padding + "]";
    }

    template<typename T>
    ndarray<T> ndarray<T>::transpose() {
        auto t_shape{ m_shape.transpose() };
        ndarray<T> t = numcpp<T>::empty(t_shape);

        auto indicies{ std::vector<int>(m_shape.dimensions().size(), 0) };

        for (int i = 0; i < m_shape.size(); i++) {
            auto t_indicies{ std::vector<int>{ indicies } };
            std::reverse(t_indicies.begin(), t_indicies.end());

            int offset = t.m_shape.offset(t_indicies);
            t.m_data[offset] = m_data[i];

            m_shape.advance(indicies);
        }

        return t;
    }

    NUMCPP_EXPLICIT_INSTANTIATE_CLASS(ndarray);
}
