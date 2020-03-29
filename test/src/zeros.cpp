#include <catch2/catch.hpp>

#include <numcpp/shape.h>
#include <numcpp/numcpp.h>
#include <vector>

using nc = numcpp::numcpp<>;

TEST_CASE( "numcpp::zeros() for one dimensional array", "numcpp::zeros" ) {
    auto a{ nc::zeros(3) };

    REQUIRE( a[0] == 0 );
    REQUIRE( a[1] == 0 );
    REQUIRE( a[2] == 0 );

    REQUIRE( a.m_shape.size() == 3 );
    REQUIRE( a.m_shape.dimensions() == std::vector<int>{ 3 } );
}

TEST_CASE( "numcpp::zeros() for multi dimensional array", "numcpp::zeros" ) {
    auto a{ nc::zeros({ 3, 3, 3 }) };

    REQUIRE( a[0][0][0] == 0 );
    REQUIRE( a[2][2][2] == 0 );

    REQUIRE( a.m_shape.size() == 27 );
}
