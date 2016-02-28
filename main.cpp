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
#include <time.h>
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
    gridFile.open("input250");
    gridSize = 250;

    gridMatrix = new char*[gridSize];
    for (int k = 0; k < gridSize; k++)
    //creates a pointer array inside each element of the first pointer array
    {
        gridMatrix[k] = new char[gridSize];
    }

    if (gridFile.is_open())
    //open the file
    {

        while (int(character) != 10)
        //gets character until new line
        {
            gridFile.get(character);
        }

        for (int i = 0; i < gridSize; i++ )
        //goes through each row
        {

            for (int j = 0; j < gridSize; j++)
            //goes through each column
            {
                character = ' ';

                while (int(character) == int(' ') || int(character) == 10)
                //when the character equals space or new line, grabs new char
                {
                    gridFile.get(character);
                }

                gridMatrix[i][j] = character;
            } //end of going through column
        } //end of going through rows

        gridFile.close();
    } //end of if file is open

} //end of grid constructor

Grid::Grid(int userGrid)
//default constructor
{
    ifstream gridFile;
    char character = ' ';
    string in = "input";
    std::string s = std::to_string(userGrid);

    string fileName = in + s;
    //Change these two lines to change the grid size
    gridFile.open(fileName);
    gridSize = userGrid;

    gridMatrix = new char*[gridSize];
    for (int k = 0; k < gridSize; k++)
    //creates a pointer array inside each element of the first pointer array
    {
        gridMatrix[k] = new char[gridSize];
    }

    if (gridFile.is_open())
    //open the file
    {

        while (int(character) != 10)
        //gets character until new line
        {
            gridFile.get(character);
        }

        for (int i = 0; i < gridSize; i++ )
        //goes through each row
        {

            for (int j = 0; j < gridSize; j++)
            //goes through each column
            {
                character = ' ';

                while (int(character) == int(' ') || int(character) == 10)
                //when the character equals space or new line, grabs new char
                {
                    gridFile.get(character);
                }

                gridMatrix[i][j] = character;
            } //end of going through column
        } //end of going through rows

        gridFile.close();
    } //end of if file is open

} //end of grid constructor

void Grid::printGrid()
//prints out the grid
{
    cout << "\n";
    for (int i = 0; i < gridSize; i++)
    //prints out each row
    {
        for (int j = 0; j < gridSize; j++)
        //prints out each column
        {
            cout << gridMatrix[i][j] << " ";
        }

        cout << "\n";
    } //end of for loop to print each row

} //end of print grid

int Grid::getGridSize()
//returns grid size
{
    return gridSize;
}

char Grid::getGridCharacterAt(int row, int col) const
//returns character in grid
{
    return gridMatrix[row][col];
}

