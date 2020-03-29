#include <catch2/catch.hpp>

#include <numcpp/shape.h>
#include <numcpp/numcpp.h>
#include <vector>

TEST_CASE( "numcpp::full() for one dimensional array", "numcpp::full" ) {
    auto a{ numcpp::numcpp<double>::full(3, 3.14) };

    REQUIRE( a[0] == 3.14 );
    REQUIRE( a[1] == 3.14 );
    REQUIRE( a[2] == 3.14 );

    REQUIRE( a.m_shape.size() == 3 );
    REQUIRE( a.m_shape.dimensions() == std::vector<int>{ 3 } );
}

TEST_CASE( "numcpp::full() for multi dimensional array", "numcpp::full" ) {
    auto s{ numcpp::shape{ 3, 3, 3 } };
    auto a{ numcpp::numcpp<double>::full(s, 3.14) };

    REQUIRE( a[0][0][0] == 3.14 );
    REQUIRE( a[2][2][2] == 3.14 );

    REQUIRE( a.m_shape == s );
}
