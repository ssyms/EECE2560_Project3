// WordList.h
// Problem Set 3a                                 Chris Canal
// Team cansym                                    canal.c@husky.neu.edu
//                                                Sarada Symonds
//                                                symonds.s@husky.neu.edu
//
// Wordlist header file for homework 3a.
// Contains declarations for wordlist class.
using namespace std;
#ifndef WordList_WordList_h
#define WordList_WordList_h

class WordList
//class declaration for the WordList class
{
  public:
    //default constructor
    WordList();

    //constructor that reads in a word list from a file
    WordList(string f);

    //returns the word in the list based on given int i
    string getWord(int i);

    //overload operator to print out wordlist
    friend ostream& operator << (ostream & ostr, WordList wordObj);

    //sorts word list using insertion sort
    void insertionSort();

    //sorts word list using merge sort
    void mergeSort();

    //sorts word list using quicksort
    void quickSort();

    //looks up whether a word is on the list and returns the location
    int lookUp(string word);

  private:
    //array to store words in
    string words[];

}; //end of WordList

#endif
