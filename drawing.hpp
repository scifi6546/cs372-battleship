#ifndef DRAWING
#define DRAWING
#include "vec2.hpp"
enum colors{NONE,OCEAN,SHIP,BOARDER,CURSOR};
namespace draw{
    void init(bool DrawToScreen);
    int drawchar(vec2 pos,char to_draw,colors draw_colors);
    int getCols();
    int getRows();
    void refresh_screen();
    void clear_screen();
    char getchar();
    void quit();
}
#endif
