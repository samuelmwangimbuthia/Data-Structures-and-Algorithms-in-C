#include <stdio.h>
#include <stdbool.h>

void search(int number);

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        printf("Usage: ./linearSearch Number\n");
    }
    else
    {
        int number = 3;
        search(number);
    }


    
    return 0;
}

void search(int number)
{
        int myArray[] = {7,6,3,9,10,45,2};
        int size = sizeof(myArray)/ sizeof(myArray[0]);
        for(int i = 0; i < size; i++)
        {
            if(myArray[i] == number){
                printf("The number you were searching for : %d found\n", number);
            }

        }
        return;
}