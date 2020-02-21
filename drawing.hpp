#ifndef DRAWING
#define DRAWING
#include "vec2.hpp"
#include <string>
enum colors{NONE=0,OCEAN=1,SHIP=2,FIRE=3,BOARDER=4,CURSOR=5};

namespace draw{
    void debug(std::string log);
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
