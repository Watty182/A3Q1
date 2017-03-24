//-----------------------------------------
// NAME: Ryan Watkins
// STUDENT NUMBER: 7691844
// COURSE: COMP 2160, SECTION: A01
// INSTRUCTOR: Franklin Bristow
// ASSIGNMENT: 3, QUESTION: 1
// 
// REMARKS: This program extensively tests the implementation of table.c by utilizing table.h
//          as well as scaffolding
//-----------------------------------------
#include "table.h"

//Prototypes
void initialize();
void testEmpty();
void testInsert();
void testDelete();
void soapyWater();
void cleanUp();
void testSearchT(int size, char *strings[]);
void testSearchF(int size, char *strings[]);

//Static Variables eg. test counters

int main(int argc, char *argv[])
{
    initalize();

    printf("Starting tests now.\n\n");

    testEmpty();
    testInsert();
    testDelete();
    soapyWater(); // test for leaks haha

    cleanUp();

    printf("=================================");
    printf("\nProgram completed successfully.\n\t\tRyan Watkins\n");
    printf("=================================");

    return EXIT_SUCCESS;
}

//