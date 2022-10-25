
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define ARRAY_SIZE 4 //size of all arrays to be instantiated. Keep track of the size at runtime

typedef struct Person
{
    int age;
    int number;
} Person;

int main(int argc, char *argv[])
{
    //different methods of declaring and initializing an array
    int numbers[] = {1,2,3,4};
    const char name[] = "Zack"; // under the hood it has a length of 5 due to the terminating null character

    const Person people[] = {
        {13,1},
        {12,2}
    };

    // array name decay to pointers

    assert(numbers == &numbers[0]); //if this evaluates to false, our program would crash
    return 0;

}