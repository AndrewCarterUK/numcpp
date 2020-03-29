#include <catch2/catch.hpp>

#include <numcpp/shape.h>
#include <numcpp/numcpp.h>
#include <vector>

TEST_CASE( "numcpp::empty() for one dimensional array", "numcpp::empty" ) {
    auto a{ numcpp::numcpp<double>::empty(3) };

    REQUIRE( a.m_shape.size() == 3 );
    REQUIRE( a.m_shape.dimensions() == std::vector<int>{ 3 } );
}

TEST_CASE( "numcpp::empty() for multi dimensional array", "numcpp::empty" ) {
    auto s{ numcpp::shape{ 3, 3, 3 } };
    auto a{ numcpp::numcpp<double>::empty(s) };

    REQUIRE( a.m_shape == s );
}
