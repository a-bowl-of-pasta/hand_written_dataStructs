#ifndef M_Q
#define M_Q

class myQeue
{
        struct node
        {
                node *next;
                node *prev;
                int data;
                node(int pData) : next(nullptr), prev(nullptr), data(pData) {}
        };
        node *head;
        node *tail;
        node *reversalHold;
        int count;

public:
        //* ------------ push and pop
        void enqeue(int data){};
        void deqeue(){};
        void clean();
        void reverseDeq();
        //* ----------- misc methods
        int peek() { return head->data; }
        int getSize() { return count; }
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
        void display(){};
        myQeue() : head(nullptr), tail(nullptr), reversalHold(nullptr), count(0) {}
        ~myQeue()
        {
                if (reversalHold != nullptr)
                {
                        delete reversalHold;
                        reversalHold = nullptr;
                }
                clean();
        }
};
//* - - - - - - - push and pops
// enqeue
void myQeue::enqeue(int data)
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
        count = count + 1;
}
// dequeu
void myQeue::deqeue()
{
        // TODO :: add an exception block for if deqeue when qeue is empty
        try
        {
                if (isEmpty() == true)
                {
                        throw std::out_of_range("there no nodes to deqeue");
                }

                if (reversalHold != nullptr)
                {
                        delete reversalHold;
                        reversalHold = nullptr;
                }
                reversalHold = head;
                head = head->next;
                head->prev = nullptr;
                count = count - 1;
        }
        catch (std::out_of_range &exe)
        {
                std::cout << exe.what();
        }
}
void myQeue::reverseDeq()
{
        try
        {
                if (reversalHold == nullptr)
                {
                        throw "there is nothing to reverse";
                }
                head->prev = reversalHold;
                reversalHold = nullptr;
        }
        catch (const char *exception)
        {
                std::cout << exception;
        }
}
void myQeue::clean()
{
        while (head != nullptr)
        {
                head = head->next;
                head->prev = tail;
                tail->next = head;
                delete (head->prev);
        }
        tail = nullptr;
        head = nullptr;
}

//* - - - - - - - misc methods
void myQeue::display()
{
        node *travel = head;
        while (travel != nullptr)
        {
                std::cout << travel->data << std::endl;
                travel = travel->next;
        }
}

#endif