std::string Grid::getStringFromGrid(int row, int col, int dir, int length) const
//returns a string from the grid
{
    std::string gridString(1, gridMatrix[row][col]);

    switch (dir)
    //switches so that it searches completely around word
    {
        case 0:
        //get the East direction string
        {
            int i = 1;

            while (gridString.size() <= length)
            //while the string is less than or equal to length of word
            {
                if (i + col >= gridSize)
                //resets column size when it reaches the end
                {
                        i = 0;
                        col = 0;
                }

                gridString += gridMatrix[(row)][(col + i)];
                i++;
            } //end of while loop to go through string

            break;
        } //end of east case

        case 1:
        //get the SoutEast direction string
        {
            int i = 1;
            int j = 1;
            while (gridString.size() <= length)
            //while the string is less than or equal to length of word
            {
                if (i + col >= gridSize)
                //resets column
                {
                        i = 0;
                        col = 0;
                }

                if (j + row >= gridSize)
                //resets row
                {
                        j = 0;
                        row = 0;
                }

                gridString += gridMatrix[(row + j)][(col + i)];
                i++;
                j++;
            }//end of while loop to go through string

            break;
        } //end of southeast case
        case 2:
        //get the South direction string
        {
            int i = 1;

            while (gridString.size() <= length)
            //while the string is less than or equal to length of word
            {
                if (i + row >= gridSize)
                //resets row
                {
                        i = 0;
                        row = 0;
                }

                gridString += gridMatrix[(row + i)][col];
                i++;
            } //end of while loop to go through string

            break;
        } //end of south case
        case 3:
        //get the SouthWest direction string
        {
            int i = 1;
            int j = 1;

            while (gridString.size() <= length)
            //while the string is less than or equal to length of word
            {
                if (col - i < 0)
                //resets column
                {
                        i = 0;
                        col = gridSize - 1;
                }

                if (j + row >= gridSize)
                //resets row
                {
                        j = 0;
                        row = 0;
                }
                gridString += gridMatrix[(row + j)][(col - i)];
                i++;
                j++;
            } //end of while loop to go through string

            break;
        } //end of southwest case
        case 4:
        //get the West direction string
        {
            int i = 1;

            while (gridString.size() <= length)
            //while the string is less than or equal to length of word
            {
                if ((col - i) < 0)
                //resets column
                {
                        i = 0;
                        col = gridSize - 1;
                }

                gridString += gridMatrix[(row)][(col - i)];
                i++;
            } //end of while loop to go through string

            break;
        } //end of west case
        case 5:
        //get the NorthWest direction string
        {
            int i = 1;
            int j = 1;

            while (gridString.size() <= length)
            //while the string is less than or equal to length of word
            {
                if ((col - i) < 0)
                //resets column
                {
                        i = 0;
                        col = gridSize - 1;
                }

                if ((row - j) < 0)
                //resets row
                {
                        j = 0;
                        row = gridSize-1;
                }

                gridString += gridMatrix[(row - j)][(col - i)];
                i++;
                j++;
            } //end of while loop to go through string

            break;
        } //end of northwest case
        case 6:
        //get the North direction string
        {
            //get the North direction string
            int i = 1;

            while (gridString.size() <= length)
            //while the string is less than or equal to length of word
            {
                if (row - i < 0)
                //resets row
                {
                        i = 0;
                        row = gridSize - 1;
                }

                gridString += gridMatrix[(row - i)][(col)];
                i++;
            } //end of while loop to go through string

            break;
        }   //end of north case
        case 7:
        //get the NorthEast direction string
        {
            int i = 1;
            int j = 1;

            while (gridString.size() <= length)
            //while the string is less than or equal to length of word
            {
                if ((col + i) >= gridSize)
                //resets column
                {
                        i = 0;
                        col = 0;
                }

                if (row - j < 0)
                //resets row
                {
                        j = 0;
                        row = gridSize - 1;
                }

                gridString += gridMatrix[(row - j)][(col + i)];
                i++;
                j++;
            } //end of while loop to go through string

            break;
        } //end of northeast case

    } //end of switch statement

    return gridString;

} //end of getStringFromGri function
//------------------WordList Functions----------------------

WordList::WordList()
//default constructor
{

}

void WordList::loadWordList(std::string fileName)
//loads word list
{
    ifstream wordListFile;
    std::string line;
    wordListFile.open(fileName);

    if (wordListFile.is_open())
    //checks that file is open
    {
        while (getline(wordListFile,line))
        //while there are new lines in the file
        {
            wordListVector.push_back(line);
        }

        wordListFile.close();
    } //end of if for open file

} //end of load word list function

void WordList::printWordList()
//prints word list
{
    for (int i = 0; i < wordListVector.size(); i++)
    //prints each word in list
    {
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

        while (j >= 0)
        //while word is greater than the key
        {
            if (wordListVector.at(j) > key)
            //if word is greater than key
            {
                wordListVector[(j + 1)] = wordListVector.at(j);
                wordListVector[j] = key;
                j = j - 1;
            }
            else
            //if word is ont greater than key
            {
                j = -1;
            }

            cout << "\n" << i;

        } //end of while loop for greater than

    } //end of for loop for insertion sort

} //end of intertion sort

