#ifndef __ARTIST__
#define __ARTIST__
#endif

#ifndef __STRUCT_H__
#define __STRUCT_H__
#include "struct.h"
#endif

#ifndef __SONGIFY__
#define __SONGIFY__
#include "songify.h"
#endif


album *find_album(artist *head, const char *album_name);
void addAlbum(songify **artists);
void printAllAlbums(songify *artists, artist *artist);










