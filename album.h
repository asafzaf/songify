#ifndef __ALBUM__
#define __ALBUM__


#ifndef __SONGIFY__
#include "songify.h"
#endif

void clock(int seconds);
void addSong(songify **artists);
int numOfsongs(songify *artists);
int lenOfalbum(songify *artists);
song *find_song(song *head, const char *song_name);
album *album_existance(artist *artist, const char *album_name);
#endif