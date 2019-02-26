//
// Created by nonee on 2/26/2019.
//

#ifndef GAMEOFLIFE_MAINTEST_H
#define GAMEOFLIFE_MAINTEST_H


class mainTest {

};


#endif //GAMEOFLIFE_MAINTEST_H
/**
 * This class has many test methods for testing the functions
 * that must be in a file named VectorFun.hpp
 *
 * Author  Rick Mercer and Nolan Colmore
 */
#include <vector>
#include <string>
#include "catch.hpp"
#include "VectorFun.hpp"

using namespace std;

TEST_CASE("testSortOfSort1") {
    vector<int> x = {2, 4, 3, 1};
    sortOfSort(x);
    REQUIRE(1 == 2);
}


TEST_CASE("testNumberOfPairs1") {
//    vector<string> s1{"a", "b", "c"};
//    REQUIRE(0 == numberOfPairs(s1));
//    vector<int> s2={1, 1, 1};
//   REQUIRE(numberOfPairs(s2)==2);// returns 2
//    vector<int> s3={1, 2, 1, 2, 1};
//    REQUIRE(numberOfPairs(s3)==0);// returns 2
//    vector<string> s4{"a", "a", "a"};
//    REQUIRE(numberOfPairs(s4)==2);// returns 2
// numberOfPairs( {"a", "b", "c" } ) returns 0
// numberOfPairs( {"a", "a", "a"} ) returns 2
// numberOfPairs( {"a", "a", "b", "b" } ) returns 2
    vector<int> s5 = {};
    REQUIRE(numberOfPairs(s5) == 0);
// numberOfPairs( { } ) returns 0
// numberOfPairs( {"a"} ) returns 0
    vector<string> s6 = {"a"};
    REQUIRE(numberOfPairs(s6) == 0);
}


TEST_CASE("testSumIsGreater") {
    vector<double> x = {1.1, 2.2, 3.3};
    REQUIRE(sumGreaterThan(x, 4.0));
}

TEST_CASE("testSumIsGreater2") {
    vector<double> x2 = {1.1, 2.2, 3.3};
    REQUIRE(!sumGreaterThan(x2, 6.6));
}

TEST_CASE("testFrequency") {
    vector<int> nums{1, 1, 1, 3, 3, 5, 6, 6, 10, 10, 10};
    vector<int> result = frequency(nums);
    REQUIRE(0 == result[0]);
    REQUIRE(3 == result[1]);
    REQUIRE(0 == result[2]);
    REQUIRE(2 == result[3]);
    REQUIRE(0 == result[4]);
    REQUIRE(1 == result[5]);
    REQUIRE(2 == result[6]);
    REQUIRE(0 == result[7]);
    REQUIRE(0 == result[8]);
    REQUIRE(0 == result[9]);
    REQUIRE(3 == result[10]);
}

TEST_CASE("testFailedHowMany") {
    vector<string> strs{"a", "C", "X", "x", "b", "a", "b",
                        "b", "a",
                        "b", "a"};
    REQUIRE(4 == howMany(strs, "b"));
}

TEST_CASE("testEvensLeft") {
    vector<int> a = {1, 2, 3, 4, 5, 6, 7};
    evensLeft(a);
// left side of the array at indexes 0..2 is even
    for (int i = 0; i <= 2; i++)
        REQUIRE(0 == a[i] % 2);
// right side of the array at indexes 3..6 is odd
    for (int i = 3; i <= 6; i++)
        REQUIRE(1 == a[i] % 2);
}


TEST_CASE("testShiftNTimes") {
    vector<int> a = {1, 2, 3};
    shiftNTimes(a, 1);
    REQUIRE(2 == a[0]);
    REQUIRE(3 == a[1]);
    REQUIRE(1 == a[2]);
}


TEST_CASE("testRange") {
    vector<int> x = {4};
    vector<int> x2 = {1, 2, -3, 4};
    REQUIRE(0 == range(x));
    REQUIRE(7 == range(x2));
}


TEST_CASE("fizzBuzz") {
    vector<string> strs = fizzBuzz(1, 6);
    REQUIRE("1" == strs[0]);
    REQUIRE("2" == strs[1]);
    REQUIRE("Fizz" == strs[2]);
    REQUIRE("4" == strs[3]);
    REQUIRE("Buzz" == strs[4]);
}