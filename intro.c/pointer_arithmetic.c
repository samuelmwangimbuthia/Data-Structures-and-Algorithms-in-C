//when to use pointer arithmetic
/*
    Calcualting byte offset - the location of a piece of data compared to another location.
                            - when reading a large binary file /you can add a numerical number to your current address to
                              get a new pointer to that binary offset.
    Comparing memory addresses
    
    Rare cases where code is cleaner as a result - iterating over array of values/simply increamenting memory addresses
                            -
*/
//Dangers of pointer arithmetic
    /*
        Readability- poor
        Overflow - you can easily write outside of memory bounds
        complex - proceed with caution
    */

#include <stdio.h>
#include <stdlib.h>

int main( int argc, char*  argv[])
{
    int count = 4;

    //Dynamically allocate memory large enough for four pointers
    int *my_pointer = (int*)malloc(count * sizeof(int));

    //Simple pointer addition, notice how the address is increased by size of int 
    for (int i = 0; i < count; i++)
    {
        printf("%p\n", my_pointer + i);
    }

    //Assign value to memory addresses using pointer arithmetic
    int initialValue = 5;
    for ( int i = 0; i < count; i++)
    {
        *(my_pointer + i) = initialValue++; //parenthesis are required here due to operator precedence!

        printf("'my_pointer' position %d value: %d\n", i, *(my_pointer + i));
    }

    free(my_pointer);
    return 0;
}