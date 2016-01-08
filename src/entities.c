#include <stdlib.h>

typedef struct{
    int x;
    int y;
    int points;
}Player;

Player * newPlayer(int y, int x){
    Player *player=(Player*)malloc(sizeof(Player));
    player->x=x;
    player->y=y;
    player->points=0;
    return player;
}

typedef struct{
    int x;
    int y;
    float speed;
    int holdCoin;
    int value;
    float lastMove;
    int charge;
    int dir;
}Enemy;

Enemy * newEnemy(int y, int x, float speed,int value){
    Enemy * enemy=(Enemy*)malloc(sizeof(Enemy));
    enemy->x=x;
    enemy->y=y;
    enemy->speed=speed/100.0;
    enemy->holdCoin=0;
    enemy->value=value;
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
    lvl->points=points;
    lvl->game=1;
    return lvl;
}
