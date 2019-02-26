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


TEST_CASE("Neighbors Top") {
    g1.growCellAt(0,2);
    g1.growCellAt(4,2);
    int neighbors=g1.neighborCount(0,2);
    cout<<g1.toString();
    cout<<neighbors;
}

TEST_CASE("Neighbors Top Left") {
    g1.growCellAt(0,0);
    g1.growCellAt(4,4);
    g1.growCellAt(4,0);
    g1.growCellAt(0,4);
    int neighbors=g1.neighborCount(0,0);
    cout<<g1.toString();
    cout<<neighbors;
}