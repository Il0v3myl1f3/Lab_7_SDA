#include "funcs.h"
#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void student_management_menu(StudentArray *student_array) {
    int input;
    do {
        char buffer[MAX_STRING_SIZE];
        print_menu();
        int validation_number = 2;
        input = safe_scanf(buffer, validation_number);
        if (input == INPUT_ERROR_CODE) {
            printf(INPUT_ERROR);
            continue;
        }
        CLEAR_SCREEN();

        if (input != 0 && input != EXIT_CODE && student_array == NULL) {
            printf("Error: Student array is not initialized. \n");
            continue;
        }

        switch (input) {
            case INIT_STUDENT_ARRAY: {
                if (student_array != NULL) {
                    printf("Student array is already initialized.\n");
                } else {
                    student_array = init_students_array();
                    printf("Student array is initialized.\n");
                }
                break;
            }
            case SEARCH_BY_NAME: {
                char target_name[MAX_STRING_SIZE];
                printf("Enter searched name: ");
                scanf("%s", target_name);
                int position = search_student_by_name(student_array, target_name);
                if (position == POSITION_ERROR_CODE) {
                    printf(POSITION_ERROR);
                } else {
                    printf("Position: %d\n", position + 1);
                }
                break;
            }
            case SEARCH_BY_AGE: {
                int target_age;
                printf("Enter searched age: ");
                scanf("%d", &target_age);
                int position = search_student_by_age(student_array, target_age);
                if (position == POSITION_ERROR_CODE) {
                    printf(POSITION_ERROR);
                } else {
                    printf("Position: %d\n", position + 1);
                }
                break;
            }
            case SEARCH_BY_GRADE: {
                int target_grade;
                printf("Enter searched grade: ");
                scanf("%d", &target_grade);
                int position = search_student_by_grade(student_array, target_grade);
                if (position == POSITION_ERROR_CODE) {
                    printf(POSITION_ERROR);
                } else {
                    printf("Position: %d\n", position + 1);
                }
                break;
            }
            case SORT_STUDENTS_BY_CRITERIA: {
                char sort_buffer[MAX_STRING_SIZE];
                print_sorting_criteria();
                int criteria = safe_scanf(sort_buffer, SORTING_NUMBER_LIMIT);
                sort_students_array(student_array, criteria);
                break;
            }
            case INSERT_STUDENT_AT_START: {
                insert_student_at_start(student_array);
                break;
            }
            case INSERT_STUDENT_AT_END: {
                insert_student_at_end(student_array);
                break;
            }
            case INSERT_GRADE_AT_ANY_POSITION: {
                insert_grade_at_any_position(student_array);
                break;
            }
            case DELETE_GRADE_AT_ANY_POSITION: {
                delete_grade_at_any_position(student_array);
                break;
            }
            case PRINT_STUDENTS_INFO: {
                print_students_list(student_array);
                break;
            }
            case EXIT_CODE:
                break;
            default:
                printf(INPUT_ERROR);
                break;
        }
    } while (input != EXIT_CODE);

    if (student_array != NULL) {
        free_students_array(student_array);
    }
}

int safe_scanf(char *buffer, int validation_number){
    fflush(stdin);
    if (fgets(buffer, MAX_STRING_SIZE, stdin) == NULL) {
        return INPUT_ERROR_CODE;
    }

    buffer[strcspn(buffer, "\n")] = '\0';

    if (strlen(buffer) == 0) {
        return INPUT_ERROR_CODE;
    }

    if (strlen(buffer) > validation_number) {
        return INPUT_ERROR_CODE;
    }

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (!isdigit(buffer[i])) {
            return INPUT_ERROR_CODE;
        }
    }

    return atoi(buffer);
}

int _read_student_age() {
    char buffer[MAX_STRING_SIZE];
    printf("Enter student age: ");
    int student_age = safe_scanf(buffer, AGE_NUMBER_LIMIT);
    if(student_age == INPUT_ERROR_CODE){
        printf(INPUT_ERROR);
        exit(INPUT_ERROR_CODE);
    }
    return student_age;
}

int _read_student_grade() {
    char buffer[MAX_STRING_SIZE];
    printf("Grade: ");
    int new_grade = safe_scanf(buffer, GRADE_NUMBER_LIMIT);
    if(new_grade == INPUT_ERROR_CODE){
        printf(INPUT_ERROR);
        exit(INPUT_ERROR_CODE);
    }
    return new_grade;
}

void _read_student_grades(Student *student) {
    assert(student);
    printf("Enter %d grades:\n", student->grades.size);
    for (int j = 0; j < student->grades.size; j++) {
        student->grades.array[j] = _read_student_grade();
    }
}

