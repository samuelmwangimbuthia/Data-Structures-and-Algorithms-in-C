#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
    int data;
    struct node *next;
} *p, *tmp, *tmp1, *end;

void insert( int elem);
void display();
void delete_beg();
void isEmpty();

int main(void)
{
    int val, n;
    p = NULL;
    
    do
    {
        printf("***************MENU*********\n");
        printf("\n1.PUSH");
        printf("\n2.Display");
        printf("\n3.Delete");
        printf("\n4.isEmpty");
        printf("\n5.Exit");
        printf("\nplease enter your choice: ");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            printf("please enter a value: \n");
            scanf("%d", &val);
            insert(val);
            break;
        case 2:
            display();
            break;
        case 3:
            delete_beg();
            break;
        case 4:
            isEmpty();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("wrong choice \n");
            break;
        }
        
    } while ('y' == getch());
    
}

// create a node
// allocate memory to the node 
void insert( int elem)
{
    struct node *tmp = (struct node*)malloc( sizeof(struct node));
    //TODO: check if the returned pointer is null
        tmp ->data = elem;
    if (p == NULL)
    {
        tmp ->next = NULL;
    }
    else 
    {
        tmp -> next = p;
    }

    p = tmp;

}
    void delete_beg()
    {
        tmp = p;
        if(p == NULL)
        {
            printf("no elements to delete");
        }
        else
        {
            p = p->next;
        }
    }

void isEmpty()
{
    if(p == NULL)
    {
        printf("the stack is empty\n");

    }
    printf("the stack is not empty");
}

void display()
{
    tmp = p;

    while(tmp != NULL)
    {

        printf("%d \n", tmp->data);
        tmp = tmp->next;
    }
}