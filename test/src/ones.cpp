#include <catch2/catch.hpp>

#include <numcpp/shape.h>
#include <numcpp/numcpp.h>
#include <vector>

using nc = numcpp::numcpp<>;

TEST_CASE( "numcpp::ones() for one dimensional array", "numcpp::ones" ) {
    auto a{ nc::ones(3) };

    REQUIRE( a[0] == 1 );
    REQUIRE( a[1] == 1 );
    REQUIRE( a[2] == 1 );

    REQUIRE( a.m_shape.size() == 3 );
    REQUIRE( a.m_shape.dimensions() == std::vector<int>{ 3 } );
}

TEST_CASE( "numcpp::ones() for multi dimensional array", "numcpp::ones" ) {
    auto a{ nc::ones({ 3, 3, 3 }) };

    REQUIRE( a[0][0][0] == 1 );
    REQUIRE( a[0][0][1] == 1 );
    REQUIRE( a[2][2][2] == 1 );

    REQUIRE( a.m_shape.size() == 27 );
}
