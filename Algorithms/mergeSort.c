#include <stdio.h>

//prototypes
 void mergeSort(int arr[], int start, int end);
 void merge(int arr[], int start, int mid, int end);
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
    mergeSort(array, 0, size-1);
    printArray(array,size);

    return 0;
}
//mergeSort function responsible for dividing the array
void mergeSort(int arr[], int start, int end)
{
    //calculate the mid point
    int mid = start + (end - start)/2;

    //recursively call the mergeSort on each half
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

// merge function for conquer/merging the subarrays

void merge(int arr[], int start, int mid, int end)
{
    int len1 = mid -start + 1;
    int len2 = end - mid;
    int leftArr[len1], rightArr[len2]; // arrays of size len

    for(int i = 0; i < len1; i++)
    {
        leftArr[i] = arr[start + i];
    }

    for(int j =0; j < len2; j++)
    {
        rightArr[j] = arr[mid + 1 + j];
    }

    int i, j, k; // to be used in the while loop
    i = 0;
    j = 0;
    k = start;
    while(i < len1 && j < len2)
    {
        if(leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        } else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    //pick the remaining elements
    while(i < len1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while(j < len2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
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
