// Grid.h
// Problem Set 3a                                 Chris Canal
// Team cansym                                    canal.c@husky.neu.edu
//                                                Sarada Symonds
//                                                symonds.s@husky.neu.edu
//
// Wordlist header file for homework 3a.
// Contains declarations for wordlist class.

#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <fstream>

#ifndef Grid_Grid_h
#define Grid_Grid_h

class Grid
//class declaration for the WordList class
{
  public:
    //default constructor
    Grid();

    Grid(std::string fileName);

    void printGrid();

    int getGridSize();

    char getGridCharacterAt(int &row, int &column) const;

    std::string getStringFromGrid(int row, int column, int direction, int length) const;

  private:
    //vector to store words in
    char** gridMatrix;
    int gridSize;

}; //end of WordList

#endif
