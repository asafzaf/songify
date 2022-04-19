#include <stdio.h>
#include <string.h>
#include "song.h"

typedef struct album
{
    char* name;
    song* songs;
    Album* next;
} Album ;

typedef struct artist
{
    char* name;
    struct activeYears active;
    Album* albums;
    Artist* next;
} Artist ;

typedef struct activeYears
{
    int firstYear;
    int lastYear;
} ActiveYears ;

