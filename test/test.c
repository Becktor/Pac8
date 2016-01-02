#include<stdio.h>
#include<ncurses.h>
#include<unistd.h>

int main ()
{
    int i=0;

    initscr();     //in ncurses
    timeout(0);
    while(!i)
    {
        usleep(1);
        i=getch();
        printw("%c ",i);
        if(i>0)
            i=1;
        else
            i=0;

    }
    endwin();
    printf("\nhitkb end\n");
    return 0;
}
