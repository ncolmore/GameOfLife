/**
 * This class has many test methods for testing the functions
 * that must be in a file named VectorFun.hpp
 *
 * Author  Rick Mercer and Nolan Colmore
 */
#include <vector>
#include <string>
#include "catch.hpp"
#include "GameOfLife.hpp"

using namespace std;

TEST_CASE("Constructore") {
    GameOfLife g1=GameOfLife(3,3);
    REQUIRE(1 == 2);
}


