#ifndef FUNCS_H
#define FUNCS_H

#include "structs.h"

/**
 * Displays the main student management menu and handles user input.
 * @param student_array Pointer to the array of students.
 */
void student_management_menu(StudentArray *student_array);

/**
 * Securely scans and validates user input.
 * @param value Character buffer to store input.
 * @param validation_number Maximum allowed length of input.
 * @return Valid integer input or an error code.
 */
int safe_scanf(int *value,int validation_number);

/**
 * Reads and validates a student’s age from user input.
 * @return The valid student age.
 */
int _read_student_age(void);
int get_grade_position_for_insertion(Student *student);
/**
 * Reads and validates a student’s grade from user input.
 * @return The valid grade entered by the user.
 */
int _read_student_grade(void);

/**
 * Reads and stores grades for a student.
 * @param student Pointer to a Student structure.
 */
void _read_student_grades(Student *student);

/**
 * Reads and allocates memory for a student name.
 * @return Pointer to the allocated student name string.
 */
char *_read_student_name(void);

/**
 * Reads complete student information (name, age, grades) from user input.
 * @param student Pointer to a Student structure.
 */
void read_student_info(Student *student);

/**
 * Allocates memory for a StudentArray and initializes its attributes.
 * @return Pointer to a newly allocated StudentArray.
 */
StudentArray *init_students_array(void);

/**
 * Initializes default values for a Student structure and reads its information.
 * @param student Pointer to a Student structure.
 */
void init_declarations(Student *student);

/**
 * Checks if the student array needs resizing and resizes if necessary.
 * Increments the student count after checking capacity.
 * @param student_array Pointer to a StudentArray structure.
 */
void check_students_array_size(StudentArray *student_array);

/**
 * Inserts a student at the beginning of the student array.
 * @param student_array Pointer to a StudentArray structure.
 */
void insert_student_at_start(StudentArray *student_array);

/**
 * Inserts a student at the end of the student array.
 * @param student_array Pointer to a StudentArray structure.
 */
void insert_student_at_end(StudentArray *student_array);

/**
 * Inserts a grade at any position for a specific student.
 * @param student_array Pointer to a StudentArray structure.
 */
void insert_grade_at_any_position(StudentArray *student_array);

/**
 * Deletes a grade at any position for a specific student.
 * @param student_array Pointer to a StudentArray structure.
 */
void delete_grade_at_any_position(StudentArray *student_array);

/**
 * Sorts students by name using the bubble sort algorithm.
 * @param student_array Pointer to a StudentArray structure.
 */
void bubble_sort_by_name(StudentArray *student_array);

/**
 * Sorts students by age using the bubble sort algorithm.
 * @param student_array Pointer to a StudentArray structure.
 */
void bubble_sort_by_age(StudentArray *student_array);

/**
 * Sorts students based on a selected criteria.
 * @param student_array Pointer to a StudentArray structure.
 * @param criteria Sorting criteria (e.g., bubble sort by name or age).
 */
void sort_students_array(StudentArray *student_array, int criteria);

/**
 * Frees all dynamically allocated memory in a StudentArray.
 * @param student_array Pointer to a StudentArray structure.
 */
void free_students_array(StudentArray *student_array);

/**
 * Prints the sorting criteria options for student sorting.
 */
void print_sorting_criteria(void);

/**
 * Checks if the grade array for a student needs resizing and resizes if necessary.
 * @param student Pointer to a Student structure.
 */
void check_grades_array_size(Student *student);

/**
 * Prints the detailed information of a specific student.
 * @param student_array Pointer to a StudentArray structure.
 * @param i Index of the student in the array.
 */
void print_student_info(StudentArray *student_array, int i);

/**
 * Prints the list of all students.
 * @param student_array Pointer to a StudentArray structure.
 */
void print_students_list(StudentArray *student_array);

/**
 * Searches for a student by name.
 * @param student_array Pointer to a StudentArray structure.
 * @param target_name Name of the student to search for.
 * @return Index of the student if found, otherwise an error code.
 */
int search_student_by_name(StudentArray *student_array, const char *target_name);

/**
 * Searches for a student by age.
 * @param student_array Pointer to a StudentArray structure.
 * @param target_age Age of the student to search for.
 * @return Index of the student if found, otherwise an error code.
 */
int search_student_by_age(StudentArray *student_array, int target_age);

/**
 * Searches for a student by grade.
 * @param student_array Pointer to a StudentArray structure.
 * @param target_grade Grade to search for.
 * @return Index of the student if found, otherwise an error code.
 */
int search_student_by_grade(StudentArray *student_array, int target_grade);

/**
 * Prints the main menu options.
 */
void print_menu(void);

/**
 * Retrieves a student’s position from user input.
 * @param student_array Pointer to a StudentArray structure.
 * @return Position of the student, or an error code if invalid.
 */
int get_student_position(StudentArray *student_array);

/**
 * Retrieves a grade’s position from user input.
 * @param student Pointer to a Student structure.
 * @return Position of the grade, or an error code if invalid.
 */
int get_grade_position(Student *student);

/**
 * Reallocates memory for the student array when capacity is exceeded.
 * @param student_array Pointer to a StudentArray structure.
 */
void _realloc_student_array(StudentArray *student_array);

/**
 * Reallocates memory for the integer array of grades.
 * @param grades Pointer to an IntArray structure.
 */
void _realloc_int_array(IntArray *grades);

#endif // FUNCS_H
