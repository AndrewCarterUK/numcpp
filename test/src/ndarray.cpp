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

    REQUIRE( a.as_string() == "1.100000" );
}

TEST_CASE( "numcpp::ndarray::as_string() 1D", "numcpp::ndarray" ) {
    double data[] = { 1.1, 2.2, 3.3 };
    numcpp::ndarray a{ data, numcpp::shape{ 3 }};

    REQUIRE( a.as_string() == "[1.100000, 2.200000, 3.300000]" );
}

TEST_CASE( "numcpp::ndarray::as_string() 2D", "numcpp::ndarray" ) {
    double data[] = { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 };
    numcpp::ndarray a{ data, numcpp::shape{ 3, 3 }};

    std::string expected{ 
        "[\n"
        "  [1.000000, 0.000000, 0.000000],\n"
        "  [0.000000, 1.000000, 0.000000],\n"
        "  [0.000000, 0.000000, 1.000000]\n"
        "]"
    };

    REQUIRE( a.as_string() == expected );
}

TEST_CASE( "numcpp::ndarray::transpose()", "numcpp::ndarray" ) {
    int data[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    numcpp::ndarray<int> a{ data, numcpp::shape{ 1, 2, 4 }};

    auto b{ a.transpose() };

    REQUIRE( a.m_shape == b.m_shape.transpose() );

    REQUIRE( a[0][0][0] == b[0][0][0] );
    REQUIRE( a[0][0][1] == b[1][0][0] );
    REQUIRE( a[0][0][2] == b[2][0][0] );
    REQUIRE( a[0][0][3] == b[3][0][0] );
    REQUIRE( a[0][1][0] == b[0][1][0] );
    REQUIRE( a[0][1][1] == b[1][1][0] );
    REQUIRE( a[0][1][2] == b[2][1][0] );
    REQUIRE( a[0][1][3] == b[3][1][0] );
}
