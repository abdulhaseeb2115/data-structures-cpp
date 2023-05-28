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
    //-----------------PUSH------------------//
    //---------------------------------------//

    void push(string expression)
    {

        Node *newNode = new Node;
        newNode->n = expression;
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
    //--------------PUSH_BRACES--------------//
    //---------------------------------------//
    void pushBraces(string s)
    {
        for (int i = 0; i < s.length(); i++)
        {
            string str = s.substr(i, 1);
            push(str);
        }
        checkBraces();
    }
    //---------------------------------------//
    //--------------CHECK_BRACES-------------//
    //---------------------------------------//

    void checkBraces()
    {
        int opening1 = 0;
        int closing1 = 0;

        int opening2 = 0;
        int closing2 = 0;

        int closing3 = 0;
        int opening3 = 0;

        Node *current = L;
        while (current != NULL)
        {
            ///////////////////////////////////
            if (current->n == "(")
            {
                opening1++;
            }
            else if (current->n == ")")
            {
                closing1++;
            }
            ///////////////////////////////////
            else if (current->n == "[")
            {
                opening2++;
            }
            else if (current->n == "]")
            {
                closing2++;
            }
            ///////////////////////////////////
            else if (current->n == "{")
            {
                opening3++;
            }
            else if (current->n == "}")
            {
                closing3++;
            }
            ///////////////////////////////////
            current = current->next;
        }
        if ((opening1 + closing1 + opening2 + closing2 + opening3 + closing3) == 0)
        {
            cout << "--> No BRACKETS..!";
            cout << "\n===========================\n";
        }
        else if (opening1 == closing1 && opening2 == closing2 && opening3 == closing3)
        {
            cout << "--> Brackets are BALANCED..!";
            cout << "\n===========================\n";
        }
        else
        {
            cout << "--> Brackets are not BALANCED..!";
            cout << "\n===========================\n";
        }
    }

    //--/////////////////////////////////////--//
    /////////////////////END/////////////////////
    //--////////////////////////////////////--//
};
int main(int argc, char **argv)
{
    Stack s;
    string expression;
    cout << "\n===========================\n";
    cout << "--> ENTER EXPRESSION: ";
    cin >> expression;
    s.pushBraces(expression);
    return 0;
}