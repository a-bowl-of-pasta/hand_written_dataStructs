#include "linkedList.cpp"

/*
        implimentations ::
enqeue - removes first element
deqeue - adds element to end
peek - checks what value is at index 0 without popping it
size - checks size of qeue
isEmpty - checks if empty
*/
class myQeue
{
        linkedList theData;
        ~myQeue()
        {
                theData.sweep();
        }

public:
        void enqeue(int data) { theData.append(data); }
        void deqeue() { theData.remove(); }
        int peek() { return theData.getHead(); }
        int getSize() { return theData.getNodeCount(); }
        bool isEmpty();
        void display() { theData.display(); }
};

bool myQeue::isEmpty()
{
        if (theData.getNodeCount() > 0)
        {
                return false;
        }
        else
        {
                return true;
        }
}
