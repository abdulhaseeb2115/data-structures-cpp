#include <iostream>

using namespace std;

class MaxHeap
{
    int *heap;
    int h_size;
    int h_cap;

public:
    MaxHeap(int cap)
    {
        heap = new int[cap]; //Set array size using max size of heap
        h_size = 0;          //Start array index
        h_cap = cap;
    }

    void insert(int element)
    {
        if (h_size == h_cap)
        {
            cout << "\n\tHeap overflow: Cannot insert an element..!\n";
            return;
        }
        else
        {
            heap[h_size] = element;
            int index = h_size;
            h_size++;

            while (index != 0 && heap[(index - 1) / 2] < heap[index])
            {
                int temp = heap[(index - 1) / 2];
                heap[(index - 1) / 2] = heap[index]; //swap greater child with parent
                heap[index] = temp;

                index = (index - 1) / 2; // iterate till root while cheking for smaller parent
            }
        }
    }

    void RestoreMaxHeap(int i)
    {
        int left = lChild(i);
        int right = rChild(i);
        if (left >= 0 && right >= 0)
        {
            if (heap[left] > heap[right])
            {
                left = right;
            }
        }
        if (left > 0)
        {
            int temp = heap[i];
            heap[i] = heap[left];
            heap[left] = temp;
            RestoreMaxHeap(left);
        }
    }
    ///////////UTILITY FUNCTIONS///////////
    int rChild(int i)
    {
        int right = (2 * i) + 2;
        if (right >= h_size)
            return -1;
        return right;
    }
    int lChild(int i)
    {
        int left = (2 * i) + 1;
        if (left >= h_size)
            return -1;
        return left;
    }
    /////////////////////////////////////
    void Del_Ele()
    {
        if (h_size <= 0)
        {
            cout << "\n\t Heap is Empty..!" << endl;
        }
        else if (h_size == 1)
        {
            h_size--;
            heap[h_size] = NULL;
        }
        else
        {
            int temp = heap[0];
            heap[0] = heap[h_size - 1]; //Replace last element with root element
            h_size--;

            cout << "\n\tHeap after deletion looks like this..! \n ";
            print();

            cout << "\n\tYour task is to implement \"RestoreMaxHeap\" function. \n"
                 << endl;

            RestoreMaxHeap(0);
        }
    }

    void print()
    {
        cout << "\n\t";
        for (int i = 0; i < h_size; i++)
        {
            cout << heap[i] << "  ";
        }
        cout << "\n\t";
    }
};

int main()
{

    int cap, num;
    cout << "\n\tEnter total capacity of the heap : ";
    cin >> cap;

    MaxHeap mh(cap);

    cout << "\n\t -: Insert Elements into Heap :- " << endl;
    for (int i = 1; i <= cap; i++)
    {
        cout << "\tEnter element " << i << " : ";
        cin >> num;
        mh.insert(num);
    }

    mh.print();

    mh.Del_Ele();

    system("PAUSE");
}