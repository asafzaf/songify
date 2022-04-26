#include "songify.h"

int main()
{
    songify *system = NULL;
    int song_number;
    int album_length;

    

    unsigned int choice;
    for (;;)
    {
        printf("\t\t   Make a choice!\n"
               "\t\t  ~~~~~~~~~~~~~~~~\n\n"
               "\t1. Add artist\t\t2. Add an album\n"
               "\t3. Artist's albums\t4. Add song\n"
               "\t5. Song count\t\t6. Album's length\n"
               "\t7. Play song\t\t8. Add to favorits\n"
               "\n\t\t      9. Exit\n"
               "Choose: ");
        scanf("%d", &choice);
        while (choice > 9){
            printf("No such option, please try again:\n");
            scanf("%d",&choice);
        }
        switch (choice)
        {
        case 1:{
           addArtist(&system);
            break;
        }
        case 2:{
            addAlbum(&system);
            break;
        }
        case 3:{
            printAllAlbums(system);
            break;
        }
        case 4:{
            addSong(&system);
            break;
        }
        case 5:{
            song_number = numOfsongs(system);
            printf("There are %d songs in this album\n\n",song_number);
            break;
        }
        case 6:{
            album_length = lenOfalbum(system);
            printf("This album is %d seconds\n\n",album_length);
            break;
        }
        case 7:{
            playSong(system);
            break;    
        }
        case 8:{
            addTOfavorites(system);
            break;
        }
         case 9:{
            return 0;
            break;    
         }
        } // end of switch
    } // end of for

    return 0;
}
