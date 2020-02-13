#include "drawing.hpp"
#include <ncurses.h>
bool ActuallyRunning=false;
void init(bool DrawToScreen){
    if(DrawToScreen){
        ActuallyRunning=true;
        initscr();
        raw();				/* Line buffering disabled	*/
	    keypad(stdscr, TRUE);		/* We get F1, F2 etc..		*/
	    noecho();
    }
}
int drawchar(vec2 pos,char to_draw){
    if(ActuallyRunning){
        mvaddch(pos.y,pos.x,to_draw);
    }
}
void quit(){
    if(ActuallyRunning){
         endwin();
         ActuallyRunning=false;
    }
    
}