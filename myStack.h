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

    node *base;
    node *topNode;
    node *poppedNode;

public:
    //*-------- insert || delete methods
    void pop();
    void push(int data);
    void reversePop();
    //*--------- not insert or delete
    bool isEmpty();
    int top();
    int size();
    void display();
    void clean();

    stack() : base(nullptr), topNode(nullptr), poppedNode(nullptr) {}
    ~stack()
    {
        clean();
    }
};

// * - - - - - - - - - - - push and pop

void stack::push(int data)
{
    node *createdNode = new node(data);
    if (base == nullptr)
    {
        base = createdNode;
        topNode = createdNode;
        base->next = topNode;
        topNode->prev = base;
    }
    else
    {
        topNode->next = createdNode;
        createdNode->prev = topNode;
        topNode = createdNode;
    }
}

void stack::pop()
{
    // if there are no elements in the stack
    if (size() <= 0)
    {
        throw std::out_of_range("stack is empty");
    }

    // if there are more than 1 elemetns in the stack
    if (poppedNode == nullptr && size() > 1)
    {
        poppedNode = topNode;
        topNode = topNode->prev;
        topNode->next = nullptr;
    }
    // if there is only one element in the stack
    else if (size() == 1)
    {
        // TODO:: send a confirmation message "if proceede, all of stack will be deleted"

        if (poppedNode != nullptr)
        {
            poppedNode->prev = nullptr;
            delete poppedNode;
            poppedNode = nullptr;
        }
        delete base;
        base = nullptr;
    }
    // if there are multiple elements in the stack
    else
    {
        poppedNode->prev = nullptr;
        delete poppedNode;
        poppedNode = nullptr;

        poppedNode = topNode;
        topNode = topNode->prev;
        topNode->next = nullptr;
    }
}

void stack::reversePop()
{
    if (poppedNode == nullptr)
    {
        throw std::out_of_range("there is not a node to reverse");
    }
    topNode->next = poppedNode;
    topNode = topNode->next;
    poppedNode = nullptr;
}
// * - - - - - - - - - - other methods (not insertion or deletion)
