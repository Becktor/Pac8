#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include "ncurses.h"
#include "../src/levelGen.h"
#include "../src/logic.h"
#include "../src/pac8.h"

void first_test()
{
    // will test if we can create a player with a negative coordinates
    int x = -1;
    int y = -1;
    Player * p = newPlayer(y,x);
}

void second_test(){ // check if player moves if he walks into a wall
    int x=1; // starting coordinates
    int y=1;
    int test=-1;
    Player * p = newPlayer(y,x);
    initscr();/* Start curses mode*/
    genLevel(test);
    playerMoveLeft(p); // player moves into a wall
    printw("test");
    //assert(p->x==x);
    move(1,10);
    mvprintw(1,1,"test");
    //assert(p->y==y);
    refresh();
    endwin(); // End curses mode
}

int main(){

    second_test();
    first_test();
}
