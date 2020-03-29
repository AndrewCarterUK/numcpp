#include <ndarray.h>
#include <shape.h>

#include <iostream>
#include <vector>

int main()
{
    double v[6] = {1.65, 2, 3, 4, 5, 6.2};

    numcpp::ndarray array{v, numcpp::shape{3, 2}};

    auto z{ numcpp::ndarray<double>::zeros(2) };

    array[2] = z;

    std::cout << array[0][0] << '\n';
    std::cout << array[0][1] << '\n';
    std::cout << array[1][0] << '\n';
    std::cout << array[1][1] << '\n';
    std::cout << array[2][0] << '\n';
    std::cout << array[2][1] << '\n';

    return 0;
}
