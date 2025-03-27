#ifndef STRUCTS_H
#define STRUCTS_H

#define INITIAL_CAPACITY 1
#define DEFAULT_GRADE_CAPACITY 1
#define SORTING_ERROR "Invalid sorting criteria.\n"
#define POSITION_ERROR "Invalid position.\n"
#define POSITION_ERROR_CODE -1
#define MAX_STRING_SIZE 100
#define INPUT_ERROR "Invalid input.\n"
#define INPUT_ERROR_CODE -2
#define AGE_NUMBER_LIMIT 3
#define GRADE_NUMBER_LIMIT 2
#define SORINTG_NUMBER_LIMIT 1
#define CLEAR_SCREEN() printf("\e[2J\e[H")

typedef enum {
INIT_STUDENT_ARRAY = 0,
SEARCH_BY_NAME = 1,
SEARCH_BY_AGE = 2,
SEARCH_BY_GRADE = 3,
SORT_STUDENTS_BY_CRITERIA = 4,
INSERT_STUDENT_AT_START = 5,
INSERT_STUDENT_AT_END = 6,
INSERT_GRADE_AT_ANY_POSITION = 7,
DELETE_GRADE_AT_ANY_POSITION = 8,
PRINT_STUDENTS_INFO = 9,
EXIT_CODE = 10
} Order;

typedef enum  {
    BUBBLE_SORT_BY_NAME = 1,
    BUBBLE_SORT_BY_AGE = 2
} SortOrder;

typedef struct {
    int *array;
    int capacity;
    int size;
} IntArray;

typedef struct {
    IntArray grades;
    char *name;
    int age;
} Student;

typedef struct {
    Student *students;
    int capacity;
    int size;
} StudentArray;

#endif //STRUCTS_H
