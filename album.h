
#include <stdio.h>
#include <string.h>

#ifndef __STRUCT_H__
#define __STRUCT_H__
#include "struct.h"
#endif



album *addSong(songify *artists, song *newSong, album *TheAlbum, artist *TheArtist);
int numOfsongs(songify *artists,  const char *TheAlbum);
album *find_song(album *head, const char *song_name);

