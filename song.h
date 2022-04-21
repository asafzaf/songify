//#ifndef __MASTEROFDEF__
//#define 
#include <stdio.h>
#include <string.h>
#define BUFSIZE 1024

void addTOfavorites(Songify *head, const char *Artistname, const char *Albumname, const char *Songname);
void playSong(Songify *head, Artist *theArtist, Album *theAlbum, Song *theSong);

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