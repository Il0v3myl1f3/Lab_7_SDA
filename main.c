#include <stdio.h>
#include <stdlib.h>

#include "funcs.h"
#include "structs.h"

int main(void) {
    StudentArray *student_array = NULL;
    int input;
    do {
        char buffer[MAX_STRING_SIZE];
        print_menu();
        int validation_number = 2;
        input = safe_scanf(buffer, validation_number);
        if(input == INPUT_ERROR_CODE){
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
                int criteria = safe_scanf(sort_buffer, SORINTG_NUMBER_LIMIT);
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
    return 0;

}
