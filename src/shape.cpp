#include <numcpp/shape.h>

#include <functional>
#include <initializer_list>
#include <numeric>
#include <stdexcept>
#include <vector>

namespace numcpp {
    shape::shape(std::initializer_list<int> dimensions) :
        shape{ std::vector<int>{ dimensions.begin(), dimensions.end() } }
    { }

    shape::shape(const std::vector<int> &dimensions) :
        m_dimensions{ dimensions },
        m_size{ std::accumulate(dimensions.begin(), dimensions.end(), 1, std::multiplies<int>()) }
    { }


    bool shape::operator== (const shape &compare) const {
        return m_dimensions == compare.m_dimensions;
    }

    bool shape::operator!= (const shape &compare) const {
        return m_dimensions != compare.m_dimensions;
    }

    bool shape::isScalar() const {
        return m_dimensions.size() == 0;
    }

    shape shape::sub() const {
        if (m_dimensions.size() == 0) {
            throw std::logic_error("Cannot extract sub shape from scalar shape");
        }

        return shape{ std::vector<int>{ m_dimensions.begin() + 1, m_dimensions.end() } };
    }

    int shape::size() const {
        return m_size;
    }

    std::vector<int> shape::dimensions() {
        return m_dimensions;
    }
}
