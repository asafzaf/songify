#ifndef __ARTIST__
#define __ARTIST__

#ifndef __SONGIFY__
#include "songify.h"
#endif


album *find_album(album *head, const char *album_name);
void addAlbum(songify **artists);
void printAllAlbums(songify *artists);
#endif