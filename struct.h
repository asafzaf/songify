#ifndef __STRUCT_H__
#define __STRUCT_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 1000
#define REMOVE_ENTER(c) (c) == '\n' ? (c) = '\0' : (c)

enum BOOL {FALSE, TRUE};
typedef struct song
{
    int ID;
    char* name;
    int length;
    int timePlayed;
    enum BOOL liked;
    struct song* next;
} song ;
/////////////////////////
typedef struct album
{
    char* name;
    song* songs;
    struct album* next;
} album ;
/////////////////////////
typedef struct activeYears
{
    int firstYear;
    int lastYear;
} activeYears ;

typedef struct artist
{
    char* name;
    struct activeYears active;
    album* albums;
    struct artist* next;
}artist;
/////////////////////////
typedef struct songify
{
    artist* artists;
} songify ;

#endif