#include <iostream>
using namespace std;

struct Node
{
    int n;
    Node *next;
    Node *back;
};

class LinkedList
{
public:
    Node *L;
    Node *Z;
    LinkedList()
    {
        L = NULL;
    }
    //---------------INSERTatSTART-----------------//
    void insertAtStart(int num)
    {

        Node *newNode = new Node;
        newNode->n = num;
        newNode->next = NULL;
        newNode->back = NULL;

        if (L == NULL)
        {
            L = newNode;
            Z = newNode;
            Z->next = NULL;
        }
        else if (L != NULL)
        {
            L->back = newNode;
            newNode->next = L;
            L = newNode;
        }
        cout << "\n>>--Inserted at START--";
    }
    //--------------------PRINT--------------------//
    void print()
    {
        Node *current;
        current = L;
        cout << "\nPrinting-->";
        while (current != NULL)
        {
            cout << "  " << current->n;
            current = current->next;
        }
    }
    //------------------PRINTREV-------------------//
    void printRev()
    {
        Node *current;
        current = Z;
        cout << "\nPrinting-REVERSE-->";
        while (current != NULL)
        {
            cout << "  " << current->n;
            current = current->back;
        }
    }
    ////////////////////////////////////////////////////////////////////
    //----------------------------------------------------------------//
    ////////////////////////////////////////////////////////////////////
    void sort()
    {
        Node *current;
        Node *prev;
        Node *nxt;
        Node *temp;

        current = L;
        prev = L;
        nxt = L;
        while (nxt->next != NULL)
        {
            prev = current;          //L
            current = current->next; //1
            nxt = current->next;     //2
            if (prev->n > current->n)
            {
                if (prev == L)
                {
                    prev->back = current;
                    nxt->back = prev;
                    current->back = NULL;

                    prev->next = nxt;
                    current->next = prev;
                    L = current;

                    current = L;
                }
            }
            else if (current->n > nxt->n)
            {
                if (nxt == Z)
                {
                    nxt->back = prev;
                    current->back = nxt;

                    prev->next = nxt;
                    nxt->next = current;
                    current->next = NULL;
                    Z = current;

                    current=L;
                }
                else
                {
                    current->back = nxt;
                    nxt->back = prev;
                    nxt->next->back = current;

                    temp = current->next;
                    current->next = nxt->next;
                    nxt->next = prev->next;
                    prev->next = temp;

                    current = L;
                }
            }
        }
        cout << "\n\n>>--List Sorted----------------------------<<\n";
    }
    ////////////////////////////////////////////////////////////////////
    //----------------------------------------------------------------//
    ////////////////////////////////////////////////////////////////////
};
//---------  ----------MAIN--------- ---------//
int main(int argc, char **argv)
{
    LinkedList list;

    list.insertAtStart(1);
    list.insertAtStart(2);
    list.insertAtStart(3);
    list.insertAtStart(4);
    list.insertAtStart(5);
    list.insertAtStart(6);
    list.insertAtStart(7);
    list.insertAtStart(8);
    list.insertAtStart(9);
    list.insertAtStart(10);

    list.print();
    list.printRev();
    list.sort();
    list.print();
    list.printRev();
}