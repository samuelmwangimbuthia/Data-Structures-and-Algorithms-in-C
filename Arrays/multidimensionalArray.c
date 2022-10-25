#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLUMNS 4

int main(int argc, char* argv[])
{
    //declare and initialize a multidimensional array containing 10 columns and 4 rows
    int matrix[ROWS][COLUMNS] = {
        {1,0,1,0},
        {0,0,1,1},
        {1,1,1,1},
        {0,0,1,1},
        {1,1,0,0},
        {0,0,0,0},
        {1,1,1,1},
        {1,0,0,1},
        {1,1,0,1},
        {0,1,1,0}
    };

    // loop over each column within each row
    for (int i =0; i<ROWS; i++)
    {
        for ( int j = 0; j < COLUMNS; j++)
        {
            // flip all the bits within each row, 0's will become 1's and viceversa
            matrix[i][j] = matrix[i][j]^1;
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}