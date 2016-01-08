#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "ncurses.h"

void throwError(char * errorMsg){
    endwin(); // End curses mode
    printf("%s\n",errorMsg);
    exit(1);
}
