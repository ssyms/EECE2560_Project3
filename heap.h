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
      void loadHeap(std::string fileName);

      //returns the parent of the nth item in heap
      int Parent(int n);

      //returns the left child of the nth item in heap
      int Left(int n);

      //returns the right child of the nth
      int Right(int n);

      //returns the nth item of heap
      T GetItem(int n);

      //adds item to heap
      void addItem(T t);

      //size of heapVector
      int getSize();

      //copies list to vector and calls build max heap
      void InitializeMaxHeap();

      //builds a max heap
      void BuildMaxHeap();

      //max heapifies the heapifies
      void MaxHeapify(int i, int n);

      //copies list to vector and calls build max heap
      void InitializeMinHeap();

      //builds a max heap
      void BuildMinHeap();

      //max heapifies the heapifies
      void MinHeapify(int i);

      //max heapifies the heapifies
      void heapSortHelper();

    private:

      //vector that stores the heap
      std::vector<T> heapVector;

      //vector that stores the heap
      std::vector<T> maxHeap;

      //vector that stores the heap
      std::vector<T> minHeap;
};
#endif
