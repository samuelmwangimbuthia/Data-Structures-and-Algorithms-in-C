// a function calling itself
// intuitive if a problem can be broken down into subproblems
// many data structures are recursive in nature

// steps
// Base condition- stops the recursion
// logic
// Recursive call

// recursion vs iteration
// recursion involves a function calling itself
// there is a space complexity involved with recursion
// recursion works implicitly with stack data structure
// recursion is slower than iteration
// any program that can be written in recursion can be written in iteration

// Tail Recursion
// Here recursive call is the last step of the implementation
//This  a faster approach- No need to maintain activation report
// calling a new function requires an extra amount of reserve memory to manage the call stack called a "stack frame"

#include <stdio.h>

void printNumber(int n);

int main(void)
{
    printNumber(1);

    return 0;
}

void printNumber(int n)
{
    if(n==6)
    {
        return;
    }
    else
    {
        printNumber(n+1);
        printf("%d\n",n);
    }
}