#include <stdio.h>
#include <stdlib.h>

int main( int argc, char*  argv[])
{
    int count = 4;
    int *my_pointer = (int*)malloc(count * sizeof(int));

    //Simple pointer addition, notice how the address is increased by size of int 
    for (int i = 0; i < count; i++)
    {
        printf("%p\n", my_pointer + i);
    }
    return 0;
}