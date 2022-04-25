#ifndef __ALBUM__
#define __ALBUM__
#endif

#ifndef __SONGIFY__
#define __SONGIFY__
#include "struct.h"
#endif

album *addSong(songify *artists, song *newSong, album *TheAlbum, artist *TheArtist);
int numOfsongs(songify *artists);
int lenOfalbum(songify *artists);
song *find_song(album *head, const char *song_name);
album *album_existance(artist *artist, const char *album_name);