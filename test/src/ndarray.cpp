#include <catch2/catch.hpp>

#include <numcpp/ndarray.h>
#include <numcpp/shape.h>

#include <stdexcept>

TEST_CASE( "numcpp::ndarray::operator T()", "numcpp::ndarray" ) {
    double data[] = { 1.1, 2.2, 3.3, 4.4 };
    numcpp::ndarray a{ data, numcpp::shape{ 2, 2 }};

    REQUIRE( a[0][0] == 1.1 );
    REQUIRE( a[0][1] == 2.2 );
    REQUIRE( a[1][0] == 3.3 );
    REQUIRE( a[1][1] == 4.4 );

    REQUIRE( static_cast<double>(a[0][0]) == 1.1 );
    REQUIRE_THROWS_AS( static_cast<double>(a[0]), std::logic_error );
}

TEST_CASE( "numcpp::ndarray::operator=(T)", "numcpp::ndarray" ) {
    double data[] = { 1.1, 2.2, 3.3, 4.4 };
    numcpp::ndarray a{ data, numcpp::shape{ 2, 2 }};

    a[1][0] = 6.6;

    REQUIRE( a[0][0] == 1.1 );
    REQUIRE( a[0][1] == 2.2 );
    REQUIRE( a[1][0] == 6.6 );
    REQUIRE( a[1][1] == 4.4 );

    REQUIRE_THROWS_AS( a[1] = 2.2, std::logic_error );
}

TEST_CASE( "numcpp::ndarray::operator=(ndarray)", "numcpp::ndarray" ) {
    double data1[] = { 1.1, 2.2, 3.3, 4.4 };
    numcpp::ndarray a1{ data1, numcpp::shape{ 2, 2 }};

    double data2[] = { 5.5, 6.6 };
    numcpp::ndarray a2{ data2, numcpp::shape{ 2 }};

    a1[1] = a2;

    REQUIRE( a1[0][0] == 1.1 );
    REQUIRE( a1[0][1] == 2.2 );
    REQUIRE( a1[1][0] == 5.5 );
    REQUIRE( a1[1][1] == 6.6 );

    REQUIRE_THROWS_AS( a1 = a2, std::logic_error );
}
