#include <stdio.h>

//prototypes
int partation(int arr[],int beg, int end);
void swap(int *elem1, int *elem2);
void quicksort(int arr[], int beg, int end);
void printArray (int arr[], int size);

int main(int argc, char *argv[])
{
    int array[] = {39, 303, 5, 7, 9};
    int size = sizeof(array)/sizeof(array[0]);

    //print the unsorted array
    printf("My unsorted array is: ");
    printArray(array,size);

    //print the sorted array
    printf("Sorted array is:  ");
    quicksort(array, 0, size-1);
    printArray(array,size);

    return 0;
}

void quicksort(int arr[], int beg, int end)
{
    // implemented recursively
    if(beg < end)
    {
        int pivotIndex = partation( arr,  beg, end);
        quicksort(arr, beg, pivotIndex - 1);
        quicksort(arr,pivotIndex + 1,end);

    }
}

int partation(int arr[], int beg, int end)
{
    //se pivot as the last element
    int pivot = arr[end];
    //set the pivotindex pi
    int pi = (beg-1);

    for(int i = beg; i < end; i++ )
    { 
        if(arr[i] < pivot)
        {
            pi++;
            swap(&arr[i], &arr[pi]);
        }
    }
        swap(&arr[pi+1], &arr[end]);
        return pi + 1;

}

void swap(int *elem1, int *elem2)
{
    int tmp = *elem1;
    *elem1 = *elem2;
    *elem2 = tmp;
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

//Notes
/*
    -follows the paradigm of divide and conquer
    -recursion is used in the implementation
    -in each recursive call a pivot is choosen, then the array is partationed in such a way that all the elements less 
    than the pivot lie to the left and greater to the right.
    -after every call the choosen pivot occupies its correct position in the array which it is supposed to as in sorted array
    -the key process in quicksort is partation.
    - we start from the left most element and keep track of the index of smaller (or equal to) element as i. While traversing, if we find a 
    smaller element, we swap the current element with arr[i]. otherwise we ignore the current element.

*/