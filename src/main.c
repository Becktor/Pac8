#include <stdlib.h>
#include <time.h>
#include "ncurses.h"
#include "pac8.h"

int main (int argc, char **argv)
{
    srand(time(0));
    int game=1;
    initscr();/* Start curses mode*/
    while(game){
        game=pacGame();
    }
    clear();
    endwin(); // End curses mode
}
