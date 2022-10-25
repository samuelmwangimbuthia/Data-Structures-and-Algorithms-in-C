#include <stdio.h>

//prototypes
void printArray (int arr[], int size);
void insertionSort(int arr[], int size);

int main(void)
{
    int array [] = {39, 303, 5, 7, 9};
    int size = sizeof(array)/sizeof(array[0]);

    //print the unsorted array
    printf("My unsorted array is: ");
    printArray(array,size);

    //print the sorted array
    printf("Sorted array is:  ");
    insertionSort(array, size);
    printArray(array,size);
   return 0; 
}

void insertionSort(int arr[], int size)
{
    //the outer loop start from index 1
    for (int i = 1; i < size; i++)
    {
        //set the first element as sorted element tmp
        int tmp = arr[i];
        int j = i-1;
        // check if the next element is smaller without going beyond

        while (j >= 0 && arr[j] > tmp)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = tmp;  //add 1 because the array was already decreamented by 1;
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