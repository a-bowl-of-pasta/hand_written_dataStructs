#ifndef M_L_L_H // my linked list header
#define M_L_L_H

#include <iostream>

class linkedList
{

    struct node
    {
        node *next;
        int mData;
        node *prev;
        node(int data) : next(nullptr), prev(nullptr), mData(data) {}
    };

    node *head;
    node *tail;
    int count;

public:
    //*  push  && pop methods
    void pushBack(int data);
    void pushFront(int data);
    void popBack();
    void popFront();
    void cleanUp();
    //* index methods
    void insert(int data, int i);
    void removeAt(int i);
    //* the rest of the methods
    int peekFront() { return head->mData; }
    int peekBack() { return tail->mData; }
    int getCount() { return count; }
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
    linkedList() : head(nullptr), tail(nullptr), count(0) {}
    ~linkedList()
    {
        if (isEmpty() != true)
        {
            cleanUp();
        }
    }
};

//* - - - - - - - - push and pops
// push methods
void linkedList::pushBack(int data)
{
    node *createdNode = new node(data);
    if (head == nullptr)
    {
        head = createdNode;
    }
    else
    {
        tail->next = createdNode;
        createdNode->prev = tail;
    }
    tail = createdNode;
    tail->next = head;
    head->prev = tail;
    count = count + 1;
}
void linkedList::pushFront(int data)
{
    node *createdNode = new node(data);
    if (head == 0)
    {
        tail = createdNode;
    }
    else
    {
        createdNode->next = head;
        head->prev = createdNode;
    }
    head = createdNode;
    head->prev = tail;
    tail->next = head;
    count = count + 1;
}
// pop methods
void linkedList::popBack()
{
    try
    {
        if (isEmpty() == true)
        {
            throw std::out_of_range("out of range big dog");
        }
        node *oldTail = tail;
        tail = oldTail->prev;
        tail->next = head;
        head->prev = tail;
        delete oldTail;
        count = count - 1;
    }
    catch (std::out_of_range &exe)
    {

        std::cout << exe.what();
    }
}
void linkedList::popFront()
{
    try
    {
        if (isEmpty() == true)
        {
            throw std::out_of_range("out of range big dog");
        }

        node *oldHead = head;
        head = oldHead->next;
        tail->next = head;
        head->prev = tail;
        delete oldHead;
        count = count - 1;
    }
    catch (std::out_of_range &exe)
    {
        std::cout << exe.what();
    }
}
//* - - - - - - - - - - - index of i methods
void linkedList::insert(int data, int i)
{
    try
    {
        if (i >= count || i < 0)
        {
            throw std::out_of_range("you're out of range big guy");
        }
        node *createdNode = new node(data);
        if (i == 0)
        {
            createdNode->next = head;
            head->prev = createdNode;
            head = createdNode;
            head->prev = tail;
            tail->next = head;
        }
        else if (i == count - 1)
        {
            node *beforeTail = tail->prev;
            beforeTail->next = createdNode;
            createdNode->prev = beforeTail;
            createdNode->next = tail;
            tail->prev = createdNode;
        }
        else
        {
            node *travel = head;
            for (int j = 0; j < i - 1; j++)
            {
                travel = travel->next;
            }
            createdNode->next = travel->next;
            travel->next = createdNode;
            createdNode->prev = travel;
            travel = createdNode->next;
            travel->prev = createdNode;
        }
        count = count + 1;
    }
    catch (std::out_of_range &exe)
    {
        std::cout << exe.what();
    }
}
void linkedList::removeAt(int i)
{
    try
    {
        if (i >= count || i < 0)
        {
            throw std::out_of_range("you're out of range big guy");
        }
        node *trash = nullptr;

        if (i == 0)
        {
            trash = head;
            head = head->next;
            delete trash;
            tail->next = head;
            head->prev = tail;
        }
        else if (i == count - 1)
        {
            trash = tail;
            tail = tail->prev;
            delete trash;
            tail->next = head;
            head->prev = tail;
        }
        else
        {
            trash = head;
            for (int j = 0; j < i - 1; j++)
            {
                trash = trash->next;
            }
            trash->prev->next = trash->next;
            trash->next->prev = trash->prev;
            delete trash;
        }
    }
    catch (std::out_of_range &exe)
    {
        std::cout << exe.what();
    }
}
//* - - - - - - - - - - - clean Up method
void linkedList::cleanUp()
{
    tail->next = nullptr;
    head->prev = nullptr;

    while (head != nullptr)
    {
        node *travel = head;
        head = head->next;
        delete travel;
        count = count - 1;
    }
    head = nullptr;
    tail = nullptr;
}
#endif