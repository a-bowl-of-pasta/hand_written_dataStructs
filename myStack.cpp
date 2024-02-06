#include <iostream>
#include "linkedList.cpp"

class stack
{
    linkedList myData;
    ~stack()
    {
        myData.sweep();
    }

public:
    void pop() { myData.remove(-1); }
    void push(int data) { myData.append(data); }
    bool isEmpty();
    int top() { return myData.getTail(); }
    int size() { return myData.getNodeCount(); }
    void display() { myData.display(); }
};

bool stack::isEmpty()
{
    if (myData.getNodeCount() > 0)
    {
        return false;
    }
    else
    {
        return false;
    }
}