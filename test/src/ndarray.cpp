#include <catch2/catch.hpp>

#include <numcpp/ndarray.h>
#include <numcpp/shape.h>

#include <stdexcept>
#include <string>

TEST_CASE( "numcpp::ndarray::operator T()", "numcpp::ndarray" ) {
    double data[] = { 1.1, 2.2, 3.3, 4.4 };
    numcpp::ndarray a{ data, numcpp::shape{ 2, 2 }};

    REQUIRE( a[0][0] == Approx(1.1) );
    REQUIRE( a[0][1] == Approx(2.2) );
    REQUIRE( a[1][0] == Approx(3.3) );
    REQUIRE( a[1][1] == Approx(4.4) );

    REQUIRE( static_cast<double>(a[0][0]) == Approx(1.1) );
    REQUIRE_THROWS_AS( static_cast<double>(a[0]), std::logic_error );
}

TEST_CASE( "numcpp::ndarray::operator=(T)", "numcpp::ndarray" ) {
    double data[] = { 1.1, 2.2, 3.3, 4.4 };
    numcpp::ndarray a{ data, numcpp::shape{ 2, 2 }};

    a[1][0] = 6.6;

    REQUIRE( a[0][0] == Approx(1.1) );
    REQUIRE( a[0][1] == Approx(2.2) );
    REQUIRE( a[1][0] == Approx(6.6) );
    REQUIRE( a[1][1] == Approx(4.4) );

    REQUIRE_THROWS_AS( a[1] = 2.2, std::logic_error );
}

TEST_CASE( "numcpp::ndarray::operator=(ndarray)", "numcpp::ndarray" ) {
    double data1[] = { 1.1, 2.2, 3.3, 4.4 };
    numcpp::ndarray a1{ data1, numcpp::shape{ 2, 2 }};

    double data2[] = { 5.5, 6.6 };
    numcpp::ndarray a2{ data2, numcpp::shape{ 2 }};

    a1[1] = a2;

    REQUIRE( a1[0][0] == Approx(1.1) );
    REQUIRE( a1[0][1] == Approx(2.2) );
    REQUIRE( a1[1][0] == Approx(5.5) );
    REQUIRE( a1[1][1] == Approx(6.6) );

    REQUIRE_THROWS_AS( a1 = a2, std::logic_error );
}

TEST_CASE( "numcpp::ndarray::operator[]", "numcpp::ndarray" ) {
    double data[] = { 1.1, 2.2, 3.3, 4.4 };
    numcpp::ndarray a{ data, numcpp::shape{ 2, 2 }};

    REQUIRE( a[0][0] == Approx(1.1) );
    REQUIRE( a[0][1] == Approx(2.2) );
    REQUIRE( a[1][0] == Approx(3.3) );
    REQUIRE( a[1][1] == Approx(4.4) );

    REQUIRE_THROWS_AS( a[0][0][0], std::logic_error );

    REQUIRE_THROWS_AS( a[-1][0], std::out_of_range );
    REQUIRE_THROWS_AS( a[0][-1], std::out_of_range );
    REQUIRE_THROWS_AS( a[2][-1], std::out_of_range );
    REQUIRE_THROWS_AS( a[0][2], std::out_of_range );
    REQUIRE_THROWS_AS( a[2][0], std::out_of_range );
}

TEST_CASE( "numcpp::ndarray::as_string() scalar", "numcpp::ndarray" ) {
    double data[] = { 1.1 };
    numcpp::ndarray a{ data, numcpp::shape{ }};

    REQUIRE( a.as_string() == std::to_string(1.1) );
}