char *_read_student_name() {
    char *student_name = calloc(MAX_STRING_SIZE, sizeof(char));
    printf("Enter student name: ");
    scanf("%s", student_name);
    student_name[strlen(student_name)] = '\0';
    return student_name;
}

void read_student_info(Student *student) {
    assert(student);
    student->name = _read_student_name();
    student->age = _read_student_age();
    _read_student_grades(student);
}

StudentArray *init_students_array() {
    StudentArray *student_array = calloc(1, sizeof(StudentArray));
    assert(student_array != NULL);
    student_array->capacity = INITIAL_CAPACITY;
    student_array->size = 0;
    student_array->students = calloc(INITIAL_CAPACITY, sizeof(Student));
    assert(student_array->students != NULL);
    return student_array;
}

void init_declarations(Student *student) {
    assert(student);
    student->name = calloc(MAX_STRING_SIZE, sizeof(char));
    assert(student->name != NULL);
    student->grades.capacity = DEFAULT_GRADE_CAPACITY;
    student->grades.size = DEFAULT_GRADE_CAPACITY;
    student->grades.array = calloc(student->grades.capacity, sizeof(int));
    assert(student->grades.array != NULL);
    read_student_info(student);
}

void check_students_array_size(StudentArray *student_array) {
    assert(student_array);
    if (student_array->size >= student_array->capacity) {
        if (student_array->capacity > 0) {
            student_array->capacity = student_array->capacity * 2;
        } else {
            student_array->capacity = 1;
        }
        _realloc_student_array(student_array);
    }
    student_array->size++;
}

void insert_student_at_start(StudentArray *student_array) {
    assert(student_array);
    check_students_array_size(student_array);
    if (student_array->size > 1) {
        for (int i = student_array->size - 1; i > 0; i--) {
            student_array->students[i] = student_array->students[i - 1];
        }
    }
    init_declarations(&student_array->students[0]);
}

void insert_student_at_end(StudentArray *student_array) {
    assert(student_array);
    check_students_array_size(student_array);
    init_declarations(&student_array->students[student_array->size - 1]);
}

void insert_grade_at_any_position(StudentArray *student_array) {
    assert(student_array);
    int student_index = get_student_position(student_array);
    if (student_index == POSITION_ERROR_CODE)
        return;

    Student *student = &student_array->students[student_index - 1];
    int new_grade_position = get_grade_position(student);
    if (new_grade_position == POSITION_ERROR_CODE)
        return;

    int new_grade = _read_student_grade();
    check_grades_array_size(student);

    int grade_position = new_grade_position - 1;
    for (int i = student->grades.size; i > grade_position; i--) {
        student->grades.array[i] = student->grades.array[i - 1];
    }
    student->grades.array[grade_position] = new_grade;
    student->grades.size++;
}

void delete_grade_at_any_position(StudentArray *student_array) {
    assert(student_array);
    int student_index = get_student_position(student_array);
    if (student_index == POSITION_ERROR_CODE)
        return;

    Student *student = &student_array->students[student_index - 1];
    int new_grade_position = get_grade_position(student);
    if (new_grade_position == POSITION_ERROR_CODE)
        return;

    for (int i = new_grade_position - 1; i < student->grades.size - 1; i++) {
        student->grades.array[i] = student->grades.array[i + 1];
    }
    student->grades.size--;
    check_grades_array_size(student);
    _realloc_int_array(&student->grades);
}

void bubble_sort_by_name(StudentArray *student_array) {
    assert(student_array);
    for (int i = 0; i < student_array->size - 1; i++) {
        for (int j = 0; j < student_array->size - 1 - i; j++) {
            if (strcmp(student_array->students[j].name, student_array->students[j + 1].name) > 0) {
                Student temp = student_array->students[j];
                student_array->students[j] = student_array->students[j + 1];
                student_array->students[j + 1] = temp;
            }
        }
    }
}

void bubble_sort_by_age(StudentArray *student_array) {
    assert(student_array);
    for (int i = 0; i < student_array->size - 1; i++) {
        for (int j = 0; j < student_array->size - 1 - i; j++) {
            if (student_array->students[j].age > student_array->students[j + 1].age) {
                Student temp = student_array->students[j];
                student_array->students[j] = student_array->students[j + 1];
                student_array->students[j + 1] = temp;
            }
        }
    }
}

