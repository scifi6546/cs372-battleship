#ifndef GRID
#define GRID
#include <vector>
#include <string>
#include <memory>
#include "vec2.hpp"
#include<vector>
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
struct SHIP_STATUS{
    int hits=0;
    bool sunk=false;

};

struct HIT{
	vec2 pos=vec2(0,0);

	bool operator==(HIT& other){

		return pos==other.pos;
	}
	bool operator<(HIT&other){
            return pos<other.pos;

	}
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
        SHIP_STATUS shoot(std::vector<HIT> shots)const;
        //draws elements with offset x and y
        void draw(int x,int y, std::vector<HIT> & beenShot);
        //flips ships clockwise
        void flip_ship();
        std::vector<ShipHull> _hull;
        
    private:
        //rebuild hull
        void _buildHull();
        Rotation _rotation;
        int _Xpos=0;
        int _Ypos=0;
        int _length=0;
        bool sunk=false;
        

};
class Grid{
   public:
        bool placeShip(Ship to_place);
        void addHoverShip(Ship to_place);
        void moveHoverShip(vec2 delta_pos);
        void flipHoverShip();
        bool isOnBoard(Ship& to_check);
        bool isOverlapping(const Ship &to_check);
        bool shoot(vec2 pos);
        void draw(vec2 offset);
        bool placeHover();
        void setCursor(vec2 pos);
   private:
        const int _boardXSize = 10;
        const int _boardYSize = 10;
        vec2 _cursorPos=vec2(0,0);
        std::unique_ptr<Ship> _hoverShip=nullptr;
        std::vector<Ship> _ships={};
        
	std::vector<HIT> _hits={};
};
#endif
