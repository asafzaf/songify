#include "song.h"

void playSong(songify *head)
{
    artist *curr_artist;
    album *curr_album;
    song *curr_song;
    
    char buff[BUFSIZE];
    int length;
    fflush(stdin);
    printf("Enter artist name: ");
    fgets(buff,BUFSIZE,stdin);
   
    length = strlen(buff);
    REMOVE_ENTER(buff[length-1]);
    curr_artist = artist_existance(head->artists, buff);
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

    printf("Enter song name: ");
    fgets(buff,BUFSIZE,stdin);
    length = strlen(buff);
    REMOVE_ENTER(buff[length - 1]);
    curr_song = find_song(curr_album->songs, buff);
    if(curr_song == NULL){
        printf("Sorry, that song does not exist in our library\n");
        return;
    }

    printf("%s length:", curr_song->name);
    clock(curr_song->length,2);
    curr_song->timePlayed++;

    return;    
}

void addTOfavorites(songify *head)
{
    artist *curr_artist;
    album *curr_album;
    song *curr_song;
    
    char buff[BUFSIZE];
    int length;
    fflush(stdin);
    printf("Enter artist name: ");
    fgets(buff,BUFSIZE,stdin);
   
    length = strlen(buff);
    REMOVE_ENTER(buff[length-1]);
    curr_artist = artist_existance(head->artists, buff);
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

    printf("Enter song name: ");
    fgets(buff,BUFSIZE,stdin);
    length = strlen(buff);
    REMOVE_ENTER(buff[length - 1]);
    curr_song = find_song(curr_album->songs, buff);
    if(curr_song == NULL){
        printf("Sorry, that song does not exist in our library\n");
        return;
    }

    curr_song->liked = TRUE;
    printf("\n\"%s\" Was added to your favorits!\n",curr_song->name);

    return;
}