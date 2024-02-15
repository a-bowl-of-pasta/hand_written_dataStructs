#ifndef M_S_H
#define M_S_H

#include <iostream>

class stack
{
    struct node
    {
        node *next;
        node *prev;
        int data;
        node(int pData) : data(pData), next(nullptr), prev(nullptr) {}
    };

    node *top;
    node *poppedNode;
    int count;

public:
    //*-------- insert || delete methods
    void pop();
    void push(int data);
    void reversePop();
    //*--------- not insert or delete
    int peekTop() { return top->data; }
    int size() { return count; }
    void display();
    void clean();
    bool isEmpty()
    {
        if (count == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    stack() : top(nullptr), poppedNode(nullptr), count(0) {}
    ~stack()
    {
        if (poppedNode != nullptr) // clears the remaining data in poppedNode, aka can no longer reverse
        {
            delete poppedNode;
            poppedNode = nullptr;
        }
        clean();
    }
};

// * - - - - - - - - - - - push and pop

void stack::push(int data)
{
    node *createdNode = new node(data);
    if (top == nullptr) // first elm of stack
    {
        top = createdNode;
        top->prev = nullptr;
    }
    else // the next elms of stack
    {
        top->next = createdNode;
        createdNode->prev = top;
        top = createdNode;
    }
    count = count + 1;
}

void stack::pop()
{
    try
    {
        if (size() <= 0) // no elms in stack
        {
            throw std::out_of_range("stack is empty");
        }
        if (poppedNode != nullptr) // saved in case reversal is called
        {
            delete poppedNode;
            poppedNode = nullptr;
        }
        if (size() > 1) // more than 1 elm in stack
        {
            poppedNode = top;
            top = top->prev;
            top->next = nullptr;
        }
        else if (size() == 1) // only 1 elm in stack
        {
            poppedNode = top;
            delete top;
            top = nullptr;
        }
        count = count - 1;
    }
    catch (std::out_of_range &exe)
    {
        std::cout << exe.what();
    }
}
void stack::reversePop()
{
    try
    {
        if (poppedNode == nullptr) // if there is not a node to reverse
        {
            throw std::out_of_range("there is not a node to reverse");
        }
        top->next = poppedNode;
        top = top->next;
        poppedNode = nullptr;
        count = count + 1;
    }
    catch (std::out_of_range &exe)
    {
        std::cout << exe.what();
    }
}
// * - - - - - - - - - - other methods (not insertion or deletion)
void stack::display()
{
    node *travel = top;
    while (travel->prev != nullptr)
    {
        std::cout << travel->data << std::endl;
        travel = travel->prev;
    }
}
void stack::clean()
{
    while (top != nullptr)
    {
        node *travel = top;
        top = travel->prev;
        delete travel;
    }
}
#endif