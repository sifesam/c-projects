#include "SDB.h"// Include the header file for the student database
#include <stdio.h> // Include the standard input/output library
#include <stdbool.h>// Include the standard boolean library

#define MAX_STUDENTS 10// Define the maximum number of students in the database

static student students[MAX_STUDENTS]; // Declare an array of student structures to store the students in the database
static uint8_t num_students = 0; // Declare a variable to keep track of the number of students in the database

bool SDB_IsFull()// Function to check if the database is ful
{
    return num_students == MAX_STUDENTS;// Return true if the number of students is equal to the maximum size, false otherwise
}

uint8_t SDB_GetUsedSize()// Function to get the number of students currently in the database
{
    return num_students; // Return the number of students in the database
}

bool SDB_AddEntry()// Function to add a new student to the database
{
    if (SDB_IsFull())// Check if the database is full
    {
        printf("Error: Database is full\n"); // Print an error message
        return false; // Return false to indicate that the student could not be added
    }

    student s; // Declare a student structure to store the new student's information
    printf("Enter student ID: ");
    scanf("%u", &s.Student_ID);
    printf("Enter student year: ");
    scanf("%u", &s.Student_year);
    printf("Enter Course1 ID: ");
    scanf("%u", &s.Course1_ID);
    printf("Enter Course1 grade: ");
    scanf("%u", &s.Course1_grade);
    printf("Enter Course2 ID: ");
    scanf("%u", &s.Course2_ID);
    printf("Enter Course2 grade: ");
    scanf("%u", &s.Course2_grade);
    printf("Enter Course3 ID: ");
    scanf("%u", &s.Course3_ID);
    printf("Enter Course3 grade: ");
    scanf("%u", &s.Course3_grade);

    students[num_students++] = s;
    return true;
}

void SDB_DeleteEntry(uint32_t id)// Function to delete a student from the database based on their ID
{
    for (uint8_t i = 0; i < num_students; i++) // Loop through all students in the database
    {
        if (students[i].Student_ID == id)// Check if the current student's ID matches the given ID
        {
            for (uint8_t j = i; j < num_students - 1; j++) // Shift all students after the current student one position to the left
            {
                students[j] = students[j + 1];// Decrement the number of students in the database
            }
            num_students--;
            return;// Return from the function
        }
    }
}

bool SDB_ReadEntry(uint32_t id)// Function to print information about a student based on their ID
{
    for (uint8_t i = 0; i < num_students; i++)// Loop through all students in the database
    {
        if (students[i].Student_ID == id) // Check if the current student's ID matches the given ID
        {
            student s = students[i]; // Get a reference to the current student
            printf("Student ID: %u\n", s.Student_ID);
            printf("Student year: %u\n", s.Student_year);
            printf("Course1 ID: %u\n", s.Course1_ID);
            printf("Course1 grade: %u\n", s.Course1_grade);
            printf("Course2 ID: %u\n", s.Course2_ID);
            printf("Course2 grade: %u\n", s.Course2_grade);
            printf("Course3 ID: %u\n", s.Course3_ID);
            printf("Course3 grade: %u\n", s.Course3_grade);
            return true;
        }
    }
    return false; // Return false to indicate that the student was not found
}

void SDB_GetList(uint8_t *count, uint32_t *list)
{
    *count = num_students;
    for (uint8_t i = 0; i < num_students; i++)
    {
        list[i] = students[i].Student_ID;
    }
}

bool SDB_IsIdExist(uint32_t id)
{
    for (uint8_t i = 0; i < num_students; i++)
    {
        if (students[i].Student_ID == id)
        {
            return true;
        }
    }
    return false;
}
