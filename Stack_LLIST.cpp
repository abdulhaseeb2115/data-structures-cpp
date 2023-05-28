#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int n;
    Node *next;
};
class Stack
{
private:
    int top;
    Node *L;
    bool empty;
    bool full;

public:
    //---------------------------------------//
    //-----------------STACK-----------------//
    //---------------------------------------//

    Stack()
    {
        top = -1;
        L = NULL;
        cout << "\n>>-------------------------------<<\n";
        cout << ">----------STACK CREATED----------<\n";
        cout << ">>-------------------------------<<\n\n";
    }

    //---------------------------------------//
    //--------------EMPTYorFULL--------------//
    //---------------------------------------//

    void EMPTYorFULL()
    {
        if (top == -1)
        {
            cout << ">>STACK_EMPTY<<\n";
        }
        else if (top == 9)
        {
            cout << ">>STACK_FULL<<\n";
        }
        else
        {
            cout << ">>STACK_HAS_" << top + 1 << "_ELEMENTS<<\n";
        }
    }

    //---------------------------------------//
    //----------------IsEMPTY----------------//
    //---------------------------------------//

    bool isEmpty()
    {
        if (L == NULL && top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    //---------------------------------------//
    //----------------IsFULL-----------------//
    //---------------------------------------//

    bool isFull()
    {
        if (top == 9)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    //---------------------------------------//
    //-----------------STATUS----------------//
    //---------------------------------------//

    void Status()
    {
        if (top == -1)
        {
            empty = true;
            full = false;
        }
        else if (top == 9)
        {
            empty = false;
            full = true;
        }
        else
        {
            empty = true;
            full = true;
        }
    }

    //---------------------------------------//
    //----------------DISPLAY----------------//
    //---------------------------------------//

    void display()
    {
        Node *current = L;
        cout << "\n------------------------------------\n STACK->>";
        while (current != NULL)
        {
            cout << " [" << current->n << "]";
            current = current->next;
        }
        cout << "\n------------------------------------\n";
    }

    //---------------------------------------//
    //-----------------PUSH------------------//
    //---------------------------------------//

    void push(int n)
    {
        Status();
        if (empty == true)
        {
            top++;
            Node *newNode = new Node;
            newNode->n = n;
            newNode->next = NULL;

            if (L == NULL)
            {
                L = newNode;
            }
            else if (L != NULL)
            {
                newNode->next = L;
                L = newNode;
            }
            cout << "-->[" << n << "] added to STACK..\n";
        }
        else
        {
            cout << "--> '" << n << "' cannot be added to STACK.\n";
        }
    }

    //---------------------------------------//
    //------------------POP------------------//
    //---------------------------------------//

    int pop()
    {
        Status();
        if (full == true)
        {
            int num;
            Node *current = L;
            if (current == NULL)
            {
                cout << "--> Cannot be popped out.\n";
            }
            else if (current != NULL)
            {
                num = current->n;
                L = L->next;
                delete current;
            }
            top--;
            cout << "-->POPPED..!";
            return num;
        }
        else
        {
            cout << "--> Cannot be popped out.\n";
            return 0;
        }
    }

    //---------------------------------------//
    //------------------PEEK-----------------//
    //---------------------------------------//

    int peek(int pos)
    {
        Status();
        Node *current = L;
        if (full == true)
        {
            for (int i = 0; i < pos - 1; i++)
            {
                current = current->next;
            }
            int num = current->n;
            cout << "--> PEEK>> [";
            return num;
        }
        else
        {
            cout << "--> Cannot be peeked at.\n";
            return 0;
        }
    }
};
int main(int argc, char **argv)
{
    Stack s;
    s.EMPTYorFULL();
    s.push(10);
    s.push(20);
    s.push(30);
    s.EMPTYorFULL();
    s.push(40);
    s.push(50);
    s.EMPTYorFULL();
    s.push(60);
    s.push(70);
    s.push(80);
    s.push(90);
    s.push(100);
    s.EMPTYorFULL();
    s.push(110);
    s.display();
    cout << s.peek(2) << "]\n";
    s.pop();
    s.display();

    return 0;
}
