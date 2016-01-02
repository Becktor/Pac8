#include <stdio.h>
#include <stdlib.h>
#include "levelGen.h"
#include <ncurses.h>
#include "logic.h"
#include <unistd.h>
#include <time.h>

#define SIZE  6
#define INIT_Y 1
#define INIT_X 3
#define INIT_ENEMY_SPEED 5


int main (int argc, char **argv)
{
    srand(time(0));
    initscr();/* Start curses mode*/
    timeout(0);
    raw();/* Line buffering disabled*/
    keypad(stdscr, TRUE);/* We get F1, F2 etc..	*/
    noecho();/* Don't echo() while we do getch */
    curs_set(FALSE); // Don't display a cursor
    genLevel(SIZE);
    Player * p1=newPlayer(INIT_Y,INIT_X);
    Enemy * e1=newEnemy(8,51,INIT_ENEMY_SPEED,0);
    Enemy * e2=newEnemy(5,71,INIT_ENEMY_SPEED,0);
    int run=1;
    while(run){
        usleep(1);
        char c='R';
        c=getch();

        switch(c){
            mvprintw(p1->y, p1->x," ");
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
            break;
        case 'R':
            break;

        };


        enemyMove(e1);
        enemyCharge(e1,p1);
        //enemyMove(e2);
        //enemyCharge(e1,p1);
            refresh();


    };
    endwin();			/* End curses mode		  */
}
