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

TEST_CASE( "numcpp::shape::transpose()", "numcpp::shape" ) {
    numcpp::shape s{ 1, 2, 3, 4 };

    REQUIRE( s.transpose().dimensions() == std::vector<int>{4, 3, 2, 1} );
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

TEST_CASE( "numcpp::shape::offset()", "numcpp::shape" ) {
    numcpp::shape s{ 2, 3, 4 };

    REQUIRE( s.offset(std::vector<int>{ 0, 0, 0 }) == 0 );
    REQUIRE( s.offset(std::vector<int>{ 0, 0, 1 }) == 1 );
    REQUIRE( s.offset(std::vector<int>{ 0, 0, 2 }) == 2 );
    REQUIRE( s.offset(std::vector<int>{ 0, 0, 3 }) == 3 );
    REQUIRE( s.offset(std::vector<int>{ 0, 1, 0 }) == 4 );
    REQUIRE( s.offset(std::vector<int>{ 0, 1, 1 }) == 5 );
    REQUIRE( s.offset(std::vector<int>{ 0, 1, 2 }) == 6 );
    REQUIRE( s.offset(std::vector<int>{ 0, 1, 3 }) == 7 );
    REQUIRE( s.offset(std::vector<int>{ 0, 2, 0 }) == 8 );
    REQUIRE( s.offset(std::vector<int>{ 0, 2, 1 }) == 9 );
    REQUIRE( s.offset(std::vector<int>{ 0, 2, 2 }) == 10 );
    REQUIRE( s.offset(std::vector<int>{ 0, 2, 3 }) == 11 );
    REQUIRE( s.offset(std::vector<int>{ 1, 0, 0 }) == 12 );
    REQUIRE( s.offset(std::vector<int>{ 1, 0, 1 }) == 13 );
    REQUIRE( s.offset(std::vector<int>{ 1, 0, 2 }) == 14 );
    REQUIRE( s.offset(std::vector<int>{ 1, 0, 3 }) == 15 );
    REQUIRE( s.offset(std::vector<int>{ 1, 1, 0 }) == 16 );
    REQUIRE( s.offset(std::vector<int>{ 1, 1, 1 }) == 17 );
    REQUIRE( s.offset(std::vector<int>{ 1, 1, 2 }) == 18 );
    REQUIRE( s.offset(std::vector<int>{ 1, 1, 3 }) == 19 );
    REQUIRE( s.offset(std::vector<int>{ 1, 2, 0 }) == 20 );
    REQUIRE( s.offset(std::vector<int>{ 1, 2, 1 }) == 21 );
    REQUIRE( s.offset(std::vector<int>{ 1, 2, 2 }) == 22 );
    REQUIRE( s.offset(std::vector<int>{ 1, 2, 3 }) == 23 );

    REQUIRE_THROWS_AS( s.offset(std::vector<int>{ 1 }), std::logic_error );
}

TEST_CASE( "numcpp::shape::advance()", "numcpp::shape" ) {
    numcpp::shape s{ 2, 3, 4 };

    auto indicies{ std::vector<int>{ 0, 0, 0} };

    s.advance(indicies);
    REQUIRE( indicies == std::vector<int>{ 0, 0, 1 } );

    s.advance(indicies);
    REQUIRE( indicies == std::vector<int>{ 0, 0, 2 } );

    s.advance(indicies);
    REQUIRE( indicies == std::vector<int>{ 0, 0, 3 } );

    s.advance(indicies);
    REQUIRE( indicies == std::vector<int>{ 0, 1, 0 } );

    s.advance(indicies);
    REQUIRE( indicies == std::vector<int>{ 0, 1, 1 } );

    s.advance(indicies);
    REQUIRE( indicies == std::vector<int>{ 0, 1, 2 } );

    s.advance(indicies);
    REQUIRE( indicies == std::vector<int>{ 0, 1, 3 } );

    s.advance(indicies);
    REQUIRE( indicies == std::vector<int>{ 0, 2, 0 } );

    s.advance(indicies);
    REQUIRE( indicies == std::vector<int>{ 0, 2, 1 } );

    s.advance(indicies);
    REQUIRE( indicies == std::vector<int>{ 0, 2, 2 } );

    s.advance(indicies);
    REQUIRE( indicies == std::vector<int>{ 0, 2, 3 } );

    s.advance(indicies);
    REQUIRE( indicies == std::vector<int>{ 1, 0, 0 } );

    s.advance(indicies);
    REQUIRE( indicies == std::vector<int>{ 1, 0, 1 } );

    s.advance(indicies);
    REQUIRE( indicies == std::vector<int>{ 1, 0, 2 } );

    s.advance(indicies);
    REQUIRE( indicies == std::vector<int>{ 1, 0, 3 } );

    s.advance(indicies);
    REQUIRE( indicies == std::vector<int>{ 1, 1, 0 } );

    s.advance(indicies);
    REQUIRE( indicies == std::vector<int>{ 1, 1, 1 } );

    s.advance(indicies);
    REQUIRE( indicies == std::vector<int>{ 1, 1, 2 } );

    s.advance(indicies);
    REQUIRE( indicies == std::vector<int>{ 1, 1, 3 } );

    s.advance(indicies);
    REQUIRE( indicies == std::vector<int>{ 1, 2, 0 } );

    s.advance(indicies);
    REQUIRE( indicies == std::vector<int>{ 1, 2, 1 } );

    s.advance(indicies);
    REQUIRE( indicies == std::vector<int>{ 1, 2, 2 } );

    s.advance(indicies);
    REQUIRE( indicies == std::vector<int>{ 1, 2, 3 } );

    s.advance(indicies);
    REQUIRE( indicies == std::vector<int>{ 0, 0, 0 } );

    auto i{ std::vector<int>{ 1 } };
    REQUIRE_THROWS_AS( s.advance(i), std::logic_error );
}
