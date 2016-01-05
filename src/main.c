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
#define INIT_ENEMY_SPEED 5


int main (int argc, char **argv)
{
    srand(time(0));
    int game=1;
    while(game){
        initscr();/* Start curses mode*/
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
        lvl->points=genLevel(SIZE);

        while(lvl->game){
            usleep(1);
            char c='R';
            c=getch();
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
                lvl->game=0;
                break;
            case 'R':
                break;

            };

            enemyMove(e1);
            enemyCharge(e1,p1); // checks if e1 should charge
            if(lvl->game==1) lvl->game=playerCaught(e1,p1);
            enemyMove(e2);
            enemyCharge(e2,p1); // checks if e2 should charge
            if(lvl->game==1) lvl->game=playerCaught(e2,p1);
            enemyMove(e3);
            enemyCharge(e3,p1); // checks if e3 should charge
            if(lvl->game==1) lvl->game=playerCaught(e3,p1);


            if(p1->points>=lvl->points*10) lvl->game=0;
            mvprintw(12,0,"Points: %i",p1->points);
            mvprintw(14,0,"Move with A S W D collect the points and avoid the X");
            mvprintw(16,0,"Restart with B" );
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
        sleep(1);
        char g = getchar();
        switch(g){
        case 'q':
            game = 0;
            erase();
            break;
        default:
            move(0,0);
            refresh();
            break;
        }
    }
    clear();
    endwin(); // End curses mode
}
