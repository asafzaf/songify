#ifndef __SONGIFY__
#define __SONGIFY__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#ifndef __STRUCT_H__
#include "struct.h"
#endif


#ifndef __ARTIST__
#include "artist.h"
#endif

#ifndef __ALBUM__
#include "album.h"
#endif

#ifndef __SONG__
#include "song.h"
#endif


void set_activeTime(artist **artist);
artist *artist_existance(artist *head, const char *artist_name);
void addArtist(songify **artists);
#endif