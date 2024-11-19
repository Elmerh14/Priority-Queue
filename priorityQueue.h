#ifndef priorityQueue
#define priorityQueue
#include <iostream>
#include <vector>

using namespace std;

class PriorityQueue
{
private:
  vector<int>array;
  int theSize;
  void percolateDown(int hole);
  void buildQueue();

public:
  PriorityQueue(int capacity = 100);
  bool isEmpty();
  void insert(int value);
  void deleteMin();
  void printQueue();

};

#endif