#include <catch2/catch.hpp>

#include <numcpp/shape.h>

#include <vector>
#include <stdexcept>

TEST_CASE( "numcpp::shape instantiation from initializer list", "numcpp::shape" ) {
    numcpp::shape s{ 1, 2, 3, 4 };

    REQUIRE( s.dimensions().size() == 4 );
}

TEST_CASE( "numcpp::shape instantiation from vector", "numcpp::shape" ) {
    std::vector<int> dimensions{ 1, 2, 3, 4 };
    numcpp::shape s{ dimensions };

    REQUIRE( s.dimensions() == dimensions );
}

TEST_CASE( "numcpp::shape::operator==", "numcpp::shape" ) {
    numcpp::shape s1{ 1, 2, 3, 4 };
    numcpp::shape s2{ 1, 2, 3, 4 };
    numcpp::shape s3{ 2, 2, 3, 4 };

    REQUIRE( s1 == s2 );
    REQUIRE( !(s1 == s3) );
}

TEST_CASE( "numcpp::shape::operator!=", "numcpp::shape" ) {
    numcpp::shape s1{ 1, 2, 3, 4 };
    numcpp::shape s2{ 2, 2, 3, 4 };
    numcpp::shape s3{ 1, 2, 3, 4 };

    REQUIRE( s1 != s2 );
    REQUIRE( !(s1 != s3) );
}

TEST_CASE( "numcpp::shape::isScalar()", "numcpp::shape" ) {
    numcpp::shape s1{ 1, 2, 3, 4 };
    numcpp::shape s2{ 1 };
    numcpp::shape s3{ };

    REQUIRE( !s1.isScalar() );
    REQUIRE( !s2.isScalar() );
    REQUIRE( s3.isScalar() );
}

TEST_CASE( "numcpp::shape::sub()", "numcpp::shape" ) {
    numcpp::shape s1{ 1, 2, 3, 4 };
    numcpp::shape s2{ 2, 3, 4 };

    REQUIRE( s1.sub() == s2 );

    numcpp::shape s3{ };

    REQUIRE_THROWS_AS( s3.sub(), std::logic_error );
}

TEST_CASE( "numcpp::shape::size()", "numcpp::shape" ) {
    numcpp::shape s1{ 1, 2, 3, 4 };
    numcpp::shape s2{ 1 };
    numcpp::shape s3{ };

    REQUIRE( s1.size() == 24 );
    REQUIRE( s2.size() == 1 );
    REQUIRE( s3.size() == 1 );
}

TEST_CASE( "numcpp::shape::dimensions()", "numcpp::shape" ) {
    numcpp::shape s{ 1, 2, 3, 4 };

    REQUIRE( s.dimensions() == std::vector<int>{1, 2, 3, 4} );
}
