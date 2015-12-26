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

typedef struct{
    int x;
    int y;
    int speed;
}Enemy;

Enemy * newEnemy(int y, int x, int speed){
    Enemy * enemy=(Enemy*)malloc(sizeof(Enemy));
    enemy->x=x;
    enemy->y=y;
    enemy->speed=speed;
    return enemy;
}
