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
#include <math.h>
using namespace std;

//------------------Grid Functions--------------------------
Grid::Grid()
//default constructor
{
    ifstream gridFile;
    char character = ' ';

    //Change these two lines to change the grid size
    gridFile.open("input15");
    gridSize = 15;

    gridMatrix = new char*[gridSize];
    for (int k = 0; k < gridSize; k++){
        gridMatrix[k] = new char[gridSize];
    }
    if (gridFile.is_open())
    {
        while (int(character) != 10){
            gridFile.get(character);
        }
        for (int i = 0; i < gridSize; i++ )
        {
            for (int j = 0; j < gridSize; j++)
            {
                character = ' ';
                while (int(character) == int(' ') || int(character) == 10){
                    gridFile.get(character);
                }
                gridMatrix[i][j] = character;
            }
        }
        gridFile.close();
    }
}

void Grid::printGrid()
//prints out the grid
{
    cout << "\n";
    for (int i = 0; i < gridSize; i++){
        for (int j = 0; j < gridSize; j++){
            cout << gridMatrix[i][j] << " ";
        }
        cout << "\n";
    }
}

int Grid::getGridSize(){
    return gridSize;
}

char Grid::getGridCharacterAt(int &row, int &column) const
{
    return gridMatrix[row][column];
}

std::string Grid::getStringFromGrid(int row, int column, int direction, int length) const{
    std::string gridString(1, gridMatrix[row][column]);
    switch (direction)
    {
        case 0:
        //get the East direction string
        {
            int i = 1;
            while (gridString.size() <= length)
            {
                if (i+column >= gridSize){
                        i = 0;
                        column = 0;
                }
                gridString += gridMatrix[(row)][(column+i)];
                i++;
            }
            break;
        }
        case 1:
        //get the SoutEast direction string
        {
            int i = 1;
            int j = 1;
            while (gridString.size() <= length)
            {
                if (i+column >= gridSize){
                        i = 0;
                        column = 0;
                }
                if (j+row >= gridSize){
                        j = 0;
                        row = 0;
                }
                gridString += gridMatrix[(row+j)][(column+i)];
                i++;
                j++;
            }
            break;
        }
        case 2:
        {
            //get the South direction string
            int i = 1;
            while (gridString.size() <= length)
            {
                if (i+row >= gridSize){
                        i = 0;
                        row = 0;
                }
                gridString += gridMatrix[(row+i)][column];
                i++;
            }
            break;
        }
        case 3:
        {
            //get the SouthWest direction string
            int i = 1;
            int j = 1;
            while (gridString.size() <= length)
            {
                if (column-i < 0){
                        i = 0;
                        column = gridSize-1;
                }
                if (j+row >= gridSize){
                        j = 0;
                        row = 0;
                }
                gridString += gridMatrix[(row+j)][(column-i)];
                i++;
                j++;
            }
            break;
        }
        case 4:
        {
            //get the West direction string
            int i = 1;
            while (gridString.size() <= length)
            {
                if ((column-i) < 0){
                        i = 0;
                        column = gridSize-1;
                        cout << "\ngridSize" << gridSize;
                }
                gridString += gridMatrix[(row)][(column-i)];
                cout << "\nGridString: " << gridString << "\ngridString.size() = " << gridString.size();
                i++;
            }
            break;
        }
        case 5:
        {
            //get the NorthWest direction string
            int i = 1;
            int j = 1;
            while (gridString.size() <= length)
            {
                if (column-i < 0){
                        i = 0;
                        column = gridSize-1;
                }
                if (row-j < 0){
                        j = 0;
                        row = gridSize-1;
                }
                gridString += gridMatrix[(row-j)][(column-i)];
                i++;
                j++;
            }
            break;
        }
        case 6:
        {
            //get the North direction string
            int i = 1;
            while (gridString.size() <= length)
            {
                if (row-i < 0){
                        i = 0;
                        row = gridSize-1;
                }
                gridString += gridMatrix[(row-i)][(column)];
                i++;
            }
            break;
        }
        case 7:
        {
            //get the NorthEast direction string
            int i = 1;
            int j = 1;
            while (gridString.size() <= length)
            {
                if (column+i >= gridSize){
                        i = 0;
                        column = 0;
                }
                if (row-j < 0){
                        j = 0;
                        row = gridSize-1;
                }
                gridString += gridMatrix[(row-j)][(column+i)];
                i++;
                j++;
            }
            break;
        }
    }
    cout << "\n";
    return gridString;
}
//------------------WordList Functions----------------------

WordList::WordList(){

}

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

