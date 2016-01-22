#include <stdio.h>
#include <stdlib.h>
#include "error.h"
typedef struct{
    int x;
    int y;
    int points;
}Player;

Player * newPlayer(int y, int x){
    Player *player=(Player*)malloc(sizeof(Player));
    if (player == NULL) {
        throwError("malloc failed");
    }if(x<0 || y<0) {
        player->x=1;
        player->y=1;
    }else{
        player->x=x;
        player->y=y;
    }
    player->points=0;
    return player;
}

typedef struct{
    int x;
    int y;
    float speed;
    int holdCoin;
    float lastMove;
    int charge;
    int dir;
}Enemy;

Enemy * newEnemy(int y, int x, float speed){
    Enemy * enemy=(Enemy*)malloc(sizeof(Enemy));
    if (enemy == NULL) {
        throwError("malloc failed");
    }
    if(x<0 || y<0) {
        enemy->x=1;
        enemy->y=1;
    }else{
        enemy->x=x;
        enemy->y=y;
    }
    enemy->speed=speed/100.0;
    enemy->holdCoin=0;
    enemy->lastMove=0.0;
    enemy->charge=0;
    enemy->dir=0;
    return enemy;
}

typedef struct{
    int points;
    int game;

}Level;

Level * newLevel(int points){
    Level *lvl= (Level*) malloc(sizeof(Level));
    if (lvl == NULL) {
        throwError("malloc");
    }
    if(points<0) {
        throwError("points cannot be negative");
    }
    lvl->points=points;
    lvl->game=1;

    return lvl;
}
