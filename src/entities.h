#ifndef _PLAYER__H__
#define __PLAYER_H__

typedef struct{
    int x;
    int y;
    int points;
}Player;


Player * newPlayer(int y, int x);

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


Enemy * newEnemy(int y, int x, float speed, int value);

#endif //__PLAYER_H__
