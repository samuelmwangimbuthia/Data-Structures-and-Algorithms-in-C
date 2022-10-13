// worst case O(n^2)
// no auxillary space required in insertion

#include <stdio.h>

void insertionSort(int arr[], int size);
void print( int arr[], int size);

int main(void)
{
    int array [] = {39, 303, 5, 7, 9};
    int size = sizeof(array)/sizeof(array[0]);

    insertionSort(array,size);
    print(array,size);

    return 0;
}

void insertionSort(int arr[], int size)
{
    for ( int i = 1; i < size; i++) // we consider the first element sorted hence we will start at index 1
    {
        int tmp = arr[i];
        int j = i-1;

        while ( j >= 0 && tmp < arr[j]) // responsible for the swaps
        {
            arr[j+1] = arr[j];
            --j;
        }

        arr[j+1] = tmp;
    }
}

void print(int arr[], int size)
{
    for ( int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}