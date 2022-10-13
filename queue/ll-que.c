#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
    int data;
    struct node* next;
}*p, *tmp, *tmp1;

void enqueue(int elem){ 
    tmp = p;

    tmp1 = (struct node*) malloc(sizeof(struct node));
    tmp1->data = elem;
    tmp1->next = NULL;

    if(p == NULL){
        p = tmp1;
    }
    else {
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = tmp1;
    }

}


void dequeue()
{
    tmp=p;
    if(tmp == NULL)
    {
        printf("\nNo element to delete");
    } else
    {
        printf("\ndeleted %d", tmp->data);
        tmp = tmp->next;
        p = tmp;
    }
    
}

void isEmpty(){
    if(p == NULL){
        printf("\n the queue is empty");
    }
        printf("\n the queue is NOT empty");
}

void display()
{
    tmp = p;
    while(tmp != NULL){
        printf("\n%d",tmp->data);
        tmp = tmp->next;
    }
}

int main(void)
{
    int val, n;

    do
    {
        printf("\n**********************MENU**********");
        printf("\n1.ENQUEUE");
        printf("\n2.DEQUEUE");
        printf("\n3. IS EMPTY");
        printf("\n6. EXIT");
        printf("\n8. DISPLAY");
        printf("\nEnter your choice....");

        scanf("%d", &n);

        switch (n)
        {
        case 1:
            printf("\nenter the value  ");
            scanf("%d", &val);
            enqueue(val);
            break;
        case 2:
            dequeue();
            break;    
        case 3:
            isEmpty();
            break;
        case 6:
            exit(0);
            break;
        case 8:
            display();
            break;
        default:
            printf("wrong choice!");
            break;
        }
    printf("\ndo you want to continue...");
    } while ('y' == getch());
    
    return 0;
}
