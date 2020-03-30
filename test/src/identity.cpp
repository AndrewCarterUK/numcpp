#include <catch2/catch.hpp>

#include <numcpp.h>
#include <vector>

using nc = numcpp::numcpp<>;

TEST_CASE( "numcpp::identity()", "numcpp::identity" ) {
    auto a{ nc::identity(3) };

    REQUIRE( a[0][0] == 1 );
    REQUIRE( a[0][1] == 0 );
    REQUIRE( a[0][2] == 0 );

    REQUIRE( a[1][0] == 0 );
    REQUIRE( a[1][1] == 1 );
    REQUIRE( a[1][2] == 0 );

    REQUIRE( a[2][0] == 0 );
    REQUIRE( a[2][1] == 0 );
    REQUIRE( a[2][2] == 1 );

    REQUIRE( a.m_shape.size() == 9 );
    REQUIRE( a.m_shape.dimensions() == std::vector<int>{ 3, 3 } );
}
