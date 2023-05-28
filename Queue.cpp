#include <iostream>
#include <string>
using namespace std;

class Queue
{
private:
    int front;
    int rear;
    int arr[10];
    bool empty;
    bool full;
    
public:
    //---------------------------------------//
    //-----------------QUEUE-----------------//
    //---------------------------------------//
    Queue()
    {
        front = -1;
        rear = -1;
        for (int i = 0; i < 10; i++)
        {
            arr[i] = 0;
        }
        cout << "\n>>-------------------------------<<\n";
        cout << ">----------QUEUE CREATED----------<\n";
        cout << ">>-------------------------------<<\n\n";
    }
    //---------------------------------------//
    //--------------EMPTYorFULL--------------//
    //---------------------------------------//

    void EMPTYorFULL()
    {
        if (front == -1 && rear == -1)
        {
            cout << ">>QUEUE_EMPTY<<\n";
        }
        else if (rear == 9)
        {
            cout << ">>QUEUE_FULL<<\n";
        }
        else
        {
            cout << ">>QUEUE_HAS_" << rear - 1 << "_ELEMENTS<<\n";
        }
    }

    //---------------------------------------//
    //-----------------STATUS----------------//
    //---------------------------------------//

    void Status()
    {
        if (front == -1 && rear == -1)
        {
            empty = true;
            full = false;
        }
        else if (rear == 9)
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
        cout << "\n------------------------------------\n QUEUE->>";
        for (int i = 0; i <= 9; i++)
        {
            cout << " [" << arr[i] << "]";
        }
        cout << "\n------------------------------------\n";
    }

    //---------------------------------------//
    //----------------ENQUEUE----------------//
    //---------------------------------------//

    void enQueue(int n)
    {
        Status();
        if (empty == true && full == false)
        {
            front++;
            rear++;
            arr[rear] = n;
            cout << "-->ENQUEUED..!\n";
        }
        else if (empty == true && full == true)
        {
            rear++;
            arr[rear] = n;
        }
        else
        {
            cout << "--> Cannot be enQueued.\n";
        }
    }

    //---------------------------------------//
    //----------------DEQUEUE----------------//
    //---------------------------------------//

    int deQueue()
    {
        Status();
        if (empty == true && full == false)
        {
            cout << "--> Cannot be deQueued.\n";
            return 0;
        }
        else if (front == rear)
        {
          int x=arr[front];
          arr[front]=0;
          front=-1;
          rear=-1;
          cout << "--> DEQUEUED>> ";
          return x;
        }
        else
        {
          int x=arr[front];
          arr[front]=0;
          front++;
          cout << "--> DEQUEUED>> [";
          return x;
        }
    }
};

int main(int argc, char **argv)
{
    Queue q;
    q.EMPTYorFULL();
    q.enQueue(2);
    q.enQueue(12);
    q.enQueue(22);
    q.EMPTYorFULL();
    cout<<q.deQueue()<<"]\n";
    q.EMPTYorFULL();
    q.display();


}