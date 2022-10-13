#include <stdio.h>
#include <stdlib.h>

//declare the node globally 
typedef struct  node
{
    int data;
    struct node *next;
}node;


int main(void)
{
    // create the list and initalize it to NULL
    node *list = NULL;

    // create a tmp variable whose value is the address to a memory location

    node *tmp = (node *)malloc(sizeof(node));
    //quit if the returned memory location is null
    if (tmp == NULL)
    {
        return 1;
    }
    else
    {
        tmp ->data = 10;
        tmp ->next = NULL;
    }
    //update list to point to new node
    list = tmp;

    //add another element to list
    tmp = (node*)malloc(sizeof(node));
    if(tmp == NULL)
    {
        free(list);
        return 1;
    }
    else
    {
        tmp->data = 20;
        tmp->next = NULL;
        list->next = tmp;
    }
    //add another element to list
    tmp = (node*)malloc(sizeof(node));
    if(tmp == NULL)
    {
        free(list->next);
        free(list);
        return 1;
    }
    else
    {
        tmp->data = 30;
        tmp->next = NULL;
        list->next->next = tmp;

    }
    //display list data
        tmp = list;
    while (tmp != NULL)
    {
        printf("%d\n", tmp->data);
        tmp = tmp->next;
    }
    

    //free list
    while (list != NULL)
    { 
        node *tmp =list;
        free(list);
        list = tmp;
    }
    
    return 0;
}