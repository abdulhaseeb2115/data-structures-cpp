//Optimized solution for bubble sort
//Big O of program-1 is n^2
//if there is no swapping at first iteration, it means that array is already sorted

#include <iostream>
using namespace std;

void swap(int *ptr1, int *ptr2)
{
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

void sortArray(int arr[], int size)
{
    int i,j;
    bool swapped = false;
    for(i=0 ; i<size-1 ; i++)
    {
        for(j=0 ; j<size-i-1 ; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped)
        {
            break;
        }
    }
}

void printArray(int arr[], int size)
{
    for(int i=0 ; i<size ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);

    printArray(arr,size);

    sortArray(arr,size);

    printArray(arr,size);
}