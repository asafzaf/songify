#ifndef __SONGIFY__
#define __SONGIFY__
#include "songify.h"
#endif

void addArtist(songify **artists)
{

    artist *new_artist;
    char *artist_name;
    char buff[BUFSIZE];
    char dump;
    int length;

     
    if (*artists == NULL) // if songify is undefined yet
    {
        *artists = (songify *)malloc(sizeof(songify));
        if (*artists == NULL)
        {
            printf("OUT OFF MEMORY\n");
            return;
        }
        (*artists)->artists = NULL;
        
    }

    new_artist = (artist *)malloc(sizeof(artist));
    if (new_artist == NULL)
    {
        printf("OUT OFF MEMORY\n");
        return;
    }
    getchar();// empting stdin
    printf("Enter artist name: ");
    fgets(buff, BUFSIZE, stdin);
    length = strlen(buff);
    REMOVE_ENTER(buff[length - 1]);
    
    if (artist_existance((*artists)->artists, buff))
    {
        printf("ARTIST ALREADY EXISTS\n\n");
        free(new_artist);
        return;
    }

    artist_name = (char *)malloc((strlen(buff) + 1));
    if (artist_name == NULL)
    {
        printf("OUT OFF MEMORY\n");
        free(new_artist);
    }
    strcpy(artist_name, buff);

    new_artist->name = artist_name;
    set_activeTime(&new_artist);
    new_artist->albums = NULL;
    new_artist->next = (*artists)->artists;
    (*artists)->artists = new_artist;
    
    printf("\n%s has been added to Songify!\n",
    (*artists)->artists->name);
}

artist *artist_existance(artist *head, const char *artist_name)
{
    artist *curr_artist;

    curr_artist = head; 
    while (curr_artist != NULL)
    {
        if (!strcmp(curr_artist->name, artist_name))
        {
            return curr_artist;
        }
        curr_artist = curr_artist->next;
    }

    return NULL;
}

void set_activeTime(artist **artist)
{
    unsigned int since, until;

    printf("Set active years:\n"
           "`````````````````\n"
           "Active Since: ");
    scanf("%d", &since);

    while (since < 1020 || since > 2022)
    {
        printf("INVALID YEAR\n");
        scanf("%d", &since);
    }

    printf("Until: ");
    scanf("%d", &until);
    
    while (until < since || until >2022)
    {
        printf("INVALID YEAR\n");
        scanf("%d", &until);
    }

    (*artist)->active.firstYear = since;
    (*artist)->active.lastYear = until;
    
}