int WordList::lookUp(std::string &keyWord, int upperBound, int lowerBound)
//word list look up function returns location of word on a list
{
    int mid = lowerBound + ((upperBound - lowerBound) / 2);
    std::string currentField = wordListVector[mid];

    if (currentField == keyWord)
    //if you found the word
    {
        return mid;
    }
    else
    //else keep looking
    {
        if(upperBound <= lowerBound)
        //if top of list is less than or equal to lower list
        {
            //iterate through the string and check for a partial match
            //this will help the FindMatches function with backtracking
            int i = 0;
            int edgeCaseAdjustment = 0;

            if (lowerBound == 0)
            //edge case - first word in list
            {
                edgeCaseAdjustment = 1;
            }
            else if (lowerBound >= getListSize() - 1)
            //edge case - last word in list
            {
                edgeCaseAdjustment = -2;
            } //end of edge case if statements

            for (int j = edgeCaseAdjustment; j < edgeCaseAdjustment + 3; j++)
            //when there is a partial match
            {
                currentField = wordListVector[(j+lowerBound)];
                i = 0;

                while (keyWord[i] == currentField[i])
                //while the word matches partially
                {
                    if (i == keyWord.size() - 1)
                    //return int to indicate partial match
                    {
                        return -2;
                    }

                    i++;
                } //end of while loop

            } //end of for loop

            return -1;
        } //end of upperBoud <=owerBound

        if (currentField > keyWord)
        //if word looking up is greater than keyword, search lower part of list
        {
            return lookUp(keyWord, mid - 1, lowerBound);
        }
        else
        //if keyword is greater than current word, search last half of list
        {
            return lookUp(keyWord, upperBound, mid + 1);
        } //end of recursive
    }

} //end of lookup function

int WordList::getListSize() const
//returns size of wordlist
{
    return wordListVector.size();
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
            while (a->at(i) < pivot) //determines how many are less than pivot
                  i++;

            while (a->at(j) > pivot) //determines how many are more than pivot
                  j--;

            if (i <= j)
            //checks how the list was divided around pivot, inserts in list
            {
                  tmp = a->at(i);
                  a->at(i) = a->at(j);
                  a->at(j) = tmp;
                  i++;
                  j--;
            }
      }

      if (left < j)
            quickHelper(a, left, j); //recurs on quickHelper

      if (i < right)
            quickHelper(a, i, right);   //recurs on quickHelper

} //end of quick helper

void WordList::quickSort()
//quicksort function
{
    int left = 0;
    int right = wordListVector.size() - 1;
    int i = left, j = right;
    string tmp;
    string pivot = wordListVector.at((left + right) / 2);

    //partition
    while (i <= j)
    //while size of left is less than size of right
    {
          while (wordListVector.at(i) < pivot) //counts strings less than pivot
                i++;

          while (wordListVector.at(j) > pivot) //strings greater than pivot
                j--;

          if (i <= j)
          //if left is less than right
          {
                tmp = wordListVector.at(i);
                wordListVector.at(i) = wordListVector.at(j);
                wordListVector.at(j) = tmp;
                i++;
                j--;

          } //end of if left is less than right

    } //end of while left is less than right

    if (left < j)   //if left size is less than number less than pivot
          quickHelper(&wordListVector, left, j);

    if (i < right)  //if right size is less than number greater than pivot
          quickHelper(&wordListVector, i, right);

} //end of quicksort

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
} //end of << overload

//------------------Global Functions------------------------
void FindMatches(WordList &listObj, Grid &gridObj)
//prints out the word that can be found
{
    std::vector< std::string > wordsFoundList;
    std::string first = "";
    wordsFoundList.push_back(first);

    int loc = -1;
    int stringLength = 3; //ensures minimum stringLength found is 5
    int loopCounter = 0;
    int loopCounter1 = 0;

    for (int i = 0; i < gridObj.getGridSize(); i++)
    //for the number of rows
    {
        for (int j = 0; j < gridObj.getGridSize(); j++)
        //for number of columns
        {
            loopCounter1++;
            loc = -1;

            std::string theKey(1,gridObj.getGridCharacterAt(i,j));

            loc = -2;

            for (int k = 0; k < 8; k++)
            //for each direction around a letter
            {
                loopCounter++;
                while (loc == -2)
                //while there is a partial word match
                {
                    stringLength += 1;
                    theKey = gridObj.getStringFromGrid(i, j, k, stringLength);
                    loc = listObj.lookUp(theKey, listObj.getListSize() - 1, 0);

                    if (loc >= 0)
                    //if you found a word
                    {
                        for  (int z = 0; z < wordsFoundList.size(); z++)
                        //checks if it is on the list
                        {
                            if (listObj.getWord(loc) == wordsFoundList[z])
                            //if it is on the list
                            {
                                z = wordsFoundList.size();
                            }
                            else if (z == wordsFoundList.size() - 1)
                            //if the word is not on the list...new word
                            {
                                wordsFoundList.push_back(listObj.getWord(loc));
                                cout << "\nFound a new word ";
                                cout << listObj.getWord(loc);
                            }

                        } //end of for loop to check if it's on the list

                        loc = -2;
                    } //end of if you found a word

                } //end of while there is a partial match

                stringLength = 3; //resets min length to search new direction
            } //end of for loop to search each direction

        } //end of for loop to go through each column

    } //end of for loop to go through each row
    cout << "\nWe found " << wordsFoundList.size()-1 << " words!";

} //end of findMatches