void sort_students_array(StudentArray *student_array, int criteria) {
    assert(student_array);
    switch (criteria) {
        case BUBBLE_SORT_BY_NAME:
            bubble_sort_by_name(student_array);
            break;
        case BUBBLE_SORT_BY_AGE:
            bubble_sort_by_age(student_array);
            break;
        default:
            printf(SORTING_ERROR);
            break;
    }
}

void free_students_array(StudentArray *student_array) {
    assert(student_array);
    for (int i = 0; i < student_array->size; i++) {
        free(student_array->students[i].name);
        free(student_array->students[i].grades.array);
    }
    free(student_array->students);
    free(student_array);
}

void print_sorting_criteria(void) {
    printf("Sort by:\n");
    printf("1. Name\n");
    printf("2. Age\n");
    printf("Enter your choice: ");
}

void check_grades_array_size(Student *student) {
    assert(student);
    if (student->grades.size >= student->grades.capacity) {
        if (student->grades.capacity > 0) {
            student->grades.capacity = student->grades.capacity * 2;
        } else {
            student->grades.capacity = 1;
        }
        _realloc_int_array(&student->grades);
    }
}

void print_student_info(StudentArray *student_array, int i) {
    assert(student_array);
    printf("Student %d:\n", i + 1);
    printf("  Name: %s\n", student_array->students[i].name);
    printf("  Age: %d\n", student_array->students[i].age);
    printf("  Grades: ");
    for (int j = 0; j < student_array->students[i].grades.size; j++) {
        printf("%d ", student_array->students[i].grades.array[j]);
    }
    printf("\n\n");
}

void print_students_list(StudentArray *student_array) {
    assert(student_array);
    printf("\nStudent List:\n");
    for (int i = 0; i < student_array->size; i++) {
        print_student_info(student_array, i);
    }
}

int search_student_by_name(StudentArray *student_array, const char *target_name) {
    assert(student_array);
    for (int i = 0; i < student_array->size; i++) {
        if (strcmp(student_array->students[i].name, target_name) == 0) {
            return i;
        }
    }
    return POSITION_ERROR_CODE;
}

int search_student_by_age(StudentArray *student_array, int target_age) {
    assert(student_array);
    for (int i = 0; i < student_array->size; i++) {
        if (student_array->students[i].age == target_age) {
            return i;
        }
    }
    return POSITION_ERROR_CODE;
}

int search_student_by_grade(StudentArray *student_array, int target_grade) {
    assert(student_array);
    for (int i = 0; i < student_array->size; i++) {
        for (int j = 0; j < student_array->students[i].grades.size; j++) {
            if (student_array->students[i].grades.array[j] == target_grade) {
                return i;
            }
        }
    }
    return POSITION_ERROR_CODE;
}

void print_menu(void) {
    printf("\n\tMENU\n");
    printf("0. Initialize student array\n");
    printf("1. Search by name\n");
    printf("2. Search by age\n");
    printf("3. Search by grade\n");
    printf("4. Sort elements\n");
    printf("5. Insert student at start\n");
    printf("6. Insert student at end\n");
    printf("7. Insert grade at position for a student\n");
    printf("8. Delete grade at position for a student\n");
    printf("9. Print student list\n");
    printf("10. Exit\n");
    printf("Enter choice: ");
}

int get_student_position(StudentArray *student_array) {
    assert(student_array);
    char buffer[MAX_STRING_SIZE];
    printf("Enter student position to modify (1 to %d): ", student_array->size);
    int student_index = safe_scanf(buffer,GRADE_NUMBER_LIMIT);
    if (student_index < 1 || student_index > student_array->size) {
        printf(POSITION_ERROR);
        return POSITION_ERROR_CODE;
    }
    return student_index;
}

int get_grade_position(Student *student) {
    assert(student);
    char buffer[MAX_STRING_SIZE];
    printf("Enter grade position to modify (1 to %d): ", student->grades.size + 1);
    int new_position = safe_scanf(buffer,GRADE_NUMBER_LIMIT);
    if (new_position < 1 || new_position > student->grades.size + 1) {
        printf(POSITION_ERROR);
        return POSITION_ERROR_CODE;
    }
    if (student->grades.size == 0) {
        printf("No grades to delete.\n");
        return POSITION_ERROR_CODE;
    }
    return new_position;
}

void _realloc_student_array(StudentArray *student_array) {
    assert(student_array);
    Student *new_students = realloc(student_array->students, student_array->capacity * sizeof(Student));
    assert(new_students != NULL);
    student_array->students = new_students;
}

void _realloc_int_array(IntArray *grades) {
    assert(grades);
    int *new_array = realloc(grades->array, grades->capacity * sizeof(int));
    assert(new_array != NULL);
    grades->array = new_array;
}
