#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include "ncurses.h"
#include <locale.h>
#include "../src/levelGen.h"
#include "../src/logic.h"
#include "../src/pac8.h"

void first_test()
{
// will test if we can create a player with a negative coordinates
    int x = -1;
    int y = -1;
    printf("    initialize player with negative coordinates (-1,-1)\n");
    Player * p = newPlayer(y,x);
    printf("    player value is x: %i y: %i \n\n",p->x,p->y);
}

void second_test(){ // check if player moves if he walks into a wall

    int x=1; // starting coordinates
    int y=1;
    int test=-1;
    Player * p = newPlayer(y,x);
    setlocale(LC_ALL,"");
    initscr();/* Start curses mode*/
    genLevel(test);
    playerMoveLeft(p); // player moves into a wall
    assert(p->x==x);
    assert(p->y==y);
    refresh();
    endwin(); // End curses mode
}

void third_test_r(){ // check if player moves
    int x=2; // starting coordinates
    int y=2;
    int test=-1;
    Player * p = newPlayer(y,x);
    initscr();/* Start curses mode*/
    genLevel(test);
    playerMoveRight(p); // player moves right
    assert(p->x==x+1);
    assert(p->y==y);
    refresh();
    endwin(); // End curses mode
}
void third_test_l(){ // check if player moves
    int x=2; // starting coordinates
    int y=2;
    int test=-1;
    Player * p = newPlayer(y,x);
    initscr();/* Start curses mode*/
    genLevel(test);
    playerMoveLeft(p); // player moves right
    assert(p->x==x-1);
    assert(p->y==y);
    refresh();
    endwin(); // End curses mode
}
void third_test_u(){ // check if player moves
    int x=2; // starting coordinates
    int y=2;
    int test=-1;
    Player * p = newPlayer(y,x);
    initscr();/* Start curses mode*/
    genLevel(test);
    playerMoveUp(p); // player moves right
    assert(p->x==x);
    assert(p->y==y-1);
    refresh();
    endwin(); // End curses mode
}

void third_test_d(){ // check if player moves
    int x=2; // starting coordinates
    int y=2;
    int test=-1;
    Player * p = newPlayer(y,x);
    initscr();/* Start curses mode*/
    genLevel(test);
    playerMoveDown(p); // player moves right
    assert(p->x==x);
    assert(p->y==y+1);
    refresh();
    endwin(); // End curses mode
}


void fourth_test(){ // check if player moves into point and increments
    int x=3; // starting coordinates
    int y=4;
    int test=-1;
    Player * p = newPlayer(y,x);
    initscr();/* Start curses mode*/
    genLevel(test);
    playerMoveRight(p); // player moves
    assert(p->x==x+1);
    assert(p->points==10);
    refresh();
    endwin(); // End curses mode
}

void fifth_test(){ // check if player moves
    int x=1; // starting coordinates
    int y=1;
    int ex=2;
    int ey=1;
    int test=-1;
    Player * p = newPlayer(y,x);
    Enemy * e = newEnemy(ey,ex,0,0);
    initscr();/* Start curses mode*/
    genLevel(test);
    playerMoveRight(p); // player moves into a wall
    assert(playerCaught(e,p)==0);
    assert(p->x==e->x);
    assert(p->y==e->y);
    refresh();
    endwin(); // End curses mode
}

void sixth_test(){ // check if player moves into point and increments
    int ex=4;
    int ey=3;
    int x=3; // starting coordinates
    int y=4;
    int test=-1;
    Player * p = newPlayer(y,x);
    Enemy * e = newEnemy(ey,ex,0,0);
    initscr();/* Start curses mode*/
    genLevel(test);
    enemyMoveDown(e);
    playerMoveRight(p); // player moves into point and enemy
    assert(p->x==x+1);
    assert(p->points==0);
    assert(playerCaught(e,p)==0);
    refresh();
    endwin(); // End curses mode
}


int main(){
    printf("First Test \n");
    first_test();

    printf("Second Test \n");
    printf("    Try to move player into wall\n");
    second_test();
    printf("    Player has same position\n\n");

    printf("Third Test \n");
    printf("    Move player to the right\n");
    third_test_r();
    printf("    Player moved to the right\n\n");
    printf("    Move player to the left\n");
    third_test_l();
    printf("    Player moved to the left\n\n");
    printf("    Move player to the upwards\n");
    third_test_u();
    printf("    Player moved to the upwards\n\n");
    printf("    Move player to the downwards\n");
    third_test_d();
    printf("    Player moved to the downwards\n\n");

    printf("Fourth Test \n");
    printf("    Move player into a point\n");
    fourth_test();
    printf("    Player moved and point was incremented\n\n");

    printf("Fifth Test \n");
    printf("    Move player into enemy\n");
    fifth_test();
    printf("    Player was caught\n\n");

    printf("Sixth Test \n");
    printf("    Move player into enemy and point\n");
    sixth_test();
    printf("    Player was caught\n\n");

}
