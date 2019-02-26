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
GameOfLife g1=GameOfLife(5,5);
TEST_CASE("Constructor") {

}


TEST_CASE("Grow Cell") {
g1.growCellAt(3,2);
cout<<g1.toString();
}
