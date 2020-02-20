#ifndef GRID
#define GRID
#include <vector>
#include <string>
#include <memory>
#include "vec2.hpp"
/*
 y+
 |
 |
 |
 *--------->x+
 */
enum Rotation{Right,Left,Up,Down,NUM_ROTATIONS};
struct ShipHull{
    bool shot = false;
    vec2 pos=vec2(0,0);

};
class Ship{
    Ship() = delete;
    public:
        Ship(Rotation rot,int x_pos,int y_pos,int length,std::string name);
        int get_x()const {return _Xpos;};
        int get_y()const {return _Ypos;};
        //does not move hull to fix
        void set_x(int x);
        //does not move hull fix now
        void set_y(int y);
        int length()const{return _length;};
        Rotation getRot()const{return _rotation;};
        //shoots hull elements
        bool shoot(int x,int y);
        //draws elements with offset x and y
        void draw(int x,int y);
        //flips ships clockwise
        void flip_ship();
        std::vector<ShipHull> _hull;
        
    private:
        //rebuild hull
        void _buildHull();
        Rotation _rotation;
        int _Xpos;
        int _Ypos;
        int _length;
        bool sunk;
        

};
class Grid{
   public:
        bool placeShip(Ship to_place);
        void addHoverShip(Ship to_place);
        void moveHoverShip(vec2 delta_pos);
        void flipHoverShip();
        bool isOnBoard(Ship& to_check);
        bool isOverlapping(const Ship &to_check);
        bool shoot(int x, int y);
        void draw(vec2 offset);
        bool placeHover();
        void setCursor(vec2 pos);
   private:
        const int _boardXSize = 10;
        const int _boardYSize = 10;
        vec2 _cursorPos=vec2(0,0);
        std::unique_ptr<Ship> _hoverShip;
        std::vector<Ship> _ships;
        
};
#endif
