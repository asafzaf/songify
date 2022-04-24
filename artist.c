#ifndef __ARTIST__
#define __ARTIST__
#include "artist.h"
#endif


void addAlbum(songify **artists)
{
    artist *artist;
    album *new_album;
    char *album_name;
    char buff[BUFSIZE];
    int length;
    fflush(stdin);
    printf("Enter artist name: ");
    fgets(buff,BUFSIZE,stdin);
   
    length = strlen(buff);
    REMOVE_ENTER(buff[length-1]);
    artist = artist_existance((*artists)->artists, buff);
    if(artist == NULL){
        printf("Sorry, that artist does not exist in our library\n");
        return;
    }

    printf("Enter album name: ");
    fgets(buff,BUFSIZE,stdin);
    length = strlen(buff);
    REMOVE_ENTER(buff[length - 1]);
    if(!find_album(artist, buff)){
        printf("ALBUM ALREADY EXISTS!\n");
        return;
    }
    new_album = (album*)malloc(sizeof(album));
    if(!new_album){
        printf("OUT OFF MEMORY\n");
        return;
    }
    album_name = (char*)malloc(strlen(buff)+1);
    if(!album_name){
        printf("OUT OFF MEMORY\n");
        free(new_album);
        return;
    }
    strcpy(album_name,buff);
    artist->name = album_name;
}

album *find_album(artist *head, const char *album_name){

    album *curr_album;
    curr_album = head->albums;
    while(curr_album != NULL){
        if(!strcmp(curr_album->name,album_name)){
            return curr_album;
        }
        curr_album = curr_album->next;
    }
    return NULL;
}
void printAllAlbums(songify *artists, artist *artist)
{

}