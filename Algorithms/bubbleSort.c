//Bubble sort anlysis
/*
    Number of comparisons- O(n2)
    Number of swaps-O(n2)
    Stable-swap occur if and only if there is a difference between arr[j] and arr[j+1], order also maintained if the two are equal
    Inplace - no extra memory required in form of stack, llist etc
*/

#include <stdio.h>

void sort(int arr[], int size);
void print(int arr[], int size);

int main(void)
{
    int unsorted[] = {2,56,78,57,11};
    int size = sizeof(unsorted)/ sizeof(unsorted[0]);

    sort(unsorted,size);

    print(unsorted, size);

}


void sort(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j =0; j < size-i-1; j++ )
        {
            if(arr[j] < arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

            }
            
        }
    }
}

void print(int arr[], int size)
{
    for(int i=0; i<size; i++)
    {
        printf("%d\n",arr[i]);
    }
}
