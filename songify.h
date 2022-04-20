#include <stdio.h>
#include <string.h>
#include "song.h"
#include "artist.h"
#define BUFSIZE 1024

Songify addArtist(Songify *artists, Artist *newArtist);

typedef struct songify
{
    Artist* artists;
} Songify ;