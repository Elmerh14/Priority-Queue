#include "priorityQueue.h"


PriorityQueue::PriorityQueue(int capacity) : array(capacity + 1), theSize(0) {}

bool PriorityQueue::isEmpty()
{
    return theSize == 0;
}

void PriorityQueue::insert(int value)
{
    if(theSize + 1 == array.size()) 
    {
        array.resize(array.size() * 2 + 1);
    }

    //Percolate up
    int hole = ++theSize;
    for(; hole > 1 && value < array[hole / 2]; hole /= 2)
    {
        array[hole] = array[hole / 2];
    }
    array[hole] = value;
}

void PriorityQueue::deleteMin()
{
    if(isEmpty())
    {
        throw underflow_error("Priority Queue is empty!");
    }
        array[1] = array[theSize--];
        percolateDown(1);
        
}

void PriorityQueue::percolateDown(int hole)
{
    int child;
    int temp = array[hole];

    for(; hole * 2 <= theSize; hole = child)
    {
        child = hole * 2;
        if(child != theSize && array[child + 1] < array[child])
            child++;

        if(array[child] < temp)
            array[hole] = array[child];

        else
            break;
    }
    array[hole] = temp;
}

void PriorityQueue::buildQueue()
{
    for(int i = theSize / 2; i > 0; --i)
    {
        percolateDown(i);
    }
}

void PriorityQueue::printQueue()
{
    cout << "[ ";
    for(int i = 1; i<= theSize; i++)
    { 
        cout << array[i];
        if(i < theSize)
        {
            cout << ", ";
        }     
    }
    cout << " ]" << endl;
}