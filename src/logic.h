#include "entities.h"
#pragma once

void playerMoveRight(Player * p);
void playerMoveLeft(Player * p);
void playerMoveUp(Player * p);
void playerMoveDown(Player *p);
void playerMove(Player * p, Level * lvl);
void enemyMoveRight(Enemy * e);
void enemyMoveLeft(Enemy * e);
void enemyMoveUp(Enemy * e);
void enemyMoveDown(Enemy * e);
void enemyMove(Enemy * e);
void enemyCharge(Enemy * e, Player * p);
int playerCaught(Enemy *e, Player * p);
void moveAll(Enemy ** es, Player *p, Level * lvl);
