#ifndef SDB_H
#define SDB_H
#include "STD.h"
#include <stdint.h>

typedef struct SimpleDb
{
    uint32_t Student_ID;
    uint32_t Student_year;
    uint32_t Course1_ID;
    uint32_t Course1_grade;
    uint32_t Course2_ID;
    uint32_t Course2_grade;
    uint32_t Course3_ID;
    uint32_t Course3_grade;
} student;

// Function declarations for the project
void add_student(student s);
void remove_student(uint32_t id);
void update_student(student s);
student get_student(uint32_t id);
void print_students();
/*
This file defines a new data type student which represents a student in a simple database.
The student structure contains several fields, including Student_ID,
 Student_year, Course1_ID, Course1_grade, Course2_ID, Course2_grade, Course3_ID,
 and Course3_grade.
 These fields represent the student’s ID, year, and information about the courses they are taking.
The file also includes function declarations for adding, removing,
 updating, and retrieving students from the database,
 as well as a function for printing all students in the database.
Note that this file only contains the function declarations and data type definitions.
*/
#endif
