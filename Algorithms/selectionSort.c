// Selection Sort
/*
    -comparison done more than swaps
    - in each iteration one element gets placed
    - we choose the minimum element and place it at the beginning of the array
    - alternatively we place the maximum element at the rear end
    
*/

//
#include <stdio.h>

void selectionSort(int arr[], int size);
void print(int arr[],int size);

int main(void)
{
    int array[] = {14,17,8,90,11,2};
    int size = sizeof(array)/sizeof(array[0]);

    selectionSort(array, size);
    print(array,size);
    return 0;

}

void selectionSort(int arr[], int size)
{
        //we use size-1 since j will always be ahead of i by one index in the inner for loop
    for( int i = 0; i < size-1; i++)
    {
        int min = i; // let the minimum index point at index 0;
        for( int j = i+1; j<size; j++)//the inner loop is only used for comparison
        {
            if (arr[j]< arr[min])
            {
                min = j;
            }

            int tmp = arr[i];
            arr[i] = arr[min];
            arr[min] = tmp;

        }

    }
}

void print(int arr[], int size)
{
    int i;
    for (i=0; i<size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}