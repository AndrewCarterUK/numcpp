#include <iostream>
#include <numcpp.h>

using nc = numcpp::numcpp<double>;

int main()
{
    auto m{ nc::identity(5) };

    std::cout << m.as_string() << '\n';

    return 0;
}
