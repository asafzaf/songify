#include "song.h"
#include "songify.h"

Album *addSong(Songify *artists, Song *newSong, Album *TheAlbum, Artist *TheArtist);
int numOfsongs(Songify *artists, Album *TheAlbum);

typedef struct album
{
    char* name;
    Song* songs;
    Album* next;
} Album ;