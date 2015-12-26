#include <stdio.h>
#include <stdlib.h>
#include "levelGen.h"
#include <ncurses.h>
#include "logic.h"

#define SIZE  4
#define INIT_Y 1
#define INIT_X 3
#define INIT_POINT 0


int main (int argc, char **argv)
{
    initscr();/* Start curses mode*/
    raw();/* Line buffering disabled*/
    keypad(stdscr, TRUE);/* We get F1, F2 etc..	*/
    noecho();/* Don't echo() while we do getch */
    curs_set(FALSE); // Don't display a cursor
    Player * p1=newPlayer(INIT_Y,INIT_X,INIT_POINT);
    Enemy * e1=newEnemy(8,51,10);
    Enemy * e2=newEnemy(5,71,10);
    int run=1;
    genLevel(SIZE);

    while(run){

        char c=getch();
        switch(c){
        case 'a':
            playerMoveLeft(p1);
            break;
        case 'w':
            playerMoveUp(p1);
            break;
        case 's':
            playerMoveDown(p1);
            break;
        case 'd':
            playerMoveRight(p1);
            break;
        case 'b':
            run=0;
        };


        enemyMove(e1);
        enemyMove(e2);
            refresh();


    };
    endwin();			/* End curses mode		  */
}
