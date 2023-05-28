#include <iostream>
using namespace std;

struct Node
{
    int n;
    Node *next;
};

class LinkedList
{
public:
    Node *L;
    LinkedList()
    {
        L = NULL;
    }
    //---------------------------------------------//
    //---------------INSERTatSTART-----------------//
    //---------------------------------------------//
    void insertAtStart(int num)
    {

        Node *newNode = new Node;
        newNode->n = num;
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
        cout << "\n>>--Inserted at START--";
    }
    //---------------------------------------------//
    //--------------------PRINT--------------------//
    //---------------------------------------------//
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
    ////////////////////////////////////////////////////////////////////
    //----------------------------------------------------------------//
    ////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////
    ////////////////// SORT ///////////////////
    ///////////////////////////////////////////
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
            prev = current;          // L
            current = current->next; // 1
            nxt = current->next;     // 2
            if (prev->n > current->n)
            {
                if (prev == L)
                {
                    prev->next = nxt;     // L->next >> nxt
                    current->next = prev; // 1->next >> L
                    L = current;          // L = 1

                    current = L;
                }
                
            }
            // 2  7  4  3  45  5  90  6  10  8  1
            // 2  4  7  3  45  5  90  6  10  8  1
            else if (current->n > nxt->n)
            {
                temp = current->next;      // temp = nxt
                current->next = nxt->next; // current->next = current->next->next
                nxt->next = prev->next;    // nxt->next = current
                prev->next = temp;         // prev->next = nxt

                current = L;
            }
        }
        cout << "\n>>--List Sorted--";
    }
};

int main(int argc, char **argv)
{
    LinkedList list;

    list.insertAtStart(1);
    list.insertAtStart(8);
    list.insertAtStart(10);
    list.insertAtStart(6);
    list.insertAtStart(90);
    list.insertAtStart(5);
    list.insertAtStart(45);
    list.insertAtStart(3);
    list.insertAtStart(4);
    list.insertAtStart(7);
    list.insertAtStart(2);

    list.print();
    list.sort();
    list.print();
}