#include <stdio.h>
#include <conio.h>

int factorial(int n);

int main(void)
{
    int val;

    do
    {
    printf("please enter the no. to check   \n");
    scanf("%d",&val);
    printf("%d\n",factorial(val));
    printf("do you want to check another number\n  ");
    } while ('y' == getch());
    
}

int factorial(int n)
{
    // base case;
    if(n==0){
        return 1;
    }
    else
    {
        return n * factorial(n-1);
    }
}