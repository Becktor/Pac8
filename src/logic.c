#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "levelGen.h"
#include "entities.h"
#include <time.h>
#include <math.h>

#define DIST(x1,y1,x2,y2)  (sqrt(pow(x1-x2,2)+pow(y1-y2,2)))
enum {Left=0, Up=1, Down=2, Right=3};
void check(Player * p){
    if(mvinch(p->y,p->x)=='O') p->points=p->points+10;
    mvprintw(12,0,"Points: %i",p->points);
}

void playerMoveRight(Player * p)
{
    int x= p->x;
    int y= p->y;
    if(mvinch(y,x+2)!='#'){
        mvprintw(y,x," ");
        x=x+2;
        p->x=x;
        check(p);

        mvprintw(y, x, "8");
        refresh();
    }
}

void playerMoveLeft(Player * p){
    int x= p->x;
    int y= p->y;
    if(mvinch(y,x-2)!='#'){
        mvprintw(y,x," ");
        x=x-2;
        p->x=x;
        check(p);

        mvprintw(y, x, "8");
        refresh();
    }
}

void playerMoveUp(Player * p){
    int x= p->x;
    int y= p->y;
    if(mvinch(y-1,x)!='#'){
        mvprintw(y,x," ");
        y=y-1;
        p->y=y;
        check(p);

        mvprintw(y, x, "8");
        refresh();
    }
}

void playerMoveDown(Player * p){

    int x= p->x;
    int y= p->y;
    if(mvinch(y+1,x)!='#'){
        mvprintw(y,x," ");
        y=y+1;
        p->y=y;
        check(p);

        mvprintw(y, x, "8");
        refresh();
    }
}

void enemyCoinCheck(Enemy * e){
    int x= e->x;
    int y= e->y;
    if(mvinch(y,x)=='O'){
        e->holdCoin=1;
    }else  e->holdCoin=0;
}


void enemyMoveRight(Enemy * e)
{
    int x= e->x;
    int y= e->y;
    if(mvinch(y,x+2)!='#'){
        if(e->holdCoin==1)  mvprintw(y, x, "O");
        else mvprintw(y,x," ");

        x=x+2;
        e->x=x;
        enemyCoinCheck(e);
        e->dir=Right;
        mvprintw(y, x, "X");
        refresh();
    }else{
        e->charge=0;
    }
}

void enemyMoveLeft(Enemy * e){
    int x= e->x;
    int y= e->y;
    if(mvinch(y,x-2)!='#'){
        if(e->holdCoin==1)  mvprintw(y, x, "O");
        else mvprintw(y,x," ");

        x=x-2;
        e->x=x;
        enemyCoinCheck(e);
        e->dir=Left;
        mvprintw(y, x, "X");
        refresh();
    }else{
        e->charge=0;
    }
}

void enemyMoveUp(Enemy * e){
    int x= e->x;
    int y= e->y;
    if(mvinch(y-1,x)!='#'){
        if(e->holdCoin==1)  mvprintw(y, x, "O");
        else mvprintw(y,x," ");

        y=y-1;
        e->y=y;
        enemyCoinCheck(e);
        e->dir=Up;
        mvprintw(y, x, "X");
        refresh();
    }else{
        e->charge=0;
    }
}

void enemyMoveDown(Enemy * e){

    int x= e->x;
    int y= e->y;
    if(mvinch(y+1,x)!='#'){
        if(e->holdCoin==1)  mvprintw(y, x, "O");
        else mvprintw(y,x," ");
        y=y+1;
        e->y=y;
        enemyCoinCheck(e);
        e->dir=Down;
        mvprintw(y, x, "X");
        refresh();
    }else{
        e->charge=0;
    }

}

void enemyCharge(Enemy * e, Player * p){
    int x1=e->x;
    int y1=e->y;
    int x2=p->x;
    int y2=p->y;
    if(DIST(x1,y1,x2,y2)<10){
        if(x1==x2){
            e->charge=1;

            if(y1>y2)e->dir=Up;
            else e->dir=Down;
            mvprintw(15,0,"mound %i % i",e->charge, e->dir);
        }
        if(y1==y2){
            e->charge=1;

            if(x1>x2)e->dir=Left;
            else  e->dir=Right;
            mvprintw(15,0,"found %i % i",e->charge, e->dir);
        }
    }
}

void enemyMove(Enemy * e){
    int tmp = 5;
    float curT = (float) clock()/ 1000000.0F;
    //mvprintw(16,0,"%f %f",e->lastMove, curT);
    if(e->lastMove+e->speed<curT) {
        e->lastMove=curT;
        tmp=rand()%4;
        if(e->charge==1){
            tmp=e->dir;
        }
    }


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
    case 5:
        break;
    };



}
