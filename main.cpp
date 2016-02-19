// main.cpp
// Problem Set 3a                                 Chris Canal
// Team cansym                                    canal.c@husky.neu.edu
//                                                Sarada Symonds
//                                                symonds.s@husky.neu.edu
//
// Main program file for homework 3a.
#include "WordList.h"
#include <iostream>
#include <cstdlib>
#include <time.h>    //for making rand() more random
#include <vector>

//------------------Test Data----------------------

char gridArray[23][10];

char gridArray0[] = {'h','e','l','l','o','g','t','t','s','d'};
char gridArray1[] = {'y','r','r','a','h','o','s','e','s','s'};
char gridArray2[] = {'d','a','d','r','d','o','r','r','q','d'};
char gridArray3[] = {'s','d','e','e','a','d','s','e','w','d'};
char gridArray4[] = {'s','e','e','t','e','b','e','u','g','a'};
char gridArray5[] = {'s','s','s','t','s','y','s','s','p','g'};
char gridArray6[] = {'i','e','e','o','e','e','f','e','a','r'};
char gridArray7[] = {'i','b','s','p','e','r','a','e','s','a'};
char gridArray8[] = {'s','s','e','n','e','m','g','e','s','d'};
char gridArray9[] = {'s','b','e','t','o','e','u','e','s','g'};
char gridArray10[] = {'s','y','a','n','e','i','i','e','d','f'};
char gridArray11[] = {'h','w','k','l','d','e','l','e','d','g'};
char gridArray12[] = {'e','e','n','i','l','e','i','w','a','c'};
char gridArray13[] = {'y','u','v','u','d','e','i','e','t','s'};
char gridArray14[] = {'s','m','v','y','a','e','r','i','o','g'};
char gridArray15[] = {'s','n','b','u','s','e','w','m','g','g'};
char gridArray16[] = {'e','t','y','g','o','l','o','n','h','c'};
char gridArray17[] = {'d','e','r','p','d','e','r','h','a','r'};
char gridArray18[] = {'s','n','n','o','p','e','e','e','d','g'};
char gridArray19[] = {'s','n','n','i','o','e','g','d','a','g'};
char gridArray20[] = {'s','b','m','u','i','e','n','f','d','g'};
char gridArray21[] = {'s','v','m','y','u','a','o','a','d','g'};
char gridArray22[] = {'a','a','a','a','a','a','r','s','a','d'};

char gridArray = {gridArray0, gridArray1, gridArray2, gridArray3, gridArray4, gridArray5, gridArray6, gridArray7, gridArray8, gridArray9, gridArray10, gridArray11, gridArray12, gridArray13, gridArray14, gridArray15, gridArray16, gridArray17, gridArray18, gridArray19, gridArray20, gridArray21, gridArray22};

string wordListArray[] = {"hello","goodbye","harry","potter","water","monkey","baller","lions","witch","awesom","suprise","bigger","faster","stronger","harder","technology"};


//------------------WordList Functions----------------------

string getWord(int i)
//returns a word in the array at the given location
{
  return words[i];
}

void insertionSort()
//sorts the list using insertion sort
{

  for(int i = 1; i < words.size(); i++)
  //outer loop to go through each word
  {
    String key = words[i];
    int j = i - 1;

    while ((j > 0) && (words[j] > key)
    //while word is greater than the key
    {
      words[(j + 1)] = words[j]
      j = j - 1;
    }

    words[(j + 1)] = key;
  } //end of for loop for insertion sort

}

void mergeSort()
//merge sort function
{

}

//------------------Global Operators------------------------
ostream& operator << (ostream & ostr, WordList wordObj)
//overload << operator for WordList
{
  for(int i = 0; i < words.size(); i++)
  //prints out each word in list
  {
    ostr << wordObj.getWord(i) << endl;
  }
}

//------------------Main Function--------------------------



int main()
//main Function
{

} // end of main function
