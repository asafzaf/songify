#ifndef __ARTIST__
#define __ARTIST__
#include "struct.h"
#include "artist.h"
#endif


void addSong(songify **artists, const char *theAlbum)
{
    artist *artist;
    album *curr_album;
    song *curr_song;
    song *new_song;
    char *song_name;
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
    curr_album = album_existance(artist, buff);
    if(curr_album == NULL){
        printf("Sorry, that album does not exist in our library\n");
        return;
    }

    curr_song = curr_album->songs;

    printf("Enter song name: ");
    fgets(buff,BUFSIZE,stdin);
    length = strlen(buff);
    REMOVE_ENTER(buff[length - 1]);
    if(!find_song(curr_album, buff)){
        printf("SONG ALREADY EXISTS!\n");
        return;
    }

    new_song = (song*)malloc(sizeof(song));
    if(!new_song){
        printf("OUT OF MEMORY\n");
        return;
    }

    song_name = (char*)malloc(strlen(buff)+1);
    if(!song_name){
        printf("OUT OF MEMORY\n");
        free(new_song);
        return;
    }
    strcpy(song_name,buff);

    new_song->liked = FALSE;
    new_song->timePlayed = 0;

    int len;
    printf("Enter song lengh: ");
    scanf("%d", &len);
    new_song->length = len;
    
    if( curr_song == NULL )
    {
        curr_song = new_song;
        printf("Song added!\n");
        return;
    }

    while( curr_song->next != NULL )
    {
        curr_song = curr_song->next;
    }

    curr_song = new_song;

    printf("Song added!\n");
    return ;
}

int numOfsongs(songify *artists, album *TheAlbum)
{
    int counter = 0;

    return counter;
}

int lenOfalbum(songify *artists, album *TheAlbum, artist *TheArtist)
{
    int sec_count = 0 ;

return sec_count;
}

artist *album_existance(artist *artist, const char *album_name)
{
    album *curr_album;

    curr_album = artist->albums; 
    while (curr_album != NULL)
    {
        if (!strcmp(curr_album->name, album_name))
        {
            return curr_album;
        }
        curr_album = curr_album->next;
    }

    return NULL;
}

album *find_song(album *head, const char *song_name){
    song *curr_song;

    curr_song = head->songs;
    while(curr_song != NULL){
        if(!strcmp(curr_song->name,song_name)){
            return curr_song;
        }
        curr_song = curr_song->next;
    }
    return NULL;
}