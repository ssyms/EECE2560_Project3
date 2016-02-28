// WordList.h
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

#ifndef WordList_WordList_h
#define WordList_WordList_h

class WordList
//class declaration for the WordList class
{
  public:
    //default constructor
    WordList();

    //Prints out all the words
    void printWordList();

    //stores a txt file of words in the wordListVector
    void loadWordList(std::string fileName);

    //returns the word in the list based on given int i
    std::string getWord(int i);

    //overload operator to print out wordlist
    friend std::ostream& operator << (std::ostream & ostr, WordList wordObj);

    int getListSize() const;

    //sorts word list using insertion sort
    void insertionSort();

    //sorts word list using merge sort
    void mergeSort();

    //sorts word list using quicksort
    void quickSort();

    //looks up whether a word is on the list and returns the location
    int lookUp(std::string &keyWord, int upperBound, int lowerBound);

  private:
    //vector to store words in
    std::vector< std::string > wordListVector;

}; //end of WordList

#endif
