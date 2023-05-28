#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int n;
    Node *next;
};
class Queue
{
public:
    Node *L;
    int len;
    int count;
    //---------------------------------------//
    //-----------------QUEUE-----------------//
    //---------------------------------------//
    Queue()
    {
    }
    Queue(int n)
    {
        len = n;
        count = 0;
        L = NULL;
    }
    //---------------------------------------//
    //----------------IsEMPTY----------------//
    //---------------------------------------//

    bool isEmpty()
    {
        if (L == NULL && count == 0)
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
        if (count == len)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    //---------------------------------------//
    //----------------DISPLAY----------------//
    //---------------------------------------//

    void display()
    {
        cout << ">QUEUE->>";
        Node *current = L;
        while (current != NULL)
        {
            cout << " [" << current->n << "]";
            current = current->next;
        }
        cout << "\n============================\n";
    }

    //---------------------------------------//
    //----------------ENQUEUE----------------//
    //---------------------------------------//

    void enQueue(int num)
    {
        if (isEmpty())
        {
            Node *current = L;
            Node *newNode = new Node;
            newNode->n = num;
            newNode->next = NULL;
            L = newNode;
            cout << "-->ENQUEUED..!\n";
            count++;
        }
        ////////////////////////////////////
        else if (isFull())
        {
            cout << "--> Cannot be enQueued.\n";
        }
        ////////////////////////////////////
        else
        {
            Node *current = L;
            Node *newNode = new Node;
            newNode->n = num;
            newNode->next = NULL;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = newNode;
            cout << "-->ENQUEUED..!\n";
            count++;
        }
    }

    //---------------------------------------//
    //----------------DEQUEUE----------------//
    //---------------------------------------//

    int deQueue()
    {

        if (isEmpty())
        {
            cout << "--> Cannot be deQueued.\n ";
            return 0;
        }
        else
        {
            Node *current = L;
            int x = current->n;
            if (current != NULL)
            {
                L = L->next;
                delete current;
            }
            count--;
            cout << "--> DEQUEUED>> [";
            return x;
        }
    }
};
int main(int argc, char **argv)
{
    int size;
    int choice;
    cout << "\n============================\n";
    cout << " > 0: EXIT.\n";
    cout << " > 1: EnQUEUE\n";
    cout << " > 2: DeQUEUE.\n";
    cout << " > 3: DISPLAY.\n";
    cout << "============================\n";
    cout << ">>>> ENTER SIZE OF QUEUE: ";
    cin >> size;
    cout << "============================\n";
    Queue q(size);
    while (choice != 0)
    {
        cout << "-->> ENTER CHOICE: ";
        cin >> choice;
        cout << "============================\n";
        if (choice == 0)
        {
            cout << "--EXITTING--\n";
            cout << "============================\n";
        }
        else if (choice == 1)
        {
            int val;
            cout << "ENTER VALUE:";
            cin >> val;
            q.enQueue(val);
            cout << "============================\n";
        }
        else if (choice == 2)
        {
            cout << q.deQueue() << "]";
            cout << "\n============================\n";
        }
        else if (choice == 3)
        {
            q.display();
        }
        else
        {
            cout << "--YOU ENTERED WRONG CHOICE--\n--EXITTING--\n";
            choice = 0;
        }
    }
}