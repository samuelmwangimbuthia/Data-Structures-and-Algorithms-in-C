//pointers that contains the beginning address of a function in memory
// why use function pointers
/*
    -Dynamically determine which function to call at runtime/ make the program flexible to the environment to which its running
    -Asynchronous code, multithreaded programing
    - defining abstractions and creating apis-  allow users to use custom functions within your api

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person {
    char* name;
    int age;
    void (*greeting)();
} Person;

void say_english_greeting();
void say_spanish_greeting();

int main(int argc, char *argv[])
{
    //function pointer declaration
    void(*greeting)();

    // function pointer initialization
    if(argc > 1)
    {
        greeting = !strcmp("spanish", argv[1]) ? &say_spanish_greeting : &say_english_greeting;
    }
    else
    {
        printf("please pass a 'greeting' argument\n");
        return 1;
    }

    char x[] = "fred"; //ISO C++ forbids converting a string constant to char *//copy the string literal into a modifiable array

    Person fred = {x,27,greeting};

    fred.greeting();

    return 0;
}

void say_spanish_greeting()
{
    printf("Hola!\n");
}

void say_english_greeting()
{
    printf("Hello\n");
}