void WordList::printWordList(){
    for (int i = 0; i < wordListVector.size(); i++){
        cout << i << ") " << wordListVector.at(i) << "\n";
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
    std::string key = wordListVector.at(0);
    cout << "This is the size\n" << wordListVector.size() << endl;
    for(int i = 1; i < wordListVector.size(); i++)
    //outer loop to go through each word
    {
        key = wordListVector.at(i);
        int j = i - 1;
        //cout << i << "\n";
        while (j >= 0)
        //while word is greater than the key
        {
            if (wordListVector.at(j) > key)
            {
                wordListVector[(j + 1)] = wordListVector.at(j);
                wordListVector[j] = key;
                j = j - 1;
            } else {
                j = -1;
            }
        }

    } //end of for loop for insertion sort

}

int WordList::lookUp(std::string &keyWord, int upperBound, int lowerBound)
{
    int mid = lowerBound+((upperBound - lowerBound)/2);
    std::string currentField = wordListVector[mid];
    if (currentField == keyWord)
    {
        cout << "The Word was found!";
        return mid;
    }
    else
    {
        cout << "\nUpper Bound:" << upperBound;
        if (upperBound <= lowerBound || upperBound-1 == lowerBound ){

            if (upperBound-1 == lowerBound)
            //if the bounds have crossed, then the function did not find the keyWord
            {
                std::string currentField = wordListVector[upperBound];
                int i = 0;
                cout << currentField << "\n";
                //iterate through the string and check for a partial match
                //this will help the FindMatches function with backtracking

                while (keyWord[i] == currentField[i]){
                    cout << "\nThis is equal:" << keyWord[i] << " == " << currentField[i];
                    if (i == keyWord.size()-1)
                    {
                        cout << "\nThere was a partial match, continuing search";
                        return -2;
                    }
                    i++;
                }
            } else {
                cout << "couldn't find your word";
                return -1;
            }
        }
        if (currentField > keyWord){
            return lookUp(keyWord, mid-1, lowerBound);
        } else {
            return lookUp(keyWord, upperBound, mid+1);
        }
    }

}

int WordList::getWordListVectorSize() const{
    return wordListVector.size();
}

void merge(vector<string>* a, vector<string> left, vector<string> right)
//void merge(std::vector< std::string>* a, std::vector< std::string>* left, std::vector< std::string>* right)
{       if(left.size() == 1 && right.size() == 1)
        //if there is only one word in each vector
        {
            if(left.at(0) < right.at(0))
            //if left word is less than right word
            {
                a->at(0) = left.at(0);
                a->at(1) = right.at(0);
            }
            else if(left.at(0) >= right.at(0))
            {
                a->at(1) = left.at(0);
                a->at(0) = right.at(0);
            }
        }
        else
        {
            int leftPlace = 0, rightPlace = 0, place = 0;
            int left_end = left.size();
            int right_end = right.size();
            while(leftPlace != left_end)
            {
              if(left.at(leftPlace) < right.at(rightPlace) && (rightPlace == right_end)) {
                  a->at(place) = left.at(leftPlace);
                  leftPlace++;
              }
              else
              {
                  a->at(place) = right.at(rightPlace);
                  rightPlace++;
              }
              place++;
            }

            while(rightPlace == right_end) {
              a->at(place) = right.at(rightPlace);
              rightPlace++;
              place++;
            }
        }
        /*int totalSize = right.size() + left.size();
        cout << totalSize << endl;
        int leftPlace = 0, rightPlace = 0, place = 0;
        while(place < (totalSize-2))
        //while there are still values in separate matrices
        {
          string leftWord = left.at(leftPlace);
          string rightWord = right.at(rightPlace);
          cout << "\nright" << rightWord;
          cout << "\nleft" << leftWord;
          if((leftPlace) == left.size())
          //if all elements from left have been inserted
          {

              a->at(place) = rightWord;
              rightPlace++;
          }
          else if((rightPlace) == right.size())
          //if left vector is empty, place
          {
              a->at(place) = leftWord;
              leftPlace++;
          }
          else if( leftWord <= rightWord)
          //if the first value in left vector is less than first value in right
          {
              a->at(place) = leftWord;
              leftPlace++;
          } else
          //else if right is less than than left
          {
            a->at(place) = rightWord;
            rightPlace++;
          }
          for (int i = 0; i < a->size(); i++){
              cout << i << ") " << a->at(i) << "\n";
          }
          place++;
      }*/
}


void mergeSortHelper(vector<string>* a)
//returns a sorted list
{

  int size = a->size();
  if(size == 1) return;
  if(size == 0) return;
  int midPoint = size/2;
  vector<string> left(a->begin(), a->begin() + midPoint);
  vector<string> right(a->begin() + midPoint + 1, a->end());
  mergeSortHelper(&left);
  mergeSortHelper(&right);
  merge(a, left, right);

}

void WordList::mergeSort()
//merge sort function
{

  int size = wordListVector.size();
  if(size == 0) return;
  int midPoint = size/2;
  vector<string> left(wordListVector.begin(), wordListVector.begin() + midPoint + 1);
  vector<string> right(wordListVector.begin() + midPoint + 1, wordListVector.end());
  mergeSortHelper(&left);
  mergeSortHelper(&right);
  merge(&wordListVector, left, right);
}

void quickHelper(vector<string>* a, int left, int right)
//helper for recursion in quicksort
{
      int i = left, j = right;
      string tmp;
      string pivot = a->at((left + right) / 2);

      //partition
      while (i <= j)
      {
            while (a->at(i) < pivot)
                  i++;
            while (a->at(j) > pivot)
                  j--;

            if (i <= j)
            {
                  tmp = a->at(i);
                  a->at(i) = a->at(j);
                  a->at(j) = tmp;
                  i++;
                  j--;
            }
      }

      if (left < j)
            quickHelper(a, left, j);
      if (i < right)
            quickHelper(a, i, right);
}

void WordList::quickSort()
//quicksort function
{
    int left = 0;
    int right = wordListVector.size() - 1;
    int i = left, j = right;
    string tmp;
    string pivot = wordListVector.at((left + right) / 2);

    //partition
    while (i <= j) {
          while (wordListVector.at(i) < pivot)
                i++;
          while (wordListVector.at(j) > pivot)
                j--;
          if (i <= j) {
                tmp = wordListVector.at(i);
                wordListVector.at(i) = wordListVector.at(j);
                wordListVector.at(j) = tmp;
                i++;
                j--;

          }
    }

    if (left < j)
          quickHelper(&wordListVector, left, j);
    if (i < right)
          quickHelper(&wordListVector, i, right);
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

//------------------Global Functions------------------------
void FindMatches(WordList &wordListObj, Grid &gridObj)
//function is passed the word list and the grid
//prints out the word that can be found
{
    std::vector< std::string > wordsFoundList;

    gridObj.printGrid();
    wordListObj.insertionSort();
    wordListObj.printWordList();

    int location = -1;
    int stringLength = 1;

    for (int i = 0; i < gridObj.getGridSize(); i++){
        for (int j =0; j < gridObj.getGridSize(); j++){

            std::string theKey(1,gridObj.getGridCharacterAt(i,j));

            location = wordListObj.lookUp(theKey, wordListObj.getWordListVectorSize()-1, 0);

            if (location >= 0){
                cout << wordListObj.getWord(location) << "\n";
            } else if(location == -2){
                while (location == -2){
                    stringLength += 1;
                    for (int k = 0; k < 8; k++){
                        theKey = gridObj.getStringFromGrid(i, j, k, stringLength);
                        location = wordListObj.lookUp(theKey, wordListObj.getWordListVectorSize()-1, 0);
                        //Last thought before quitting for the night
                        //I need to make a vector that stores all the directions that I
                        //no longer need to check, thus saving a binary search. Use the
                        //index of the vector for each direction. will make sense tomorrow!
                    }


                }

            }
        }
    }
        //cout << wordListObj.lookUp(theKey, newWords.getWordListVectorSize()-1, 0);
}
//------------------Main Function--------------------------



int main()
//main Function
{

    std::cout << "Clock time: " << clock() << std::endl;
    srand (time(NULL));   //Uses time to make rand more random
    clock_t t1,t2;

    t1=clock();

    Grid newGrid;
    newGrid.printGrid();
    WordList newWords;
    newWords.loadWordList("wordlistPrac.txt");
    //newWords.insertionSort();
    newWords.mergeSort();
    //newWords.quickSort();
    newWords.printWordList();
    std::string theKey = "ab";
    cout << newWords.lookUp(theKey, newWords.getWordListVectorSize()-1, 0);

    cout << "\n--- Find Matches Test ---\n";
    //FindMatches(newWords, newGrid);

    //test get string from grid funciton
    int newRow = 0;
    int newCol = 13;
    int dir = 7;
    int length = 20;
    cout << "code got here";
    cout << "\nThe grid contains: " << newGrid.getStringFromGrid(newRow, newCol, dir, length);

    t2=clock();
    float diff = ((float)t2-(float)t1);

    float seconds = diff / CLOCKS_PER_SEC;
    std::cout << "\n\nRuntime of program: "<< seconds << " seconds\n";

} // end of main function
