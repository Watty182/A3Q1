#ifndef _TABLE_H
#define _TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// defines Boolean to either false or true
typedef enum BOOL {false, true} Boolean;

//==============================================================
// Prototypes
//==============================================================

Boolean search(const char *);
Boolean insert(char const*);
Boolean delete(const char *);
void wipeTable(void);
char * firstItem(void);
char * nextItem(void);

#endif