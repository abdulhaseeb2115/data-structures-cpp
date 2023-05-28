//iterative aproach to implement selection sort in ascending order

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
    int i,j,min_index;
    for(i = 0 ; i<size-1 ; i++)
    {
        min_index = i;
        for(j = i+1 ; j<size ; j++)
        {
            if(arr[j] < arr[min_index])
            {
                min_index = j;
            }
            swap(&arr[min_index], &arr[i]);
        }
    }
}

void printArray(int *ptrArray, int size)
{
    for(int i=0 ; i<size ; i++)
    {
        cout << *ptrArray << " ";
        ptrArray++;
    }
    cout << endl;
}

int main()
{
    int arr[] = {34,12,56,10,11};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout << "Printing Array in Unsorted form : ";
    printArray(arr,size);

    sortArray(arr, size);

    cout << "Pinting Array in Sorted form : ";
    printArray(arr,size);

    return 0;
}