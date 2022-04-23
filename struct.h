
enum BOOL {FALSE, TRUE};
typedef struct song
{
    int ID;
    char* name;
    int length;
    int timePlayed;
    enum BOOL liked;
    struct song* next;
} song ;
/////////////////////////
typedef struct album
{
    char* name;
    song* songs;
    struct album* next;
} album ;
/////////////////////////
typedef struct activeYears
{
    int firstYear;
    int lastYear;
} activeYears ;

typedef struct artist
{
    char* name;
    struct activeYears active;
    album* albums;
    struct artist* next;
}artist;
/////////////////////////
typedef struct songify
{
    artist* artists;
} songify ;
