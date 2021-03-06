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
    initialize();

    printf("\n\nStarting tests now.\n");

    printf("\n\nTesting bounds of empty list.\n");
    testEmpty();
    printf("\n\nTesting Inserts\n");
    testInsert();
    printf("\n\nTesting Deletes\n");
    testDelete();
    printf("\n\nTesting for Leaks\n");
    soapyWater(); // test for leaks haha
    printf("\n\nNow Cleaning the table\n");
    cleanUp();

    printf("===============================");
    printf("\nProgram completed successfully.\n\tRyan Watkins\n");
    printf("===============================\n");

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
//      prints items in the list for visual verification [edit: for debugging]
void testSize()
{
    char *string;
    int size;

    printf("\nNow Testing List Size: \n");

    string = firstItem();
    size = 0;

    while (string != NULL)
    {
        //printf("%s\n", string);
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

    printf("\n Now testing search for items that should not be in the list...\n");

    for (count = 0; count < size; count++)
    {
        target = strings[count];
        result = search(target);

        if (result)
        {
            printf("Located: %s\n", target);
            failed++;
        }
        else
        {
            printf("Failed to locate: %s\n", target);
            passed++;
        }
    }
}

// testSearchT(int size, char* strings[]))
//      Verifies that a certain set of elements are in the list
void testSearchT(int size, char *strings[])
{
    char *target;
    
    Boolean result;

    int count;

    printf("\n Now Testing search for items in the list...\n");

    for(count = 0; count < size; count++)
    {
        target = strings[count];
        result = search(target);

        if(result)
        {
            printf("Located: %s\n", target);
            passed++;
        }
        else
        {
            printf("Failed to locate: %s\n", target);
            failed++;
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
        printf("Inserted: %s\n", insertions[count]);
        insert(insertions[count]);
        currSize++;
    }
    // search for items we inserted
    testSearchT(INS_SIZE, insertions);

    // search for items we did not insert
    testSearchF(1, emptyStrings);

    //verify
    testSize();
}

// testDelete()
//      tests deleting items from the list
void testDelete()
{
#define DEL_SIZE 3
    char *deletions[DEL_SIZE] = {"Item5", "Item3", "Item1"}; //deletes the first, middle, and last items
    char *stringsLeft[2] = {"Item4", "Item2"};

    int count;

    printf("Now Testing item deletions from the list...\n");

    for(count = 0; count < DEL_SIZE; count++)
    {
        printf("Deleted: %s\n", deletions[count]);
        delete(deletions[count]);

        currSize--;
    }
    // search for what is left in the list after deletion
    testSearchT(2, stringsLeft);
    // ensure the items we deleted are not in the list
    testSearchF(DEL_SIZE, deletions);

    //verify
    testSize();
}

// soapyWater() (named as such, because that's how you can test something for airtight-ness)
//      tests the list for any leaks through numerous inserts and deletes
void soapyWater()
{
#define ONE_MILLION_ITEMS 1000000 //Dr. Evil
    int count;

    char *bubbles[1] = {"bloop"};

    for(count = 0; count < ONE_MILLION_ITEMS; count++)
    {
        insert(bubbles[0]);

        currSize++;
    }
    //Locate bubbles then verify size
    testSearchT(1, bubbles);
    testSize();

    //pop (Read: Delete) all of the bubbles 
    
    for(count = 0; count < ONE_MILLION_ITEMS; count++)
    {
        delete(bubbles[0]);

        currSize--;
    }
}

// cleanUp() [... so much water... everywhere...]
//      frees up the entire table
void cleanUp()
{
    wipeTable();
    currSize = 0;
    testSize();

    printf("\n Test Results: \n---------------\n");
    printf("Number of Total Tests Ran: %d\n", passed+failed);
    printf("Number of Tests Passed: %d\n", passed);
    printf("Number of Tests Failed: %d\n", failed);
}