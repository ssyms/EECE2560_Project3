// Heap<T>.h
// Problem Set 3b                                 Chris Canal
// Team cansym                                    canal.c@husky.neu.edu
//                                                Sarada Symonds
//                                                symonds.s@husky.neu.edu
//
// Heap<T> header file for homework 3b.
// Contains declarations for Heap<T> class.

#ifndef HEAP_CLASS
#define HEAP_CLASS

template <typename T>
class Heap
//the heap class
{
    public:
      //default constructor
      Heap();

      //constructor that uploads from filexx
      Heap(std::string fileName);

      //returns the parent of the nth item in heap
      std::string Parent(int n);

      //returns the left child of the nth item in heap
      std::string Left(int n);

      //returns the right child of the nth
      std::string Right(int n);

      //returns the nth item of heap
      std::string GetItem(int n);

      //copies list to vector and calls build max heap
      void InitializeMaxHeap();

      //builds a max heap
      void BuildMaxHeap();

      //max heapifies the heapifies
      void MaxHeapify();

      //heap sort function
      void HeapSort();

    private:

      //vector that stores the heap
      std::vector<T> heapVector;
};
#endif