void Search(int searchChoice)
//searches through wordlist and grid to find matches
{
    int fileNumber = 250;
    cout << "\nWhich word puzzle would you like to search?\n";
    cout << "Your options are 15, 30, 50 or 250. Integers only please!\n";
    cin >> fileNumber;

    std::cout << "Clock time: " << clock() << std::endl;
    clock_t t1,t2, t3, t4, t5, t6;
    t1 = clock();
    Grid newGrid(fileNumber);
    WordList newWords;
    newWords.loadWordList("wordlist.txt");
    switch (searchChoice)
    //Use user input to choose search
    {
        case 1:
        //insertion sort case
        {
            t3 = clock();
            newWords.insertionSort();
            t4 = clock();
        }
        case 2:
        //quicksort case
        {
            t3 = clock();
            newWords.quickSort();
            t4 = clock();
        }

    } //end of switch statement based on sorting algorithm

    t5 = clock();
    FindMatches(newWords, newGrid);
    t6 = clock();

    t2 = clock();

    float totalTime = ((float)t2 - (float)t1) / CLOCKS_PER_SEC;
    float sortTime = ((float)t4 - (float)t3) / CLOCKS_PER_SEC;
    float findTime = ((float)t6 - (float)t5) / CLOCKS_PER_SEC;

    cout << "\nTotal time in seconds: " << totalTime << endl;
    cout << "Sorting time in seconds: " << sortTime << endl;
    cout << "finding time in seconds: " << findTime << endl;

} //end of search function

//------------------Test Functions--------------------------
void testGridLoadedCorrectly(Grid testGrid)
//prints grid, check to see if it looks right
{
    testGrid.printGrid();
}

void testWordListLoadedCorrectly(WordList testWordList)
//prints WordList, check to see if it looks right
{
    testWordList.printWordList();
}

void testWordsSorted(WordList testWordList)
//checks to make sure every word is greater than its predecesor
{
    bool pass = true;
    for (int i = 0; i < testWordList.getListSize()-1; i++){
        if (testWordList.getWord(i) > testWordList.getWord(i+1)){
            cout << "\nSort Algorithm Failed";
            pass = false;
        }
    }
    if (pass == true)
    {
        cout << "\nThe sorting algorithm worked correctly";
    }
}

void testLookUp(WordList testWordList)
//test the three casses for the lookUp Function
//1) returns -1 when no word found
//2) returns -2 when a partial match exists
//3) returns value greater than zero when match is found
{
    std::string testKey1 = "nothere";
    std::string testKey2 = "amazo";
    std::string testKey3 = "disestablishment";

    if (testWordList.lookUp(testKey1, testWordList.getListSize(), 0) == -1)
    //test for proper response to nonexistent word
    {
        cout << "\nlookUp function passed test 1";
    } else {
        cout << "\nlookUp function FAILED test 1";
    }

    if (testWordList.lookUp(testKey2, testWordList.getListSize(), 0) == -2)
    //test for proper response to partially found word
    {
        cout << "\nlookUp function passed test 2";
    } else {
        cout << "\nlookUp function FAILED test 2";
    }

    if (testWordList.lookUp(testKey3, testWordList.getListSize(), 0) >= 0)
    //test for proper response found word
    {
        cout << "\nlookUp function passed test 3";
    } else {
        cout << "\nlookUp function FAILED test 3";
    }

}


//------------------Main Function--------------------------

int main()
//main Function
{
    //TESTING

    //Test Grid Loaded
    Grid testGrid(250);
    testGridLoadedCorrectly(testGrid);

    //Test Words Loaded
    WordList newWords;
    newWords.loadWordList("wordlist.txt");
    testWordListLoadedCorrectly(newWords);

    //Test words sorted
    newWords.quickSort();
    testWordsSorted(newWords);

    //Test Look up Function
    testLookUp(newWords);




    int sortChoice = 1;
    cout << "\nHi! Which type of sort would you like to implement?\n";
    cout << "Your options are:";
    cout << "\n1) Insertion Sort";
    cout << "\n2) Quick Sort";
    cout << "\nIntegers only please!\n";
    cin >> sortChoice;
    Search(sortChoice);


} // end of main function
