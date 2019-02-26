/*
 * GameOfLife.cpp
 *
 *  Created on: Feb 18, 2019
 *      Author: mercer
 *
 * This class models a society of cells growing according
 * to the rules of John Conway's Game of Life.
 *
 */
#ifndef GAMEOFLIFE_HPP_
#define GAMEOFLIFE_HPP_

#include <string>
#include <vector>
#include <iostream>

using namespace std;

// This class allows a society of cells to grow according
// to the rules from John Conway's Game of Life
class GameOfLife {

// --Data Member(s)
private:
    std::vector<std::vector<bool>> theSociety;

public:
    // Construct a board that is rows by cols size
    // with all elements set to false
    GameOfLife(unsigned long rows, unsigned long cols) {
        theSociety = {rows, vector<bool>(cols, false)};
    }

    // Grow a cell at the given location
    void growCellAt(unsigned long row, unsigned long col) {
        theSociety.at(row).at(col) = true;
    }

    // Check to see if a cell is at the given location
    bool cellAt(unsigned long row, unsigned long col) const {
        int outOfRange = theSociety.at(row).at(col);
        if (theSociety.at(row).at(col) == true) {
            return true;
        }
        return !true;
    }

    // Returns the colony as one big string
    std::string toString() const {
        string colony;
        for (int i = 0; i < theSociety.size(); i++) {
            for (int j = 0; j < theSociety.at(i).size(); j++) {
                if (theSociety.at(i).at(j) == 1) {
                    colony.push_back('O');
                } else {
                    colony.push_back('.');
                }
            }
            colony.push_back('\n');
        }
        return colony;
    }

    // Count the neighbors around the given location.
    // Use wraparound. A cell in row 0 has neighbors in
    // the last row if a cell is in the same column, or
    // the column to the left or right. In this example,
    // cell 0,5 has two neighbors in the last row, cell 2,8
    // has four neighbors, cell 2,0 has four neighbors,
    // cell 1,0 has three neighbors. The cell at 3,8 has
    // 3 neighbors. The potential location for a cell at 4,8
    // would have three neighbors.
    //
    // .....O..O
    // O........
    // O.......O
    // O.......O
    // ....O.O..
    //
    // The return values should always be in the range of 0 through 8.
    // return the number of neighbors around any cell using wrap around.
    int neighborCount(int row, int col) const {
        bool firstMember,secondMember;
        int societyRows = theSociety.size();
        int societyCols = theSociety.at(0).size();
        int wrapAroundCase;
        int neighborCount=0;
        vector<std::vector<bool>> shiftedSociety;
        std::vector<bool> tempVector;
        for(int i=0;i<theSociety.size()+2;i++){
            if(i==0){
                tempVector=theSociety.at(theSociety.size()-1);
                firstMember=tempVector.at(0);
                secondMember=tempVector.at(tempVector.size()-1);
                tempVector.insert(tempVector.begin(),secondMember);
                tempVector.push_back(firstMember);
                shiftedSociety.push_back(tempVector);
            }
            else if(i==theSociety.size()+1){
                tempVector=theSociety.at(0);
                firstMember=tempVector.at(0);
                secondMember=tempVector.at(tempVector.size()-1);
                tempVector.insert(tempVector.begin(),secondMember);
                tempVector.push_back(firstMember);
                shiftedSociety.push_back(tempVector);
            }
            else{
                tempVector=theSociety.at(i-1);
                firstMember=tempVector.at(0);
                secondMember=tempVector.at(tempVector.size()-1);
                tempVector.insert(tempVector.begin(),secondMember);
                tempVector.push_back(firstMember);
                shiftedSociety.push_back(tempVector);
            }
        }
        col++;
        row++;
        for(int i=row-1;i<=row+1;i++){
            for(int j=col-1;j<=col+1;j++){
                if(!(j==col && i==row)){
                    if(shiftedSociety.at(i).at(j)==true){
                        neighborCount++;
                    }
                }
            }
        }


        return neighborCount;
    }

    // Change the state to the next society of cells
    void update() {
        for(int i=0;i<theSociety.size();i++){
            for(int j=0;j<theSociety.at(i).size();j++){
                if(neighborCount(i,j)==3 && cellAt(i,j)==true){
                    growCellAt(i,j);
                }
                else if((neighborCount(i,j)==2 || neighborCount(i,j)==3) && cellAt(i,j)==true){
                    //do nothing
                }
                else if(neighborCount(i,j)<2 && cellAt(i,j)==true){
                    theSociety.at(i).at(j)==false;
                }
                else if(neighborCount(i,j)>3){
                    theSociety.at(i).at(j)==false;
                }
            }
        }
    }

};

#endif