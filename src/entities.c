#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
typedef struct{
    int x;
    int y;
    int points;
}Player;

Player * newPlayer(int y, int x, int points){
    Player *player=(Player*)malloc(sizeof(Player));
    player->x=x;
    player->y=y;
    player->points=points;
    return player;
}
