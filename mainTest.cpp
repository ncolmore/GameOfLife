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

TEST_CASE("Constructor") {

}


TEST_CASE("Grow Cell") {
    GameOfLife g1=GameOfLife(5,5);
g1.growCellAt(3,2);
cout<<g1.toString();
}


TEST_CASE("Neighbors Top") {
    GameOfLife g1=GameOfLife(5,5);
    g1.growCellAt(0,2);
    g1.growCellAt(4,2);
    int neighbors=g1.neighborCount(0,2);
    cout<<g1.toString();
    cout<<neighbors;
}

TEST_CASE("1 Neighbor Top Left") {
    GameOfLife g1=GameOfLife(5,5);
    g1.growCellAt(0,0);
    g1.growCellAt(4,4);
    int neighbors=g1.neighborCount(0,0);
    cout<<g1.toString();
    cout<<neighbors;
}
TEST_CASE("2 Neighbors Top Left") {
    GameOfLife g1=GameOfLife(5,5);
    g1.growCellAt(0,0);
    g1.growCellAt(4,4);
    g1.growCellAt(4,0);
    int neighbors=g1.neighborCount(0,0);
    cout<<g1.toString();
    cout<<neighbors;
}
TEST_CASE("3 Neighbors Top Left") {
    GameOfLife g1=GameOfLife(5,5);
    g1.growCellAt(0,0);
    g1.growCellAt(4,4);
    g1.growCellAt(4,0);
    g1.growCellAt(0,4);
    int neighbors=g1.neighborCount(0,0);
    cout<<g1.toString();
    cout<<neighbors;
}

TEST_CASE("3 Neighbors Top Right") {
    GameOfLife g1=GameOfLife(5,5);
    g1.growCellAt(0,4);
    g1.growCellAt(4,4);
    g1.growCellAt(4,0);
    g1.growCellAt(0,0);
    int neighbors=g1.neighborCount(0,4);
    cout<<g1.toString();
    cout<<neighbors;
}
TEST_CASE("2 Neighbors Top Right") {
    GameOfLife g1=GameOfLife(5,5);
    g1.growCellAt(0,4);
    g1.growCellAt(4,4);
    g1.growCellAt(4,0);
    int neighbors=g1.neighborCount(0,4);
    cout<<g1.toString();
    cout<<neighbors;
}

TEST_CASE("3 Neighbors Bottom Right") {
    GameOfLife g1=GameOfLife(5,5);
    g1.growCellAt(0,4);
    g1.growCellAt(4,4);
    g1.growCellAt(4,0);
    g1.growCellAt(0,0);
    int neighbors=g1.neighborCount(4,4);
    cout<<g1.toString();
    cout<<neighbors;
}

TEST_CASE("Grow Cell Rule 1") {
    GameOfLife g1=GameOfLife(5,7);
    g1.growCellAt(1, 2);
    g1.growCellAt(1, 4);
    g1.growCellAt(2, 2);
    g1.growCellAt(2, 3);
    g1.growCellAt(2, 4);
    cout << g1.toString();
    for (int i = 0; i < 10; i++) {
    cout << endl;
    g1.update();
    cout << g1.toString();
}
}