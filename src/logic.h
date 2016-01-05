#include "entities.h"
#ifndef _ENTITIES__H__
#define __ENTITIES_H__


void playerMoveRight(Player * p);
void playerMoveLeft(Player * p);
void playerMoveUp(Player * p);
void playerMoveDown(Player *p);

void enemyMoveRight(Enemy * e);
void enemyMoveLeft(Enemy * e);
void enemyMoveUp(Enemy * e);
void enemyMoveDown(Enemy * e);
void enemyMove(Enemy * e);
void enemyCharge(Enemy * e, Player * p);
int playerCaught(Enemy *e, Player * p);
#endif //__ENTITIES_H__
