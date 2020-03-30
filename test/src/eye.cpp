#include <catch2/catch.hpp>

#include <numcpp.h>
#include <vector>

using nc = numcpp::numcpp<>;

TEST_CASE( "numcpp::eye()", "numcpp::eye" ) {
    auto a{ nc::eye(3, 4, -1) };

    REQUIRE( a[0][0] == 0 );
    REQUIRE( a[0][1] == 0 );
    REQUIRE( a[0][2] == 0 );
    REQUIRE( a[0][3] == 0 );

    REQUIRE( a[1][0] == 1 );
    REQUIRE( a[1][1] == 0 );
    REQUIRE( a[1][2] == 0 );
    REQUIRE( a[1][3] == 0 );

    REQUIRE( a[2][0] == 0 );
    REQUIRE( a[2][1] == 1 );
    REQUIRE( a[2][2] == 0 );
    REQUIRE( a[2][3] == 0 );

    REQUIRE( a.m_shape.size() == 12 );
    REQUIRE( a.m_shape.dimensions() == std::vector<int>{ 3, 4 } );

    auto b{ nc::eye(3, 4, 1) };

    REQUIRE( b[0][0] == 0 );
    REQUIRE( b[0][1] == 1 );
    REQUIRE( b[0][2] == 0 );
    REQUIRE( b[0][3] == 0 );

    REQUIRE( b[1][0] == 0 );
    REQUIRE( b[1][1] == 0 );
    REQUIRE( b[1][2] == 1 );
    REQUIRE( b[1][3] == 0 );

    REQUIRE( b[2][0] == 0 );
    REQUIRE( b[2][1] == 0 );
    REQUIRE( b[2][2] == 0 );
    REQUIRE( b[2][3] == 1 );

    REQUIRE( b.m_shape.size() == 12 );
    REQUIRE( b.m_shape.dimensions() == std::vector<int>{ 3, 4 } );
}
