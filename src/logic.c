#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "levelGen.h"
#include "entities.h"



void check(Player * p){
    if(mvinch(p->y,p->x)=='O') p->points=p->points+10;
    mvprintw(12,0,"Points: %i",p->points);
}

void playerMoveRight(Player * p)
{
    int x= p->x;
    int y= p->y;
    if(mvinch(y,x+2)!='#'){
        x=x+2;
        p->x=x;
        check(p);
        mvprintw(y, x-2," ");
        mvprintw(y, x, "8");
        refresh();
    }
}

void playerMoveLeft(Player * p){
    int x= p->x;
    int y= p->y;
    if(mvinch(y,x-2)!='#'){
        x=x-2;
        p->x=x;
        check(p);
        mvprintw(y, x+2," ");
        mvprintw(y, x, "8");
        refresh();
    }
}

void playerMoveUp(Player * p){
    int x= p->x;
    int y= p->y;
    if(mvinch(y-1,x)!='#'){
        y=y-1;
        p->y=y;
        check(p);
        mvprintw(y+1, x," ");
        mvprintw(y, x, "8");
        refresh();
    }
}

void playerMoveDown(Player * p){

    int x= p->x;
    int y= p->y;
    if(mvinch(y+1,x)!='#'){
        y=y+1;
        p->y=y;
        check(p);
        mvprintw(y-1, x," ");
        mvprintw(y, x, "8");
        refresh();
    }
}


void enemyMoveRight(Enemy * e)
{
    int x= e->x;
    int y= e->y;
    if(mvinch(y,x+2)!='#'){
        x=x+2;
        e->x=x;

        mvprintw(y, x-2," ");
        mvprintw(y, x, "X");
        refresh();
    }
}

void enemyMoveLeft(Enemy * e){
    int x= e->x;
    int y= e->y;
    if(mvinch(y,x-2)!='#'){
        x=x-2;
        e->x=x;

        mvprintw(y, x+2," ");
        mvprintw(y, x, "X");
        refresh();
    }
}

void enemyMoveUp(Enemy * e){
    int x= e->x;
    int y= e->y;
    if(mvinch(y-1,x)!='#'){
        y=y-1;
        e->y=y;

        mvprintw(y+1, x," ");
        mvprintw(y, x, "X");
        refresh();
    }
}

void enemyMoveDown(Player * e){

    int x= e->x;
    int y= e->y;
    if(mvinch(y+1,x)!='#'){
        y=y+1;
        e->y=y;

        mvprintw(y-1, x," ");
        mvprintw(y, x, "X");
        refresh();
    }
}

void enemyMove(Enemy * e){
    int tmp=rand()%4;

    switch(tmp){
    case 0:
        enemyMoveLeft(e);
        break;
    case 1:
        enemyMoveUp(e);
        break;
    case 2:
        enemyMoveDown(e);
        break;
    case 3:
        enemyMoveRight(e);
        break;

    };

}
