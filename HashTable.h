// HashTable.h
// Problem Set 3a                                 Chris Canal
// Team cansym                                    canal.c@husky.neu.edu
//                                                Sarada Symonds
//                                                symonds.s@husky.neu.edu
//
// Wordlist header file for homework 3b.
// Contains declarations for wordlist class.

#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <fstream>

#ifndef HashTable_HashTable_h
#define HashTable_HashTable_h

template <typename T>
class HashTable
//class declaration for the HashTable class
{
  public:
    //default constructor
    HashTable();

    HashTable(std::string fileName);

    void LoadWords(std::string fileName);

    void AddItem(T newItem, int location);

    void DeleteItem(T itemThatIsDeadToMe);

    int lookUp(T lookUpItem, int unused, int unused2);

    int InList(T lookUpItem, int unused, int unused2);

    int Hash(T newItem);

    int getListSize();

    std::string getWord(int i, std::string newWord);

  private:
    //vector to store words in
    std::vector < std::vector < T > > hashTableTable;

}; //end of WordList

#endif
