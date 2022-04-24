#include "struct.h"
#ifndef __ARTIST__
#define __ARTIST__
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
    curr_album = find_album(artist, buff);
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
    artist *curr_artist;
    album *curr_album;
    
    char buff[BUFSIZE];
    int length;
    fflush(stdin);
    printf("Enter artist name: ");
    fgets(buff,BUFSIZE,stdin);
   
    length = strlen(buff);
    REMOVE_ENTER(buff[length-1]);
    curr_artist = artist_existance(artists, buff);
    if(curr_artist == NULL){
        printf("Sorry, that artist does not exist in our library\n");
        return;
    }
    
    printf("Enter album name: ");
    fgets(buff,BUFSIZE,stdin);
    length = strlen(buff);
    REMOVE_ENTER(buff[length - 1]);
    curr_album = find_album(curr_artist->albums, buff);
    if(curr_album == NULL){
        printf("Sorry, that album does not exist in our library\n");
        return;
    }

    song *curr_song = curr_album->songs;
    if(curr_song == NULL){
        printf("This album has no songs!\n");
        return counter;
    }
    ++counter;

    while( curr_song->next != NULL )
    {
        ++counter;
        curr_song = curr_song->next;
    }

    return counter;
}

int lenOfalbum(songify *artists)
{
    int timer = 0;
    artist *curr_artist;
    album *curr_album;
    
    char buff[BUFSIZE];
    int length;
    fflush(stdin);
    printf("Enter artist name: ");
    fgets(buff,BUFSIZE,stdin);
   
    length = strlen(buff);
    REMOVE_ENTER(buff[length-1]);
    curr_artist = artist_existance(artists, buff);
    if(curr_artist == NULL){
        printf("Sorry, that artist does not exist in our library\n");
        return;
    }
    
    printf("Enter album name: ");
    fgets(buff,BUFSIZE,stdin);
    length = strlen(buff);
    REMOVE_ENTER(buff[length - 1]);
    curr_album = find_album(curr_artist->albums, buff);
    if(curr_album == NULL){
        printf("Sorry, that album does not exist in our library\n");
        return;
    }

    song *curr_song = curr_album->songs;
    if(curr_song == NULL){
        printf("This album has no songs!\n");
        return timer;
    }

    timer += curr_song->length;

    while( curr_song->next != NULL )
    {
        curr_song = curr_song->next;
        timer += curr_song->length;
    }
    
    return timer;

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