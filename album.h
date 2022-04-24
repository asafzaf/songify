#include <stdio.h>
#include <string.h>

#ifndef __STRUCT_H__
#define __STRUCT_H__
#include "struct.h"
#endif

album *addSong(songify *artists, song *newSong, album *TheAlbum, artist *TheArtist);
int numOfsongs(songify *artists);
int lenOfalbum(songify *artists);
album *find_song(album *head, const char *song_name);
album *album_existance(artist *artist, const char *album_name);