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
        start_color();
        init_pair(NONE,COLOR_WHITE,COLOR_BLACK);
        init_pair(OCEAN,COLOR_WHITE,COLOR_BLUE);
        init_pair(SHIP,COLOR_BLACK,COLOR_WHITE);
        init_pair(FIRE,COLOR_RED,COLOR_BLACK);
        init_pair(BOARDER,COLOR_WHITE,COLOR_BLACK);
        init_pair(CURSOR,COLOR_WHITE,COLOR_BLACK);



    }
}
int draw::drawchar(vec2 pos,char to_draw,colors draw_colors){
    if(ActuallyRunning){
        attron(COLOR_PAIR(draw_colors));
        mvaddch(draw::getRows()-pos.y,pos.x,to_draw);
        attroff(COLOR_PAIR(draw_colors));
    }
    return 0;
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
    return 10;
}
int draw::getRows(){
    if(ActuallyRunning){
        return getmaxy(stdscr);
    }
    return 10;
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
