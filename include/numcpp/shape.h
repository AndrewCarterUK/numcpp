#ifndef NUMCPP_SHAPE_H_
#define NUMCPP_SHAPE_H_

#include <functional>
#include <initializer_list>
#include <numeric>
#include <stdexcept>
#include <vector>

namespace numcpp {
    class shape
    {
        public:
            shape(std::initializer_list<int> dimensions);
            shape(const std::vector<int> &dimensions);

            bool operator== (const shape &compare) const;

            bool operator!= (const shape &compare) const;

            bool isScalar() const;

            shape sub() const;

            int size() const;

            const std::vector<int> dimensions() const;

        private:
            const std::vector<int> m_dimensions;
            const int m_size;
    };
}

#endif
