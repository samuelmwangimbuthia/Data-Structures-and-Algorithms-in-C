#include <stdio.h>

int main(void)
{
    /* Linear Data Structure: Array, Linked List, Stack, Queue
       Data stored in a sequential manner
       every data element has two neighbours
      have predefined extremes
     Stack and queue implimented using either arrays or linked lists
     */

    /*Non linear data  structure: Binary Tree, Binary Search Tree, AVL Tree, Graph, Red Black Tree
    Allow data to be stored in nonsequential manner
    No predefined extremes
    There can be n number of neighbours
    */

   //Array
   /* why does the array index start at 0;
   the name of the array represent its base address
   */

  int myArray[] = {1,2,3};
  int* p = myArray;
  int z = myArray[1];
  int w = myArray[2];
  int y = myArray[3];

    printf("%p\n",p);
    printf("%p\n",&z);
    printf("%p\n",&w);
    printf("%p\n",&y);
    printf("\n");
  //char myCharArray[] = {'a','b','c'};
  char* i = "abc";
  //char j  = myCharArray[1];
  //char k = myCharArray[2];
 // char l = myCharArray[3];

    printf("%s\n",i);
   // printf("%p\n",&j);
   // printf("%p\n",&k);
    //printf("%p\n",&l);

  
    
    return 0;
}