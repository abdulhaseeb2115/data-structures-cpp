#include <iostream>
using namespace std;

void sortArray(int arr[], int size)
{
    int i,j,value;

    for(i = 1 ; i<size ; i++)
    {
        value = arr[i];
        j = i-1;
        while(j>=0 && arr[j] > value)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = value;
    }
}

void printArray(int *ptrArray, int size)
{
    for(int i=0 ; i<size ; i++)
    {
        cout << *ptrArray << " ";
        *ptrArray++;
    }
    cout << endl;
}

int main()
{
    int arr[] = {32,14,10,11,28};
    int size  = sizeof(arr)/sizeof(arr[0]);

    cout << "Printing Array in Un-Sorted form : ";
    printArray(arr,size);

    sortArray(arr,size);

    cout << "Printing Array in Sorted form : ";
    printArray(arr,size);

    return 0;
}