#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int myNumber = 10;
    int *myPointer;
    
    //print the address of the pointer

    printf("%p\n", myPointer);

    myPointer = &myNumber;

    printf("%p\n", myPointer);

    // initialize a pointer using malloc

    char *name = (char*)malloc(8 * sizeof(char));

    // Dereference a pointer to read a value at its address

    printf("value at my pointer %d\n", *myPointer);

    int myCopiedNumber = *myPointer;

    printf("value of my copied number %d\n", myCopiedNumber);

    name[0] = 's';
    name[1] = 'a';

    printf("the char at %c\n", name[1]);

    free(name);
    return 0;
}