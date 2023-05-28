#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string n;
    Node *next;
};
class Stack
{
public:
    Node *L;
    //---------------------------------------//
    //-----------------STACK-----------------//
    //---------------------------------------//

    Stack()
    {
        L = NULL;
    }

    //---------------------------------------//
    //----------------IsEMPTY----------------//
    //---------------------------------------//

    bool isEmpty()
    {
        if (L == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    //---------------------------------------//
    //-----------------PUSH------------------//
    //---------------------------------------//

    void push(string opretor)
    {
        Node *newNode = new Node;
        newNode->n = opretor;
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
    }

    //---------------------------------------//
    //------------------POP------------------//
    //---------------------------------------//

    void pop()
    {
        Node *current = L;
        if (current != NULL)
        {
            L = L->next;
            delete current;
        }
    }

    //---------------------------------------//
    //------------------TOP------------------//
    //---------------------------------------//

    string top()
    {
        Node *current = L;
        string val = current->n;
        return val;
    }

    //---------------------------------------//
    //---------------PRECEDENCE--------------//
    //---------------------------------------//

    int precedence(string x)
    {
        if (x == "^")
        {
            return 10;
        }
        else if (x == "/" || x == "*")
        {
            return 9;
        }
        else if (x == "+" || x == "-")
        {
            return 8;
        }
        else
        {
            return 0;
        }
    }

    //---------------------------------------//
    //-------------INFIXtoPOSTFIX------------//
    //---------------------------------------//

    void infixToPost(string s)
    {
        string strout = "";
        for (int i = 0; i < s.length(); i++)
        {
            if ((s.substr(i, 1) >= "a" && s.substr(i, 1) <= "z") || (s.substr(i, 1) >= "A" && s.substr(i, 1) <= "Z") 
                                                                 || (s.substr(i, 1) >= "0" && s.substr(i, 1) <= "9") )
            {
                strout = strout + s.substr(i, 1);
            }
            else if (s.substr(i, 1) == "+" || s.substr(i, 1) == "-" || s.substr(i, 1) == "*" || s.substr(i, 1) == "/" || s.substr(i, 1) == "^")
            {
                /////////////////////////////////////////////////////
                if (isEmpty())
                {
                    push(s.substr(i, 1));
                }
                /////////////////////////////////////////////////////
                else if (precedence(s.substr(i, 1)) > precedence(top()))
                {
                    push(s.substr(i, 1));
                }
                /////////////////////////////////////////////////////
                else if (precedence(s.substr(i, 1)) <= precedence(top()))
                {
                    while (!isEmpty() && precedence(s.substr(i, 1)) <= precedence(top()))
                    {
                        strout = strout + top();
                        pop();
                    }
                    push(s.substr(i, 1));
                }
                /////////////////////////////////////////////////////
            }
        }

        while (!isEmpty())
        {
            strout = strout + top();
            pop();
        }
        cout << "---------------------------\n";
        cout << "--> INFIX>>>> [" << s << "]\n--> POSTFIX>> [" << strout << "]";
        cout << "\n===========================\n";
    }

    //--/////////////////////////////////////--//
    /////////////////////END/////////////////////
    //--////////////////////////////////////--//
};
int main(int argc, char **argv)
{
    Stack s;
    string infix;
    cout << "\n===========================\n";
    cout << "--> ENTER INFIX: ";
    cin >> infix;
    s.infixToPost(infix);
    return 0;
}