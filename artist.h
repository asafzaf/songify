#include <stdio.h>
#include <string.h>
#include "album.h"
#include "song.h"
#define BUFSIZE 1024

Artist addAlbum(Songify *artists, Artist *Artist, Album *newAlbum);
void printAllAlbums(Songify *artists, Artist *artist);


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

