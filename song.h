//#ifndef __MASTEROFDEF__
//#define 
#include <stdio.h>
#include <string.h>
#define BUFSIZE 1024

enum bool {false, true};

typedef struct song
{
    int ID;
    char* name;
    int length;
    int timePlayed;
    enum bool liked;
    Song* next;
} Song ;