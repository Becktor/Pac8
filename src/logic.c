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
/////
// Player Movement Left, Right, Up and Down
// mvinch returns the value at the given position
// check checks if player walks into a point and then increments the score
/////
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
/////
// Checks if Enemy walks into a point for point recreation
// when it leaves that pos again
/////
void enemyCoinCheck(Enemy * e){
    int x= e->x;
    int y= e->y;
    if(mvinch(y,x)=='O'){
        e->holdCoin=1;
    }else  e->holdCoin=0;
}

/////
// Enemy movement Left, Right, Up and Down
// Checks if it is on a point position if it is it redraws the point
// otherwise it moves the enemy
/////

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

//////
// This function checks the space between the player and enemy
// if it has a wall between them then the enemy will not notice
// or follow the player
/////
int obstructionCheck(int enemyPos, int playerPos, int xOrY,int def){
    if(enemyPos>playerPos && def == 0){
        for(int i = playerPos; i<enemyPos;i++){
            if(mvinch(xOrY, i) == '#') return 0;
        }
    }
    if(enemyPos>playerPos && def == 1){
        for(int i = playerPos; i<enemyPos;i++){
            if(mvinch(i,xOrY) == '#') return 0;
        }
    }
    if(playerPos>enemyPos && def == 0){
        for(int i = enemyPos; i<playerPos;i++){
            if(mvinch(xOrY, i) == '#') return 0;
        }
    }
    if(playerPos>enemyPos && def == 1){
        for(int i = enemyPos; i<playerPos;i++){
            if(mvinch(i,xOrY) == '#') return 0;
        }
    }
    return 1;
}

/////
// enemyCharge enables the enemy to charge the player if it has
// LOS(Line Of Sight), when enemy charges it will move one direction
// until it reaches a wall or the player.
/////
void enemyCharge(Enemy * e, Player * p){
    int x1=e->x;
    int y1=e->y;
    int x2=p->x;
    int y2=p->y;
    int charge=0;
    if(DIST(x1,y1,x2,y2)<10){
        if(x1==x2){
            charge=obstructionCheck(y1,y2,x1,1);
            if(charge==1){
                e->charge=charge;
                if(y1>y2)e->dir=Up;
                else e->dir=Down;
            }
        }
        if(y1==y2){
            charge=obstructionCheck(y1,y2,x1,1);
            if(charge==1){
                charge=obstructionCheck(x1,x2,y1,0);
                e->charge=charge;
                if(x1>x2)e->dir=Left;
                else  e->dir=Right;
            }
        }
    }
}
/////
// enemyMove is the randomiser for the enemy movement
// and sets the enemy speed. We use the clock speed
// to determine it.
/////
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
