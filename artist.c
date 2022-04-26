#include "artist.h"



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
    if(find_album(artist->albums, buff)){
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
    new_album->name = album_name;
    new_album->songs = NULL;
    new_album->next = artist->albums;
    artist->albums = new_album;

    printf("\n%s is about to relese a new album!\n"
           "\"%s\" is now available for pre-saving\n\n",artist->name, artist->albums->name);
}

album *find_album(album *head, const char *album_name){

    album *curr_album;
    curr_album = head;
    while(curr_album != NULL){
        if(!strcmp(curr_album->name,album_name)){
            return curr_album;
        }
        curr_album = curr_album->next;
    }
    return NULL;
}
void printAllAlbums(songify *artists)
{
    artist *artist_for_print;
    album *curr_album;
    char buff[BUFSIZE];
    int length;
    getchar();
    
    printf("Choose artist: ");
    fgets(buff,BUFSIZE,stdin);
    length = strlen(buff);
    REMOVE_ENTER(buff[length -1]);

    artist_for_print = artist_existance(artists->artists,buff);
    if(!artist_for_print){
        printf("Sorry, that artist does not exist in our library\n");
        return;
    }
printf("\t\t%s discography\n"
       "\t\t`````````````````````\n",artist_for_print->name);
    curr_album = artist_for_print->albums;
    while(curr_album != NULL){
        printf("\t\t| %-19s|\n", curr_album->name);
        curr_album = curr_album->next;
    }
    printf("\n\n");
}