#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <conio.h>

struct stackk
{
    int top;
    unsigned size;
    int *array;
};

    //create method
    struct stackk* create(unsigned size)
    {
        // allocate memory to the stackk
        struct stackk *stackk = (struct stackk*)malloc(sizeof(struct stackk));
        stackk->top = -1;
        stackk->size = size;
        stackk->array = (int*)malloc(stackk->size * sizeof(int));
        return stackk;
    }
 
    //check if the stackk is full
    int isfull(struct stackk* stackk)
    {
        return stackk->top == stackk->size - 1;
    };

    //check if the stackk is empty
    int isEmpty(struct stackk* stackk)
    {
        return stackk->top == - 1;
    };

    //push method
    int push(struct stackk* stackk, int elem)
    {
        if(isfull(stackk))
        {
            return -1;
        }
        else
        {
            return stackk->array[++stackk->top] = elem;
        }
    }

    int pop(struct stackk* stackk)
    {
        if(isEmpty(stackk))
        {
            return -1;
        }
        else
        {
           return stackk->array[stackk->top --];
        }
    }

    int peek(struct stackk* stackk)
    {
        if(isEmpty(stackk))
        {
            return -1;
        }
        else
        {
            return stackk->array[stackk->top];
        }
    }

int main(void)
{
    //create the stackk
    int val, n;
    struct stackk* stackk = create(100);

    do
    {
        printf("***************MENU*********\n");
        printf("\n1.PUSH");
        printf("\n2.POP");
        printf("\n3.PEEK");
        printf("\n4.IS EMPTY");
        printf("\n5.EXIT");
        printf("please enter your choice: \n");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            printf("please enter a value to push: \n");
            scanf("%d", &val);
            push(stackk, val);
            break;
        case 2:
            if(-1){
                printf("your array is empty");
            }
            else{
            printf("Deleted value: %d\n",pop(stackk));
            }
            break;
        case 3:
            printf("top element is: %d\n", peek(stackk));
            break;
        case 4:
            printf("is Empty: %d\n", isEmpty(stackk));
            scanf("%d", &val);
            push(stackk, val);
            break;
        case 5:
            exit(0);
        
        default:
            printf("wrong choice.please try again\n");
            break;
        }
        printf("do you want to continue.....\n");
    } while ('y' == getch());
    
    return 0;
}