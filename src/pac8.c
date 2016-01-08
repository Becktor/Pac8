#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <time.h>
#include "levelGen.h"
#include "logic.h"

#define SIZE  4
#define INIT_Y 1
#define INIT_X 3
#define INIT_ENEMY_SPEED 20
#define AMOUNT_OF_ENEMIES 3

int pacGame(){

    Enemy * enemies[AMOUNT_OF_ENEMIES];
    timeout(0);
    raw();/* Line buffering disabled*/
    keypad(stdscr, TRUE);/* We get F1, F2 etc..	*/
    noecho();/* Don't echo() while we do getch */
    curs_set(FALSE); // Don't display a cursor
    Level * lvl=newLevel(0);
    Player * p1=newPlayer(INIT_Y,INIT_X);
    Enemy * e1=newEnemy(8,51,INIT_ENEMY_SPEED,0);
    Enemy * e2=newEnemy(5,71,INIT_ENEMY_SPEED,0);
    Enemy * e3=newEnemy(1,21,INIT_ENEMY_SPEED,0);
    enemies[0]=e1;
    enemies[1]=e2;
    enemies[2]=e3;

    lvl->points=genLevel(SIZE);

    while(lvl->game){
        usleep(1);

        moveAll(enemies,p1,lvl);

        if(p1->points>=lvl->points*10) lvl->game=0;
        mvprintw(12,0,"Points: %i",p1->points);
        mvprintw(14,0,"Move with A S W D collect the points and avoid the X");
        mvprintw(16,0,"Restart with B %i",enemies[0]->x);
        refresh();
    };
    //Free memory
    free(p1);
    free(e1);
    free(e2);
    free(e3);
    erase();
    refresh();
    move(0,0);
    mvprintw(4,15,"Game Over");
    mvprintw(6,0,"Pres q to quit or any other to play again");
    refresh();
    sleep(0.5);
    char g = getchar();
    switch(g){
    case 'q':
        return 0;
        erase();
        break;
    default:
        move(0,0);
        refresh();
    }
    return 1;
}
