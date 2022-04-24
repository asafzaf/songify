
#include <string.h>
#include <stdio.h>
#ifndef __STRUCT_H__
#define __STRUCT_H__
#include "struct.h"
#endif


void set_activeTime(artist **artist);
artist *artist_existance(artist *head, const char *artist_name);
void addArtist(songify **artists);