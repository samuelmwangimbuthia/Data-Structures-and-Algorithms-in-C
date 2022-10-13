#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

struct node
{
    int data;
    struct node *previous;
    struct node *next;
} *p, *tmp, *tmp1;

//prototypes;
void insert_Beg(int num);
void insert_End(int num);
void display(int arr[]);

int main(void)
{
    p = NULL;
    return 0;
}

void insert_Beg(int num)
{
    tmp = p;
    tmp1 = (struct node*) malloc(sizeof(struct node));
    tmp1->data = num;
    tmp1->next = p;
    p = tmp1;
}

