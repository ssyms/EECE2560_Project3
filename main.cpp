// main.cpp
// Problem Set 3a                                 Chris Canal
// Team cansym                                    canal.c@husky.neu.edu
//                                                Sarada Symonds
//                                                symonds.s@husky.neu.edu
//
// Main program file for homework 3a.
#include "WordList.h"
#include "Grid.h"
#include "HashTable.h"
#include "heap.h"
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

//------------------Heap Functions---------------------------
template<typename T>
Heap<T>::Heap()
//default constructor
{

}

template<typename T>
void Heap<T>::loadHeap(std::string fileName)
//constructor that uploads from file
{
  ifstream heapFile;
  std::string line;
  heapFile.open(fileName);
  if (heapFile.is_open())
  //checks that file is open
  {
      while (getline(heapFile,line))
      //while there are new lines in the file
      {
          heapVector.push_back(line);
      }

      heapFile.close();
  } //end of if for open file

}

//returns the parent of the nth item in heap
template<typename T>
int Heap<T>::Parent(int n)
{
    int k = n / 2;

    return k;
}

//returns the left child of the nth item in heap
template<typename T>
int Heap<T>::Left(int n)
{
    int k = 2 * n;

    return k;
}

//returns the right child of the nth
template<typename T>
int Heap<T>::Right(int n)
{
  int k = (2 * n) + 1;

  return k;
}

//returns the nth item of heap
template<typename T>
T Heap<T>::GetItem(int n)
{
  return heapVector.at(n);
}

template<typename T>
int Heap<T>::getSize()
//size of heap
{
  return heapVector.size();
}

template<typename T>
void Heap<T>::InitializeMaxHeap()
//copies list to vector and calls build max heap
{

  maxHeap.push_back("");

  for(int i = 0; i < heapVector.size(); i++)
  //adds each item in heapvector to maxheap
  {
    maxHeap.push_back(heapVector.at(i));
  }

  BuildMaxHeap();

  for(int i = 1; i < maxHeap.size(); i++)
  //adds each item in maxheap to heapvector
  {
    heapVector.at(i - 1) = maxHeap.at(i);
  }

} //end of initialize max heap

template<typename T>
void Heap<T>::BuildMaxHeap()
//builds max heap
{
    int n = maxHeap.size();

    for(int i = n; i >= 1; i--)
    //iterates over max heapify
    {
        MaxHeapify(i, n);
    }

} //end of build max heap

template<typename T>
void Heap<T>::MaxHeapify(int i, int n)
//max heapify elper function
{
  int l, r, largest;
  T temp;
  largest = i;
  l = Left(i);
  r = Right(i);

  if((l < n) && (maxHeap.at(l) > maxHeap.at(largest)))
  //if left is larger than parent
  {
    largest = l;
  }

  if(r < n && maxHeap.at(r) > maxHeap.at(largest))
  //if right larger than current largest
  {
    largest = r;
  }

  if(largest != i)
  //does the swap, floats down
  {
    temp = maxHeap.at(i);
    maxHeap.at(i) = maxHeap.at(largest);
    maxHeap.at(largest) = temp;
    MaxHeapify(largest, n);
  }

} //end max heapify

template<typename T>
void Heap<T>::InitializeMinHeap()
//copies list to vector and calls build max heap
{

  minHeap.push_back("");

  for(int i = 0; i < heapVector.size(); i++)
  //adds each item in heapvector to maxheap
  {
    minHeap.push_back(heapVector.at(i));
  }

  BuildMinHeap();

  for(int i = 1; i < minHeap.size(); i++)
  //adds each item in maxheap to heapvector
  {
    heapVector.at(i - 1) = minHeap.at(i);
  }

} //end of initialize max heap

template<typename T>
void Heap<T>::BuildMinHeap()
//builds max heap
{
    int n = minHeap.size();

    for(int i = n; i >= 1; i--)
    //iterates over max heapify
    {
        MinHeapify(i);
    }

} //end of build max heap

template<typename T>
void Heap<T>::MinHeapify(int i)
//min heapify  function
{
  int l, r, smallest;
  T temp;
  smallest = i;
  l = Left(i);
  r = Right(i);

  if((l < minHeap.size()) && (minHeap.at(l) < minHeap.at(smallest)))
  //if left is larger than parent
  {
    smallest = l;
  }

  if(r < minHeap.size() && minHeap.at(r) < minHeap.at(smallest))
  //if right smaller than current smallest
  {
    smallest = r;
  }

  if(smallest != i)
  //does the swap, floats down
  {
    temp = minHeap.at(i);
    minHeap.at(i) = minHeap.at(smallest);
    minHeap.at(smallest) = temp;
    MinHeapify(smallest);
  }

} //end min heapify

