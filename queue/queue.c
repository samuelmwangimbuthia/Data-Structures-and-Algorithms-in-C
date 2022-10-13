#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <conio.h>

struct node
{
    int front, rear, size;
    unsigned actualSize;
    int *arr;
};


struct node* createque(unsigned actualSize)
{
    struct node* que = (struct node*) malloc (sizeof (struct node));
    que->actualSize = actualSize;
    que->size = 0;
    que->front = que->rear = -1;
    que->arr = (int*)malloc(que->actualSize * sizeof(int));
    return que;
}

int isFull(struct node* que){
    return (que->size == que->actualSize);
}

int isEmpty(struct node* que){
    return(que->size == 0);
}
// implementing enqueue
void enqueue(struct node* que, int elem){
    if(isFull(que)){
        return;
    }
    else 
    {  
    que->rear = que->rear+1;
    que->arr[que->rear] = elem;
    que->size = que->size+1;   
    if(que->front==-1) //To update the front to also point at 0  NB applicable only when inserting in an empty queue
    {
        que->front++;  
    }
     printf("%d enqueued to que\n", elem);
    }
}

int dequeue(struct node* que){
    if (isEmpty(que)){
        return INT_MIN;
    }
    int elem = que->arr[que->front];
    if(que->front == que->rear){
        que->front = que->rear = -1;
    }
    else
    {
        que->front = que->front +1;
    }
    que->size = que->size-1;
    return elem;
}


int isFront(struct node* que)
{
    if(isEmpty(que))
    return INT_MIN;
    return que->arr[que->front];
}

int rear(struct node* que){
    if(isEmpty(que))
    return INT_MIN;
    return que->arr[que->rear];
}

int main(void)
{
    int val, n;
    struct node* que = createque(1000);
    do
    {
        printf("\n**********************MENU**********");
        printf("\n1.ENQUEUE");
        printf("\n2.DEQUEUE");
        printf("\n3. IS EMPTY");
        printf("\n4.IS FULL");
        printf("\n5. FIRST ELEM");
        printf("\n6. LAST ELEM");
        printf("\n7. EXIT");
        printf("\nEnter your choice....");

        scanf("%d", &n);

        switch (n)
        {
        case 1:
            printf("\nenter the value  ");
            scanf("%d", &val);
            enqueue(que,val);
            break;
        case 2:
            dequeue(que);
            break;    
        case 3:
            printf("\nIsEmpty: %d", isEmpty(que));
            break;
        case 4:
            printf("\nIsFull: %d", isFull(que));
            break;
        case 5:
            printf("\n front element: %d", isFront(que));
            break;
        case 6:
            printf("\n rear element: %d", rear(que));
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("wrong choice!");
            break;
        }
    printf("\ndo you want to continue...");
    } while ('y' == getch());
    
    return 0;
}