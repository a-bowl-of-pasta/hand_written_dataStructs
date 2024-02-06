#include <iostream>

/*
        implimentations
append - inserts new element to end
insert - inserts at index i
sweep - cleans up memory
display - prints every element in list
*/
struct node
{
    int data;   // list data
    node *next; // ptr to next elm
    node *last; // ptr to previous elm

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
    node *head;     // first node
    node *tail;     // last node
    int numOfNodes; // keeps track of node num

public:
    void append(const int data);                      // adds new node to end
    void insert(const int data, const int index = 0); // inserts new node at index
    void sweep();                                     // deallocates memory starting at tail and ending at head
    void display();                                   // displays stuff
    void remove(const int i = 0);                     // removes at index i //* defaults i to 0  or default delete's head
    int getNodeCount() { return numOfNodes; }         // returns the number of nodes
    int getHead() { return head->data; }              // returns the data in head
    int getTail() { return tail->data; }              // returns the data in tail
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
    tail = new node(data);       // new node = new tail
    numOfNodes = numOfNodes + 1; // adds 1 to the node count
    if (head == NULL)            // if there is not a head, assign one
    {
        head = tail;
        head->last = head;
        head->next = head;
    }
    else
    {
        node *lastElm = head->last; // inserts between tail and head (head's ptr to last = old tail)
        tail->last = lastElm;       // new tail's ptr to last is assigned to old tail
        lastElm->next = tail;       // old tail's ptr to next is assigned to new tail
        tail->next = head;          // new tail's ptr to next = head
        head->last = tail;          // head's ptr to last is assigned to new tail
    }
}
//* - - - - - insert method
void linkedList::insert(const int data, int index)
{
    node *insertedNode = new node(data); // creates new node
    numOfNodes = numOfNodes + 1;         // adds to node total
    if (index == 0)                      // if insert at head, replace head
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

    node *index = head; // starts at head
    int i = 1;          // node num starts at 1

    while (index != tail)
    {
        std::cout << "the data for node" << i << " is :: \t" << index->data << std::endl;
        i = i + 1;           // incriments node num
        index = index->next; // new index is ptr to next node
    }

    std::cout << "the data for last node is :: \t" << index->data << std::endl;
}
//* - - - - - - - the remove method

void linkedList::remove(int i)
{
    node *currentNode;
    node *trash = head;

    int nodeTracker = 0;
    if (numOfNodes == 1)
    {
        delete head;
        numOfNodes = numOfNodes - 1;
    }
    else if (i == -1)
    {
        trash = tail;
        tail = tail->last;
        trash->next = NULL;
        trash->last = NULL;
        delete trash;
        trash = nullptr;
        head->last = tail;
        tail->next = head;
    }
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