template<typename T>
void Heap<T>::heapSortHelper()
//heap sort  function
{
  T temp;
  int n = maxHeap.size() - 1;
  for (int i = n; i >= 2; i--)
  {
      temp = maxHeap.at(i);
      maxHeap.at(i) = maxHeap.at(1);
      maxHeap.at(1) = temp;
      MaxHeapify(1, i - 1);
  }

  for(int i = 1; i < maxHeap.size(); i++)
  //adds each item in maxheap to heapvector
  {
    heapVector.at(i - 1) = maxHeap.at(i);
  }

}

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

std::string WordList::getWord(int i, std::string newWord)
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

void WordList::heapsort()
//heap sort
{
  Heap<std::string> myHeap;
  myHeap.loadHeap("wordtest.txt");
  myHeap.InitializeMaxHeap();
  myHeap.heapSortHelper();
  for(int i = 0; i < myHeap.getSize(); i++)
  //adds each item in maxheap to heapvector
  {
    wordListVector.at(i) = myHeap.GetItem(i);
  }

}

void maxHeapifyWordlist(int i, int n)
//heapifies the wordlist
{

}

//------------------Global Operators------------------------
std::ostream& operator << (std::ostream & ostr, WordList wordObj)
//overload << operator for WordList
{
  for(int i = 0; i < wordObj.wordListVector.size(); i++)
  //prints out each word in list
  {
    ostr << wordObj.getWord(i, "Null") << std::endl;
  }

  return ostr;
} //end of << overload


//------------------HashTable Functions--------------------------
template <typename T>
HashTable<T>::HashTable()
{
    hashTableTable.resize(475255);
}

template <typename T>
HashTable<T>::HashTable(std::string fileName)
{
    hashTableTable.resize(475255);

    ifstream wordListFile;
    std::string line;
    wordListFile.open(fileName);

    if (wordListFile.is_open())
    //checks that file is open
    {
        while (getline(wordListFile,line))
        //while there are new lines in the file
        {
            AddItem(line, Hash(line));
        }

        wordListFile.close();
    } //end of if for open file

} //end of load word list function

template <typename T>
void HashTable<T>::AddItem(T newItem, int location)
{
    hashTableTable[location].push_back(newItem);
}

template <typename T>
void HashTable<T>::DeleteItem(T itemThatIsDeadToMe)
{
    int location = Hash(itemThatIsDeadToMe);
    for (int i = 0 ; i < hashTableTable[location].size() ; i++){
        if (hashTableTable[location][i] == itemThatIsDeadToMe){
            hashTableTable[location].erase(hashTableTable[location].begin()+i);

            //Assumes there is only one copy of each item
            //Delete the next line if you want to Delete
            //all copies of an item
            i = hashTableTable[location].size();
        }
    }
}

template <typename T>
int HashTable<T>::lookUp(T lookUpItem, int unused, int unused2)
{
    int hashTableLocation = Hash(lookUpItem);
    int lookUpItemLocation = -1;
    for (int i = 0 ; i < hashTableTable[hashTableLocation].size() ; i++)
    {
        if (hashTableTable[hashTableLocation][i] == lookUpItem)
        //if you found the word
        {
            return i;
        }
        else
        //else keep looking
        {
            int j = 0;
            while ((hashTableTable[hashTableLocation][i][j] == lookUpItem[j]) && (j < lookUpItem.size()) )
            //while the word matches partially
            {
                if (j == (lookUpItem.size()-1))
                //return int to indicate partial match
                {
                    lookUpItemLocation = (-2);
                }

                j++;
            } //end of while loop
        }
    }
    return lookUpItemLocation;
}

template <typename T>
int HashTable<T>::InList(T lookUpItem, int unused, int unused2)
{
    int hashTableLocation = Hash(lookUpItem);
    int lookUpItemLocation = -1;
    for (int i = 0 ; i < hashTableTable[hashTableLocation].size() ; i++)
    {
        if (hashTableTable[hashTableLocation][i] == lookUpItem)
        //if you found the word
        {
            return i;
        }
        else
        //else keep looking
        {
            int j = 0;
            while (hashTableTable[hashTableLocation][i][j] == lookUpItem[j])
            //while the word matches partially
            {
                if (j == (hashTableTable[hashTableLocation][i].size()-1) || j == (lookUpItem.size()-1))
                //return int to indicate partial match
                {
                    lookUpItemLocation = -2;
                }

                j++;
            } //end of while loop
        }
    }
    return lookUpItemLocation;
}

