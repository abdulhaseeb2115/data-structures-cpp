#include <iostream>
using namespace std;

struct Node
{
    int n;
    Node *next;
};

class LinkList
{
public:
    Node *L;

    LinkList()
    {
        L = NULL;
    };
    //----------------PRINT----------------//
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
    //----------------INSERTatFRONT----------------//
    void insertAtFront(int num)
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
    //----------------INSERTbeforePOSITION----------------//
    void insertBeforePosition(int pos, int num)
    {
        Node *current = L;
        Node *prev = new Node;

        Node *newNode = new Node;
        newNode->n = num;
        newNode->next = NULL;

        for (int i = 1; i < pos; i++)
        {
            prev = current;
            current = current->next;
        }
        prev->next = newNode;
        newNode->next = current;
        cout << "\n>>--Node INSERTED--";
    }
    //----------------INSERTafterPOSITION----------------//
    void insertAfterPosition(int pos, int num)
    {
        Node *current = L;

        Node *newNode = new Node;
        newNode->n = num;
        newNode->next = NULL;

        for (int i = 1; i < pos; i++)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        cout << "\n>>--Node INSERTED--";
    }
    //----------------DELETEfromPOSITION----------------//
    void deletePosition(int pos)
    {
        Node *current = L;
        Node *prev;

        if (L == NULL)
        {
            cout << "\n>>--Node DELETED--";
        }
        else
        {
            int i = 1;
            current = L;
            while (i < pos)
            {
                prev = current;
                current = current->next;
                i++;
            }
            prev->next = current->next;
            delete current;
        }
        cout << "\n>>--Node DELETED--";
    }
    //----------------DELETEfullLIST----------------//
    void deleteFullList()
    {
        Node *current = L;
        Node *temp;
        while (L != NULL)
        {
            temp = L;
            L = L->next;
            delete temp;
        }
        cout << "\n>>--FULL LIST DELETED--";
    }
    //----------------DELETEevenVALUE--------------//
    void deleteEvenValues()
    {
        Node *prev = L;
        Node *current = L;
        while (current != L)
        {
            prev = current;
            current = current->next;
            if (current->n % 2 == 0)
            {
                prev->next = current->next;
            }
        }
        cout << "\n>>--Even Values DELETED--";
    }
    //----------------DELETEoddVALUE--------------//
    void deleteOddValues()
    {
        Node *prev = L;
        Node *current = L;
        while (current != L)
        {
            prev = current;
            current = current->next;
            if (current->n % 2 != 0)
            {
                prev->next = current->next;
            }
        }
    cout << "\n>>--Odd Values DELETED--";
    }
};
//---------  ----------MAIN--------- ---------//
int main(int argc, char **argv)
{
    LinkList list;

    list.insertAtFront(1);
    list.insertAtFront(2);
    list.insertAtFront(3);
    list.insertAtFront(4);
    list.insertAtFront(5);
    list.insertAtFront(6);
    list.insertAtFront(7);
    list.insertAtFront(8);
    list.insertAtFront(9);
    list.insertAtFront(10);
    cout << "\n----------------------------------------------------";
    cout << "\n----------------------------------------------------";
    list.print();
    cout << "\n----------------------------------------------------";
    list.insertAfterPosition(2, 60);
    list.print();
    list.insertBeforePosition(2, 99);
    list.print();
    cout << "\n----------------------------------------------------";
    list.deletePosition(3);
    list.print();
    cout << "\n----------------------------------------------------";
    list.deleteOddValues();
    list.print();
    cout << "\n----------------------------------------------------";
    list.deleteEvenValues();
    list.print();
    cout << "\n----------------------------------------------------";
    list.deleteFullList();
    list.print();
    cout << "\n----------------------------------------------------";
}
