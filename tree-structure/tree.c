#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}node;

node* create(node* bt, int elem, char direction);
void free_tree(node *root);
void print_tree(node *root);
bool search(node *root, int number);


int main(void)
{
    
    //create the tree of size zero
    node *tree = (node*)malloc(sizeof(node));
    tree->data = -1;
/*
    //add fields to the root 
    node *tmp = (node*)malloc(sizeof(node));
    if(tmp == NULL)
    {
        return 1;
    }
    else
    {
        tmp->data = 2;
        tmp->left = NULL;
        tmp->right = NULL;
    }
tree = tmp;
    // add another node
    tmp = (node*)malloc(sizeof(node));
    if(tmp == NULL)
    {
        //free memory
        return 1;
    }
    else
    {
        tmp->data = 1;
        tmp->left = NULL;
        tmp->right = NULL;
        tree->left = tmp;
    }
    // add another node
    tmp = (node*)malloc(sizeof(node));
    if(tmp == NULL)
    {
        return 1;
    }
    else
    {
        tmp->data = 3;
        tmp->left = NULL;
        tmp->right = NULL;
        tree->right = tmp;
    }
*/
create(tree,1,'l');
create(tree,2,'r');

print_tree(tree);
printf("%d\n",search(tree, 4));
free_tree(tree);

    return 0;
}
   
node* create(node* p, int elem, char direction){
    
    node *tmp;
    tmp = (node*)malloc(sizeof(node));
    tmp->data =elem;
    tmp->left =NULL;
    tmp->right =NULL;

    if(direction == 'l')
    {
        p->left = tmp;
    }
    else{  
    p->right =tmp;
    }
    return p;
   }

    void free_tree(node *root)
    {
        if(root == NULL)
        {
            return;
        }
        free_tree(root -> left);
        free_tree(root -> right);
        free_tree(root);
    }

    //print tree (print left, yourself, and finally right at every hierarchy level  )
    void print_tree(node *root)
    {
        if (root == NULL)
        {
            return; //base case
        } 
        print_tree(root->left); 
        printf("%i\n", root -> data);
        print_tree(root-> right);
    }

    bool search(node *tree, int number)
    {
        if (tree == NULL)
        {
            return false;
        }
        else if (number < tree ->data)
        {
            return search(tree -> left, number);
        }
        else if (number > tree ->data)
        {
            return search(tree -> right, number);
        }
        else
        {
            return true;
        }
    }