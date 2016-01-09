#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include "ncurses.h"
#include "../pac8.h"

int gg2 = 1;
int main (int argc, char **argv)
{
    srand(time(0));
    int game=1;
    setlocale(LC_ALL,"");
    initscr();/* Start curses mode*/
    while(game){
        game=pacGame();
    }
    clear();
    endwin(); // End curses mode
}
