#include "drawing.hpp"
#include <ncurses.h>
bool ActuallyRunning=false;

void draw::init(bool DrawToScreen){
    if(DrawToScreen){
        ActuallyRunning=true;
        initscr();
        raw();				/* Line buffering disabled	*/
	    keypad(stdscr, TRUE);		/* We get F1, F2 etc..		*/
	    noecho();
    }
}
int draw::drawchar(vec2 pos,char to_draw){
    if(ActuallyRunning){
        mvaddch(draw::getRows()-pos.y,pos.x,to_draw);
    }
}
void draw::quit(){
    if(ActuallyRunning){
         endwin();
         ActuallyRunning=false;
    }
}
int draw::getCols(){
    if(ActuallyRunning){
        return getmaxx(stdscr);
    }
}
int draw::getRows(){
    if(ActuallyRunning){
        return getmaxy(stdscr);
    }
}
void draw::refresh_screen(){
    if(ActuallyRunning){
        refresh();
    }
}
void draw::clear_screen(){
    if(ActuallyRunning){
        clear();
    }
}
char draw::getchar(){
    if(ActuallyRunning){
        return getch();
    }
    return 0;
}