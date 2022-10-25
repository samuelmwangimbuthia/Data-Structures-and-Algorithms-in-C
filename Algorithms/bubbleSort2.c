#include <stdio.h>

//prototypes
void bubbleSort(int arr[], int size);
void printArray (int arr[], int size);

int main(void)
{
    //my unsorted array
    int myUnsortedArray[] = {13,5,145,76,2,5};
    int size = sizeof(myUnsortedArray)/sizeof(myUnsortedArray[0]);

    //print the unsorted array
    printf("My unsorted array is: ");
    printArray(myUnsortedArray,size);

    //print the sorted array
    printf("Sorted array is:  ");
    bubbleSort(myUnsortedArray, size);
    printArray(myUnsortedArray,size);
}

//sorting algorithm
void bubbleSort(int arr[], int size)
{
    //iterate through the array with the outer for loop
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++ )
        {
            //compare arr[j] element with every other element
            if (arr[j] > arr[j+1])
            {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
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