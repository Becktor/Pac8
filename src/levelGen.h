#ifndef _LEVELGEN__H__
#define __LEVELGEN_H__



int * getLevel(int levelno);
void drawPlayer(int playerPos, int * level);
void draw(int * level, int tmp);
int * genLevel(int size);
#endif //__LEVELGEN_H__
