#include <iostream>
using namespace std;

int partition(int *arr, int start, int end)
{
    int pivot = arr[end];
    int index = start;

    for(int i=start ; i<end ; i++)
    {
        if(arr[i] <= pivot)
        {
            swap(arr[i], arr[index]);
            index++;
        }
    }
    swap(arr[index],arr[end]);
    return index;
}

void sortArray(int *arr, int start, int end)
{
    if(start < end)     //to manage unwanted segments or write it as (start>= end) then return
    {
        int index = partition(arr,start,end);
        sortArray(arr,start,index-1);
        sortArray(arr,index+1,end);
    }
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void printArray(int *arr, int size)
{
    for(int i=0 ; i<size ; i++)
    {
        cout << *arr << " ";
        *arr++;
    }
    cout << endl;
}

int main()
{
    int arr[8] = {7,2,1,6,8,5,3,4};

    printArray(arr,8);

    sortArray(arr,0,8);

    printArray(arr,8);
}