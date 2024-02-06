#include <iostream>

struct node
{
    int data;
    node *next;
    node *last;

    node(const int data)
    {
        this->data = data;
        next = NULL;
        last = NULL;
    }
};

//* - - - - - - - - - list class
class linkedList
{
    node *head;
    node *tail;
    int numOfNodes;

public:
    void append(const int data);
    void insert(const int data, const int index = 0);
    void sweep();
    void display();
    void remove(const int i = 0);
    void removeAtTail();
    int getNodeCount() { return numOfNodes; }
    int getHead() { return head->data; }
    int getTail() { return tail->data; }
    linkedList()
    {
        head = NULL;
        tail = NULL;
        numOfNodes = 0;
    }
};

// * - - - - - - - - - list methods
void linkedList::append(const int data)
{
    tail = new node(data);
    numOfNodes = numOfNodes + 1;
    if (head == NULL)
    {
        head = tail;
        head->last = head;
        head->next = head;
    }
    else
    {
        node *lastElm = head->last;
        tail->last = lastElm;
        lastElm->next = tail;
        tail->next = head;
        head->last = tail;
    }
}
//* - - - - - insert method
void linkedList::insert(const int data, int index)
{
    node *insertedNode = new node(data);
    numOfNodes = numOfNodes + 1;
    if (index == 0)
    {
        insertedNode->last = tail;
        insertedNode->next = head;
        tail->next = insertedNode;
        head->last = insertedNode;
        head = insertedNode;
    }
    else
    {
        node *currentNode = head;
        int nodeTracker = 0;
        while (nodeTracker != index - 1)
        {
            currentNode = currentNode->next;
            nodeTracker = nodeTracker + 1;
        }

        insertedNode->last = currentNode;
        insertedNode->next = currentNode->next;
        currentNode->next = insertedNode;
        currentNode = insertedNode->next;
        currentNode->last = insertedNode;
    }
}
//* - - - - - - de allocation method
void linkedList::sweep()
{
    node *currentNode = head;
    node *trash = nullptr;
    tail->next = NULL;

    while (currentNode->next != NULL)
    {
        trash = currentNode;
        currentNode = currentNode->next;

        trash->next = NULL;
        trash->last = NULL;
        delete trash;
        trash = nullptr;
        numOfNodes = numOfNodes - 1;
    }
    if (head != NULL)
    {
        delete head;
        head = NULL;
    }
}
//* - - - - - - - display method
void linkedList::display()
{

    node *index = head;
    int i = 1;

    while (index != tail)
    {
        std::cout << "the data for node" << i << " is :: \t" << index->data << std::endl;
        i = i + 1;
        index = index->next;
    }

    std::cout << "the data for last node is :: \t" << index->data << std::endl;
}
//* - - - - - - - the remove method

void linkedList::remove(int i)
{
    node *currentNode;
    node *trash = head;

    int nodeTracker = 0;
    // if there is a singular node
    if (numOfNodes == 1)
    {
        delete head;
        numOfNodes = numOfNodes - 1;
    }
    // if removal is happening at tail
    else
    {
        while (nodeTracker != i)
        {
            trash = trash->next;
            nodeTracker = nodeTracker + 1;
        }
        currentNode = trash->last;
        currentNode->next = trash->next;
        currentNode = currentNode->next;
        currentNode->last = trash->last;
        if (i == 0)
        {
            head = currentNode->last;
        }
        trash->last = nullptr;
        trash->next = nullptr;
        delete trash;
        trash = nullptr;
        numOfNodes = numOfNodes - 1;
    }
}
void linkedList::removeAtTail()
{
    node *trash;
    trash = tail;
    tail = tail->last;
    trash->next = NULL;
    trash->last = NULL;
    delete trash;
    trash = nullptr;
    head->last = tail;
    tail->next = head;
}
