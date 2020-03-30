#include <catch2/catch.hpp>

#include <numcpp.h>
#include <vector>

using nc = numcpp::numcpp<>;

TEST_CASE( "numcpp::empty() for one dimensional array", "numcpp::empty" ) {
    auto a{ nc::empty(3) };

    REQUIRE( a.m_shape.size() == 3 );
    REQUIRE( a.m_shape.dimensions() == std::vector<int>{ 3 } );
}

TEST_CASE( "numcpp::empty() for multi dimensional array", "numcpp::empty" ) {
    auto a{ nc::empty({ 3, 3, 3 }) };

    REQUIRE( a.m_shape.size() == 27 );
}
