#include "entities.h"
#ifndef _CONTROLS__H__
#define __CONTROLS_H__


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
#endif //__CONTROLS_H__
