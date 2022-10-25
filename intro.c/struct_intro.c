#include <stdio.h>
#include <stddef.h>

// custom type definition
typedef struct Grade
{
    char letter;
    int rank;
} Grade;

int main(int argc, char* argv[])
{
    //Declare and initialize a  structure variable
    Grade student_grade = {'A', 93};

    // read values from a struct's members
    printf("%c\n", student_grade.letter);
    printf("%d\n", student_grade.rank);

    //get byte size of struct members and the byte size of the struct
    const size_t letter_byte_size = sizeof(student_grade.letter);
    const size_t rank_byte_size = sizeof(student_grade.rank);

    printf("byte size of student letter: %d\n", letter_byte_size);
    printf("byte size of student rank: %d\n", rank_byte_size);

    const size_t student_grade_byte_size = sizeof(student_grade);
    printf("total byte size of student grade struct %d\n", student_grade_byte_size);

    // reveal memory addresses position of struct member

    printf("address for letter: %p\n", &student_grade.letter);
    printf("address for rank: %p\n", &student_grade.rank);

    // calculate padding via memory offsets using <stddef.h> , offsetof macro

    const size_t letter_offset = offsetof(Grade,letter),
                rank_offset = offsetof(Grade, rank),
                padding = rank_offset - (letter_offset + letter_byte_size);

    //
    printf("letter byte offset %zu\n", letter_offset);
    printf("rank byte offset %zu\n", rank_offset);
    printf("padding %zu\n", padding);

    return 0;
}

