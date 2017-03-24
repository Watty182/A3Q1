#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef enum BOOL { false,
                    true } Boolean;

// Linked list node definition
typedef struct NODE Node;

struct NODE
{
    char *string;
    Node *next;
};

static Node *top = NULL;
static int numNodes = 0;

// used to track where we are for the list traversal methods
static Node *traverseNode = NULL;

int size()
{
    assert(numNodes != NULL);
    return numNodes;
}

// add an element to the beginning of the linked list
Boolean insert(char const *const new_string)
{
    Boolean rc = true;
    Node *newNode = NULL;

#ifndef NDEBUG
    assert(NULL != new_string);
    assert(strcmp("", new_string) != 0); // ensures the string inserted will not be NULL
#endif

    if (new_string != NULL && strcmp("", new_string) != 0)
    {
        newNode = (Node *)malloc(sizeof(Node));

#ifndef NDEBUG
        assert(newNode != NULL);
#endif

        if (newNode != NULL)
        {
            newNode->next = top;
            top = newNode;

            // note that we need to have space for the string as well!
            newNode->string = (char *)malloc(strlen(new_string) + 1);

#ifndef NDEBUG
            assert(newNode->string != NULL);
#endif

            if (newNode->string != NULL)
            {
                strcpy(newNode->string, new_string);
                numNodes++;
            }
        }
    }
    else
    {
        rc = false;
    }

    return rc;
}

// remove an element with the given string
Boolean delete (char const *const target)
{
    Boolean deleted = false;
    Node *curr = top;

#ifndef NDEBUG
    assert(curr != NULL);
#endif

    Node *prev = NULL;
#ifndef NDEBUG
    assert(target != NULL);
    assert(strcmp("", target) != 0);
#endif

    if (target != NULL && strcmp("", target) != 0)
    {
        while (curr != NULL && strcmp(target, curr->string) != 0)
        {
            prev = curr;
            curr = curr->next;
        }

        if (curr != NULL)
        {
            if (prev != NULL)
                prev->next = curr->next;
            else
                top = curr->next;

            free(curr->string);
            free(curr);
            deleted = true;
            numNodes--;
        }
    }
    return deleted;
}

// tells us whether or not the given string is in the list
Boolean search(char const *const target)
{
    Boolean found = false;
    Node *curr = top;

    if (curr != NULL && target != NULL)
    {
#ifndef NDEBUG
        assert(curr != NULL);
        assert(target != NULL);
#endif

        while (curr != NULL && !found)
        {
#ifndef NDEBUG
            assert(curr->string != NULL);
#endif
            if (strcmp(target, curr->string) == 0)
            {
                found = true;
            }

            else
            {
                curr = curr->next;
            }
        }

        return found;
    }

    // starts a list traversal by getting the data at top
    char *firstItem()
    {
        traverseNode = top->next;

        return top->string;
    }

    // gets the data at the current traversal node and increments the traversal
    char *nextItem()
    {
        char *item = NULL;

        // no need to go past the end of the list...
        if (traverseNode != NULL)
        {
            item = traverseNode->string;
            traverseNode = traverseNode->next;
        }

        return item;
    }
