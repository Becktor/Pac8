#include <stdio.h>
#include <ncurses.h>
#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))
void draw(int *level, int tmp){

    if(level[tmp]==0){
        printw(" #");
    }else if(level[tmp]==1){
        printw("  ");
    }else if(level[tmp]==3){
        printw(" 8");
    }else if(level[tmp]==9){
        printw(" O");
    }

}

int * getLevel(int levelno)
{

    static int l1[100]={ 0,0,0,0,0,0,0,0,0,0,
                         0,3,1,1,1,1,1,1,1,0,
                         0,0,0,0,0,0,0,0,1,0,
                         0,1,1,1,1,1,1,0,1,0,
                         0,1,0,0,0,0,1,0,1,0,
                         0,1,1,1,1,0,1,0,1,0,
                         0,0,0,0,1,0,1,0,1,0,
                         0,1,1,0,1,0,1,0,1,0,
                         0,9,1,1,1,0,1,1,1,1,
                         0,0,0,0,0,0,0,0,0,0 };

    static int l2[100]={ 0,0,0,0,0,0,0,0,0,0,
                         1,1,1,0,1,1,1,1,1,1,
                         1,0,1,0,1,0,1,0,1,0,
                         1,0,1,0,1,0,1,0,1,1,
                         1,0,1,1,1,0,1,0,1,1,
                         1,0,0,0,0,0,0,0,0,0,
                         1,1,1,1,1,1,0,9,1,1,
                         1,1,0,1,0,1,0,1,0,1,
                         1,9,0,9,0,9,1,1,0,1,
                         0,0,0,0,0,0,0,0,0,0 };

    static int l3[100]={ 0,0,0,0,0,0,0,0,0,0,
                         0,1,1,1,1,1,1,0,9,0,
                         1,1,1,0,1,0,1,0,9,0,
                         1,0,9,0,1,0,1,0,9,0,
                         0,1,0,1,1,0,1,0,1,1,
                         1,1,1,1,0,1,1,0,1,1,
                         1,1,1,0,1,1,1,1,1,0,
                         1,1,0,1,1,1,1,1,0,1,
                         1,1,1,1,1,1,1,1,1,1,
                         0,0,0,0,0,0,0,0,0,0 };

    static int l4[100]={ 0,0,0,0,0,0,0,0,0,0,
                         1,0,1,1,0,1,1,1,1,0,
                         1,1,1,0,1,1,1,1,1,0,
                         1,1,0,1,1,0,0,0,1,0,
                         1,0,1,1,0,0,1,1,1,0,
                         0,1,1,0,1,0,1,0,0,0,
                         1,1,0,1,1,0,1,0,9,0,
                         1,0,1,1,0,0,1,0,9,0,
                         0,9,1,1,1,1,1,1,1,0,
                         0,0,0,0,0,0,0,0,0,0 };

    switch(levelno) {
    case 0 :
        return l1;
    case 1 :
        return l2;
    case 2 :
        return l3;
    case 3 :
        return l4;
    default :
        printf("no such level\n" );
    }
    return 0;
}
void genLevel(int size)
{
    for(int i=0;i<10;i++){
        for(int k=0;k<size;k++){
            int * level = getLevel(k);
            for(int j=0;j<10;j++){
                int tmp= i*10+j;
                draw(level,tmp);
            }
        }
        printw("\n");
    }
    mvprintw(12,0,"Points: %i",0);
    mvprintw(14,0,"Move with A S W D collect the points and avoid the beast");
}

void drawPlayer(int playerPos, int * level){

    level[playerPos]=11;
}
