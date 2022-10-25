#include <stdio.h>

//prototypes
void selectionSort(int arr[], int size);
void printArray (int arr[], int size);

int main(void)
{
    int myArray[] = {45,26,13,4,6,9};
    int size = sizeof(myArray)/sizeof(myArray[0]);

    printArray(myArray, size);

    selectionSort(myArray,size);

    printArray(myArray, size);
    return 0;
}

void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size -1; i++) // it is n-1 because the inner loop iterates from the second element
    {
        //set the minimum index to point at the first element

        int min = i;
        for ( int j = i+1; j < size; j++)
        {
            //compare and update min
            if ( arr[j] < arr[min])
            {
                min = j;
            }

        }
            int tmp = arr[min];
            arr[min] = arr[i];
            arr[i] = tmp;
    }
}

//print the array

void printArray (int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}