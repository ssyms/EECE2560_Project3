// main.cpp
// Problem Set 3a                                 Chris Canal
// Team cansym                                    canal.c@husky.neu.edu
//                                                Sarada Symonds
//                                                symonds.s@husky.neu.edu
//
// Main program file for homework 3a.
#include "WordList.h"
#include "Grid.h"
#include <iostream>
#include <cstdlib>
#include <time.h>    //for making rand() more random
#include <vector>
#include <string>
#include <cstring>
/*
#include "input15"
#include "input30"
#include "input50"
#include "input250"
*/
using namespace std;

//------------------Grid Functions--------------------------
Grid::Grid()
//default constructor
{
    ifstream gridFile;
    char character;
    gridFile.open("input15");
    if (gridFile.is_open())
    {
        for (int i = 0; i < 15; i++ )
        {
            for (int j = 0; j < 15; j++)
            {
                gridFile.get(character);
                gridMatrix[i][j] = character;
            }
        }
        gridFile.close();
    }
}

//------------------WordList Functions----------------------

void WordList::loadWordList(std::string fileName)
//loads word list
{
    ifstream wordListFile;
    std::string line;
    wordListFile.open(fileName);
    if (wordListFile.is_open())
    {
        while ( getline(wordListFile,line) )
        {
            wordListVector.push_back(line);
        }
        wordListFile.close();
    }
}

std::string WordList::getWord(int i)
//returns a word in the array at the given location
{
  return wordListVector.at(i);
}

void WordList::insertionSort()
//sorts the list using insertion sort
{

  for(int i = 1; i < wordListVector.size(); i++)
  //outer loop to go through each word
  {
    std::string key = wordListVector.at(i);
    int j = i - 1;

    while ((j > 0) && (wordListVector.at(j) > key))
    //while word is greater than the key
    {
      wordListVector.assign((j + 1), (wordListVector.at(j)));
      j = j - 1;
    }

    wordListVector[(j + 1)] = key;
  } //end of for loop for insertion sort

}

/*void merge(std::vector< std::string >* a, std::vector< std::string >* left, std::vector< std::string >* right)
{
    while(*right != NULL || *left != NULL)
    //while there are still values in separate matrices
    {
      if(*right == NULL)
      //if right vector is empty
      {
          *a = *left;
          *a++;
          *left++;
      }
      else if(*left == NULL)
      //if left vector is empty, place
      {
        *a = *right;
        *a++;
        *right++;
      }
      else if(*left <= *right)
      //if the first value in left vector is greater than first value in right
      {
          *a = *left;
          *a++;
          *left++;
      } else
      //else if right is greater than left
      {
        *a = *right;
        *a++;
        *right++;
      }
  }
}

void mergeSortHelper(std::vector< std::string >* a)
//returns a sorted list
{
  int size = a.size();
  if(size == 1) return;
  int midPoint = size/2;
  std::vector< std::string > left(a.begin(), a.begin() + midPoint);
  std::vector< std::string > right(a.begin() + midPoint + 1, a.end());
  mergeSortHelper(left);
  mergeSortHelper(right);
  merge(a, left, right);

}*/

void WordList::mergeSort()
//merge sort function
{
  /*int size = wordListVector.size();
  if(size == 1) return;
  int midPoint = size/2;
  std::vector< std::string > left(wordListVector.begin(), wordListVector.begin() + midPoint);
  std::vector< std::string > right(wordListVector.begin() + midPoint + 1, wordListVector.end());
  mergeSortHelper(left);
  mergeSortHelper(right);
  merge();*/

}



//------------------Global Operators------------------------
std::ostream& operator << (std::ostream & ostr, WordList wordObj)
//overload << operator for WordList
{
  for(int i = 0; i < wordObj.wordListVector.size(); i++)
  //prints out each word in list
  {
    ostr << wordObj.getWord(i) << std::endl;
  }
  return ostr;
}

//------------------Main Function--------------------------



int main()
//main Function
{

} // end of main function
