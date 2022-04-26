#include "album.h"
#include <stdio.h>

void addSong(songify **artists) {
  artist *artist;
  album *curr_album;
  song *new_song;
  char *song_name;
  char buff[BUFSIZE];
  unsigned int count;
  int length;

  getchar();

  printf("Enter artist name: ");
  fgets(buff, BUFSIZE, stdin);

  length = strlen(buff);
  REMOVE_ENTER(buff[length - 1]);
  artist = artist_existance((*artists)->artists, buff);
  if (artist == NULL) {
    printf("Sorry, that artist does not exist in our library\n");
    return;
  }

  printf("Enter album name: ");
  fgets(buff, BUFSIZE, stdin);
  length = strlen(buff);
  REMOVE_ENTER(buff[length - 1]);
  curr_album = find_album(artist->albums, buff);
  if (curr_album == NULL) {
    printf("Sorry, that album does not exist in our library\n");
    return;
  }
  printf("How many songs to be added?: ");
  scanf("%d",&count);
getchar();
if(!count)
    return;

for(int i = 0 ; i < count ; i++ ){

  printf("Enter song name: ");
  fgets(buff, BUFSIZE, stdin);
  length = strlen(buff);
  REMOVE_ENTER(buff[length - 1]);
  if (find_song(curr_album->songs, buff)) {
    printf("SONG ALREADY EXISTS!\n");
    return;
  }

  new_song = (song *)malloc(sizeof(song));
  if (!new_song) {
    printf("OUT OF MEMORY\n");
    return;
  }

  song_name = (char *)malloc(strlen(buff) + 1);
  if (!song_name) {
    printf("OUT OF MEMORY\n");
    free(new_song);
    return;
  }

  strcpy(song_name, buff);
  new_song->name = song_name;
  new_song->liked = FALSE;
  new_song->timePlayed = 0;

  printf("Enter song lengh: ");
  scanf("%d", &new_song->length);
  getchar();
  new_song->next = curr_album->songs;
  curr_album->songs = new_song;

  printf("The song \"%s\" was added to the album!\n", curr_album->songs->name);

}
  return;
}

int numOfsongs(songify *artists) {
  int counter = 0;
  artist *curr_artist;
  album *curr_album;
  song *curr_song;

  char buff[BUFSIZE];
  int length;
  fflush(stdin);
  printf("Enter artist name: ");
  fgets(buff, BUFSIZE, stdin);

  length = strlen(buff);
  REMOVE_ENTER(buff[length - 1]);
  curr_artist = artist_existance(artists->artists, buff);
  if (curr_artist == NULL) {
    printf("Sorry, that artist does not exist in our library\n");
    return FALSE;
  }

  printf("Enter album name: ");
  fgets(buff, BUFSIZE, stdin);
  length = strlen(buff);
  REMOVE_ENTER(buff[length - 1]);
  curr_album = find_album(curr_artist->albums, buff);
  if (curr_album == NULL) {
    printf("Sorry, that album does not exist in our library\n");
    return FALSE;
  }

  curr_song = curr_album->songs;
  while (curr_song != NULL) {
    ++counter;
    curr_song = curr_song->next;
  }

  return counter;
}

int lenOfalbum(songify *artists) {
  int timer = 0;
  artist *curr_artist;
  album *curr_album;
  song *curr_song;

  char buff[BUFSIZE];
  int length;
  fflush(stdin);
  printf("Enter artist name: ");
  fgets(buff, BUFSIZE, stdin);

  length = strlen(buff);
  REMOVE_ENTER(buff[length - 1]);
  curr_artist = artist_existance(artists->artists, buff);
  if (curr_artist == NULL) {
    printf("Sorry, that artist does not exist in our library\n");
    return FALSE;
  }
  printf("Enter album name: ");
  fgets(buff, BUFSIZE, stdin);
  length = strlen(buff);
  REMOVE_ENTER(buff[length - 1]);
  curr_album = find_album(curr_artist->albums, buff);
  if (curr_album == NULL) {
    printf("Sorry, that album does not exist in our library\n");
    return FALSE;
  }

  curr_song = curr_album->songs;
  while (curr_song != NULL) {
    timer += curr_song->length;
    curr_song = curr_song->next;
    printf("and here\n");
  }
 
  return timer;
}

song *find_song(song *head, const char *song_name) {
  song *curr_song;

  curr_song = head;
  while (curr_song != NULL) {
    if (!strcmp(curr_song->name, song_name)) {
      return curr_song;
    }
    curr_song = curr_song->next;
  }
  return NULL;
}
