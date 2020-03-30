#include <iostream>
#include <numcpp.h>

using nc = numcpp::numcpp<double>;

int main()
{
    auto m{ nc::eye(5, 8, -2) };
    auto m_t{ m.transpose() };

    std::cout << "Original:\n" << m.as_string() << '\n';
    std::cout << "Transpose:\n" << m_t.as_string() << '\n';

    return 0;
}
