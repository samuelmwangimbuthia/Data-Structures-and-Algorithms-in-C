#include <stdio.h>
#include <stdlib.h>

//
typedef struct Node 
{
    int data;
    struct Node *next;
} Node;


//to keep count of the number of nodes
typedef struct linkedlist
{
    int count;
    Node *head;

} linkedlist;

// API's for working with the linked list

linkedlist* init_linked_list();
void destroy_linked_list(linkedlist*);
void print_linked_list(linkedlist*);
void print_node(Node*);
void insert_node(linkedlist*, int);
void remove_node(linkedlist*, Node*);

int main(int argc, char* argv[])
{
    linkedlist *my_list = init_linked_list();
    if (!my_list)
        return 1;

    insert_node(my_list, 1);
    print_linked_list(my_list);

    insert_node(my_list, 2);
    print_linked_list(my_list);

    insert_node(my_list, 3);
    print_linked_list(my_list);

    remove_node(my_list, my_list->head->next);
    print_linked_list(my_list);

    destroy_linked_list(my_list);

    return 0;
}

//the init_linked list returns a pointer to an empty linked list after allocating memory for it on the heap
linkedlist *init_linked_list()
{
    linkedlist *list = (linkedlist*)malloc(sizeof(linkedlist));
    if (list != NULL)
    {
        list ->count = 0;
        list -> head = NULL;
    }

    return list;
}

// the destroy_linked_list will free memory of all the linked list nodes
void destroy_linked_list(linkedlist *list)
{
    // base case
    if (list == NULL)
    {
        return;
    }
    
    Node *current = list -> head;

    while ( current != NULL)
    {
        Node *next = current -> next;
        remove_node(list, current);
        current = next;
    }
    free(list);
    printf("list destroyed.\n");
}

void print_linked_list(linkedlist *list) {
    if (list == NULL)
        return;

    Node *current = list->head;
    while (current != NULL) {
        print_node(current);
        current = current->next;
    }
    printf("\n");
};

void print_node(Node *node) {
    printf("[%d] => %s", node->data, node->next ? "" : "NULL");
}

void insert_node(linkedlist* list, int data) {
    if (list == NULL)
        return;

    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    
    Node *tail = NULL,
         *current = list->head;

    while (current) {
        tail = current;
        current = current->next;
    }


    if (tail == NULL) {
        list->head = new_node;
    } else {
        tail->next = new_node;
    }

    list->count++;
};

void remove_node(linkedlist* list, Node* node) {
    if (list == NULL || list->head == NULL || node == NULL)
        return;

    if (list->head == node) {
        printf("Destroying: [%d]\n", node->data);
        Node *next = list->head->next;
        free(list->head);

        list->count--;
        list->head = next;
        return;
    }
    
    Node *current  = list->head,
         *previous = NULL;
    
    while (current != NULL) {
        if (current == node) {
            printf("Destroying: [%d]\n", current->data);
            previous->next = current->next;
            free(current);
            break;
        } else {
            previous = current;
            current = current->next;
        }
    }

    list->count--;
};
