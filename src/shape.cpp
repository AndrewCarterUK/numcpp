#include <numcpp/shape.h>

#include <algorithm>
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

    shape shape::transpose() const {
        std::vector<int> t{ m_dimensions };
        std::reverse(t.begin(), t.end());
        return shape{ t };
    }

    int shape::size() const {
        return m_size;
    }

    const std::vector<int> shape::dimensions() const {
        return m_dimensions;
    }

    int shape::offset(const std::vector<int> indicies) const {
        if (indicies.size() != m_dimensions.size()) {
            throw std::logic_error("Cannot calculate index from incompatible shape");
        }

        int offset = 0;

        for (std::size_t i = 0; i < indicies.size(); i++) {
            if (i == indicies.size() - 1) {
                offset += indicies[i];
            } else {
                offset += indicies[i] * std::accumulate(m_dimensions.begin() + i + 1, m_dimensions.end(), 1, std::multiplies<int>());
            }
        }

        return offset;
    }

    void shape::advance(std::vector<int> &indicies) const {
        if (indicies.size() != m_dimensions.size()) {
            throw std::logic_error("Cannot calculate index from incompatible shape");
        }

        for (int i = static_cast<int>(indicies.size()) - 1; i >= 0; i--) {
            if (indicies[i] < m_dimensions[i] - 1) {
                indicies[i]++;
                return;
            } else {
                for (std::size_t j = i; j < indicies.size(); j++) {
                    indicies[j] = 0;
                }
            }
        }
    }
}
