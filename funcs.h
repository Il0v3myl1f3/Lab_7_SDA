#ifndef FUNCS_H
#define FUNCS_H
#include <stddef.h>

#include "structs.h"
void student_management_menu(StudentArray *student_array);

StudentArray *init_read_students();
void init_declarations(Student *student);
StudentArray *init_students_array();

void _realloc_student_array(StudentArray *student_array);
void _realloc_int_array(IntArray *int_array);

void print_menu();
void print_students_list( StudentArray *student_array);
void print_sorting_criteria();
void print_student_info(StudentArray *student_array, int i);

void free_students_array(StudentArray *student_array);

int search_student_by_name( StudentArray *student_array, const char *target_name);
int search_student_by_age( StudentArray *student_array, int target_age);
int search_student_by_grade( StudentArray *student_array, int target_grade);

void insert_student_at_start(StudentArray *student_array);
void insert_student_at_end(StudentArray *student_array);

void insert_grade_at_any_position(StudentArray *student_array);
void delete_grade_at_any_position(StudentArray *student_array);

void bubble_sort_by_age(StudentArray *student_array);
void bubble_sort_by_name(StudentArray *student_array);
void sort_students_array(StudentArray *student_array, int criteria);

void check_students_array_size(StudentArray *student_array);
void check_grades_array_size(Student *student);

int get_student_position(StudentArray *student_array);
int get_grade_position(Student *student);
int get_new_grade();

char  *_read_student_name();
int _read_student_age();
void _read_student_grades(Student *student);

void check_students_array_capacity(StudentArray *student_array);

int safe_scanf(char *buffer, int validation_number);
#endif //FUNCS_H
