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
void testSize();

//Static Variables eg. test counters
static int passed;
static int failed;
static int currSize;

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

void initialize()
{
    passed = 0;
    failed = 0;
    currSize = 0;
}

// testSize():
//      starts a traversal through the list and verifies the size of the list is accurate
//      increments passed or failed to keep track of tests
//      prints items in the list for visual verification
void testSize()
{
    char *string;
    int size;

    printf("\nNow Testing List Size: \n");

    string = firstItem();
    size = 0;

    while (string != NULL)
    {
        size++;
        string = nextItem();
    }

    printf("The size of the list is: %d\n", size);

    if (currSize == size)
    {
        passed++;
    }
    else
    {
        failed++;
    }
}

// testEmpty():
//      tests to see if the list is empty
void testEmpty()
{
    char *empty[1] = {"Nobody Home"};

    testSearchF(1, empty);
    delete ("Node-less");

    testSize();
}

// testSearchF(int size, char* strings[]):
//      Verifies that a certain set of elements are not in the List

void testSearchF(int size, char *strings[])
{
    char *target;

    Boolean result;

    int count;

    printf("\n Now testing search for items that should not be in the list\n");

    for (count = 0; count < size; count++)
    {
        target = strings[i];
        result = search(target);

        if (result)
        {
            printf("located: %s\n", target);
            failed++;
        }
        else
        {
            printf("Failed to locate: %s\n", target);
            passed++;
        }
    }
}

// testInsert()
//      tests adding items to the list
void testInsert()
{
#define INS_SIZE 5
    char *insertions[INS_SIZE] = {"Item5", "Item4", "Item3", "Item2", "Item1"};
    char *emptyStrings[1] = {"MT"};

    int count;

    printf("\nNow Testing item insertions to the list...\n");

    for (count = 0; count < INS_SIZE; count++)
    {
        printf("Inserted: %s", insertions[count]);
        insert(insertions[count]);
        currSize++;
    }
    // search for items we inserted
    testSearchT(INS_SIZE, insertions);

    // search for items we did not insert
    testSearchFP(1, emptyStrings);

    //verify
    testSize();
}
