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
        Z = NULL;
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
    //----------------INSERTatEnd------------------//
    void insertAtEnd(int num)
    {
        Node *newNode = new Node;
        newNode->n = num;
        newNode->next = NULL;

        if (L == NULL)
        {
            L = newNode;
            Z = newNode;
            Z->next = NULL;
        }
        else if (L != NULL)
        {
            Z->next = newNode;
            newNode->back = Z;
            Z = newNode;
        }

        cout << "\n>>--Inserted at END--";
    }
    //--------------INSERTatPosition---------------//
    void insertAtPosition(int num, int pos)
    {
        Node *newNode = new Node;
        newNode->n = num;
        newNode->next = NULL;

        if (L == NULL)
        {
            L = newNode;
            Z = newNode;
            newNode->back = NULL;
        }
        else
        {
            Node *nxt = L;
            Node *prev = L;
            for (int i = 1; i < pos; i++)
            {
                prev = nxt;
                nxt = nxt->next;
            }
            prev->next = newNode;
            newNode->next = nxt;
            newNode->back = prev;
            nxt->back = newNode;

            cout << "\n>>--Inserted at POSITION--";
        }
    }
    //----------------REVERSEtheLIST----------------//
    void reverseList()
    {
        Node *prev = NULL;
        Node *nxt = L;
        Node *current = L;

        while (current != NULL)
        {
            nxt = current->next;
            current->next = prev;
            prev = current;
            current = nxt;
        }
        L = prev;
        cout << "\n>>--List REVERSED--";
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
    //------------------DELETEfirstNODE-------------------//
    void deleteFirstNode()
    {
        if (L == NULL)
        {
            cout << "\n>>  List Empty...!";
        }
        else
        {
            Node *temp = L;
            L = L->next;
            L->back = NULL;
            delete temp;
        }
        cout << "\n>>--First Node DELETED--";
    }
    //------------------DELETElastNODE-------------------//
    void deletelastNode()
    {
        if (L == NULL)
        {
            cout << "\n>>  List Empty...!";
        }
        else
        {
            Node *temp = Z;
            Z = Z->back;
            Z->next = NULL;
            delete temp;
        }
        cout << "\n>>--Last Node DELETED--";
    }
    //------------------DELETENODE-------------------//
    void deleteNode(int pos)
    {
        Node *nxt;
        Node *current = L;
        Node *prev = L;
        for (int i = 1; i < pos; i++)
        {
            prev = current;
            current = current->next;
        }
        nxt = current->next;
        prev->next = nxt;
        nxt->back = prev;
        delete current;

        cout << "\n>>--Deleted NODE--";
    }
    //----------------DELETEfullLIST-----------------//
    void deleteFullList()
    {
        Node *temp;
        while (L != NULL)
        {
            temp = L;
            L = L->next;
            delete temp;
        }
        cout << "\n>>--Deleted FULL LIST--";
    }
    //----------------SWAPtwoNODES-----------------//
    void swapNodes(int num1, int num2)
    {
        Node *prev1;
        Node *current1 = L;
        Node *prev2;
        Node *current2 = L;
        while (current1->n != num1)
        {
            prev1 = current1;
            current1 = current1->next;
        }
        while (current2->n != num2)
        {
            prev2 = current2;
            current2 = current2->next;
        }
        Node *temp = current1->next;
        current1->next = current2->next;
        current2->next = temp;

        prev1->next = current2;
        prev2->next = current1;

        current1->back = prev2;
        current2->back = prev1;
        cout << "\n>>--Nodes SWAPPED--";
    }
};
//---------  ----------MAIN--------- ---------//
int main(int argc, char **argv)
{
    LinkedList list;
    cout << "\n----------------------------------------------------";
    cout << "\n----------------------------------------------------";
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
    cout << "\n----------------------------------------------------";
    cout << "\n----------------------------------------------------";
    list.print();
    list.printRev();
    cout << "\n----------------------------------------------------";
    list.insertAtEnd(1000);
    list.print();
    list.insertAtEnd(2000);
    list.print();
    list.insertAtPosition(20, 2);
    list.print();
    cout << "\n----------------------------------------------------";
    list.swapNodes(9, 1);
    list.print();
    cout << "\n----------------------------------------------------";
    list.deleteFirstNode();
    list.print();
    list.deletelastNode();
    list.print();
    list.deleteNode(2);
    list.print();
    cout << "\n----------------------------------------------------";
    list.reverseList();
    list.print();
    cout << "\n----------------------------------------------------";
    list.deleteFullList();
    list.print();
    cout << "\n----------------------------------------------------";
}