template <typename T>
int HashTable<T>::Hash(T newItem)
//Simple hash function, uses the ascii number of the
//character to make the a number. Must subtract 96
//so that 'a' = 1 ... then we use each character to
//make a number the is base 26 where the first characters
//is the least significant bit.
{
    if(strchr(newItem.c_str(), char(39)))
    {
        return 0;
    }
    if(strchr(newItem.c_str(), char(46)))
    {
        return 0;
    }
    if(strchr(newItem.c_str(), char(45)))
    {
        return 0;
    }
    if (newItem.size() <= 1)
    //The word being hashed is one character long
    {
        return int(newItem[0])-96;
    } else if (newItem.size() == 2)
    //The word being hashed is two characters long
    {
        return (int(newItem[0])-96)+((int(newItem[1])-96)*26);
    } else if (newItem.size() == 3)
    //The word being hashed is three characters long
    {
        return (int(newItem[0])-96)+((int(newItem[1])-96)*26)+((int(newItem[2])-96)*676);
    } else
    //The word being hashed is longer than 3 characters
    {
        return (int(newItem[0])-96)+((int(newItem[1])-96)*26)+((int(newItem[2])-96)*676)+((int(newItem[3])-96)*17576);
    }
}

template <typename T>
void HashTable<T>::LoadWords(std::string fileName)
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
            AddItem(line, Hash(line));
        }

        wordListFile.close();
    } //end of if for open file

} //end of load word list function

template <typename T>
int HashTable<T>::getListSize(){
    return 1;
}

template <typename T>
std::string HashTable<T>::getWord(int i, std::string newWord)
//returns a word in the array at the given location
{
  return hashTableTable[Hash(newWord)][i];
}

//------------------Global Functions------------------------
bool isOnList(string s, vector<string> foundWords)
//checks if given word is on a list of words
{
      for  (int z = 0; z < foundWords.size(); z++)
      //checks if it is on the list
      {
          if (s == foundWords[z])
          //if it is on the list
          {
              z = foundWords.size();
              return true;
          }

      } //end of for loop to check if it's on the list

      return false;
}


template <typename T>
void FindMatches(T &listObj, Grid &gridObj)
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
                        if(!isOnList(listObj.getWord(loc, theKey), wordsFoundList))
                        //if word is not on the list of already found words
                        {
                          wordsFoundList.push_back(listObj.getWord(loc, theKey));
                          cout << "\nFound a new word ";
                          cout << listObj.getWord(loc, theKey);
                        }

                        loc = -2;
                    } //end of if you found a word

                } //end of while there is a partial match

                stringLength = 3; //resets min length to search new direction
                loc = -2;
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

    HashTable<std::string> newHashTable;
    Grid newGrid(fileNumber);
    WordList newWords;
    t1 = clock();
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
            break;
        }
        case 2:
        //quicksort case
        {
            t3 = clock();
            newWords.quickSort();
            t4 = clock();
            break;
        }
        case 3:
        //HashTable
        {
            t3 = clock();
            newHashTable.LoadWords("wordlist.txt");
            t4 = clock();
            break;
        }

    } //end of switch statement based on sorting algorithm

    t5 = clock();
    if (searchChoice > 2)
    {
        FindMatches(newHashTable, newGrid);
    } else {
        cout << "\nFindMatches";
        FindMatches(newWords, newGrid);
        cout << "\nFindMatchesDone";
    }

    t6 = clock();

    t2 = clock();

    float totalTime = ((float)t2 - (float)t1) / CLOCKS_PER_SEC;
    float sortTime = ((float)t4 - (float)t3) / CLOCKS_PER_SEC;
    float findTime = ((float)t6 - (float)t5) / CLOCKS_PER_SEC;

    cout << "\nTotal time in seconds: " << totalTime << endl;
    cout << "Sorting time in seconds: " << sortTime << endl;
    cout << "finding time in seconds: " << findTime << endl;

} //end of search function



//------------------Main Function--------------------------

int main()
//main Function
{
    int sortChoice = 1;
    /*int sortChoice = 1;
    cout << "\nHi! Which type of sort would you like to implement?\n";
    cout << "Your options are:";
    cout << "\n1) Insertion Sort";
    cout << "\n2) Quick Sort";
    cout << "\n3) Hash Table";
    cout << "\nIntegers only please!\n";
    cin >> sortChoice;
    Search(sortChoice);*/
    WordList words;
    words.loadWordList("wordtest.txt");
    words.heapsort();
    words.printWordList();

} // end of main function
