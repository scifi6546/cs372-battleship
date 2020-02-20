#ifndef DRAWING
#define DRAWING
#include "vec2.hpp"
namespace draw{
    void init(bool DrawToScreen);
    int drawchar(vec2 pos,char to_draw);
    int getCols();
    int getRows();
    void refresh_screen();
    void clear_screen();
    char getchar();
    void quit();
}
#endif