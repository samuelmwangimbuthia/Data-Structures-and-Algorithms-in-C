#include <stdio.h>
#include <stdlib.h>

//prototypes
void print_int_by_reference(int *number_ptr);
void print_int_by_value(int number);

void malloc_int_dangerous(int *number_ptr);
void malloc_int_safe(int **number_ptr);

int main(int argc, char*argv[])
{
    // Give example of passing an int via a pointer instead of by value
    int my_number = 10;

    print_int_by_value(my_number);
    print_int_by_reference(&my_number);

    printf("the address printed above should be different! ^^\n\n\n");

    return 0;
}

void print_int_by_value(int number)
{
    printf("print int => address: %p | value: %d\n", &number, number);

}
void print_int_by_reference(int *number)
{
    printf("print int => address: %p | value: %d\n", number, *number);

}
