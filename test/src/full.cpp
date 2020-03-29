#include <catch2/catch.hpp>

#include <numcpp/shape.h>
#include <numcpp/numcpp.h>
#include <vector>

using nc = numcpp::numcpp<>;

TEST_CASE( "numcpp::full() for one dimensional array", "numcpp::full" ) {
    auto a{ nc::full(3, 3.14) };

    REQUIRE( a[0] == Approx(3.14) );
    REQUIRE( a[1] == Approx(3.14) );
    REQUIRE( a[2] == Approx(3.14) );

    REQUIRE( a.m_shape.size() == 3 );
    REQUIRE( a.m_shape.dimensions() == std::vector<int>{ 3 } );
}

TEST_CASE( "numcpp::full() for multi dimensional array", "numcpp::full" ) {
    auto a{ nc::full({ 3, 3, 3 }, 3.14) };

    REQUIRE( a[0][0][0] == Approx(3.14) );
    REQUIRE( a[2][2][2] == Approx(3.14) );

    REQUIRE( a.m_shape.size() == 27 );
}
