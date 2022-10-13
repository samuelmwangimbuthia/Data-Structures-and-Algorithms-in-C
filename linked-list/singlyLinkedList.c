#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//create a struct to contain the data and hold a link/address to the next node
// Declare root/head alias p , tmp and tmp1 globally so that you don't have to return anything in the 
// individual functions i.e insert_beg etc
 struct node
 {
    int data;
    struct node *next;
} *p, *tmp, *tmp1;

//prototypes
void insert_beg(int);
void insert_end(int);
void delete_beg();
void delete_end();
void display();

int main(void)
{
    int val, n;

    //create the root node/head
    p = NULL;

    //Menu
    do
    {
        printf("********************************MENU*********************\n");
        printf("\n1.INSERT AT END");
        printf("\n2.INSERT AT BEG");
        printf("\n3.INSERT DELETE FROM BEG");
        printf("\n4.INSERT DELETE FROM END");
        printf("\n5.DISPLAY");
        printf("\n6.EXIT");

        printf("\n");
        printf("please enter your choice:   ");

        scanf("%d",&n);
        
        switch (n)
        {
        case 1:
            printf("enter the value \n");
            scanf("%d",&val);
            insert_end(val);
            break;
        case 2:
            printf("enter the value \n");
            scanf("%d",&val);
            insert_beg(val);
            break;
        case 3:
            delete_beg();
            break;
        case 4:
            delete_end();
            break;

        case 5:
            display();
            break;
        case 6:
            exit(0);
            break;
        
        default:
            printf("Wrong Choice \n");
            break;
        }
        printf("do you want to continue \n");
    } while ('y'==getch());
    return 0;
}
void insert_end(int ele)
{
    tmp = p;
    tmp1 = (struct node*)malloc(sizeof(struct node));
    tmp1 -> data = ele;
    tmp1 -> next = NULL;

    if(p == NULL)
    {
        p = tmp1;
    }
    else
    {
        while (tmp1 -> next != NULL)
        {
            tmp = tmp -> next;
            tmp -> next = tmp1;
        }
        
    }

}
void insert_beg(int ele)
{
    tmp = p;
    tmp1 = (struct node*)malloc(sizeof(struct node));
    tmp1 -> data = ele;
    tmp1 -> next = p;
    p = tmp1;
}

void delete_beg()
{
    tmp =p;
    if( p == NULL)
    {
        printf("no element to be deleted \n");
    }
    else
    {
        printf("element deleted %d\n", p ->data);
        p = p ->next;
    }
}

void delete_end()
{
    tmp = p;
    struct node* prev;
    if( p == NULL)
    {
        printf("no element to be deleted \n");
    }
    else if (p -> next == NULL)
    {
        printf("element deleted %d\n", p ->data);
        p = NULL;
    }
    else
    {
        while (tmp ->next != NULL)
        {
            prev = tmp;
            tmp = tmp ->next;
        }
        prev -> next = NULL;
        printf("element deleted %d\n", p ->data);
    }
}   
    void display(void)
    {
        tmp =p;
        while (tmp != NULL)
        {
            printf("%d \n", tmp -> data);
            tmp = tmp->next;
        }
        
    }

    