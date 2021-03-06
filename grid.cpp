#include "grid.hpp"
#include "drawing.hpp"
#include<iostream>
#include <algorithm>
#include<vector>
using std::vector;

Ship::Ship(Rotation rot,int x_pos,int y_pos,int length,std::string name){
            _rotation = rot;
            _Xpos=x_pos;
            _Ypos=y_pos;
            _length = length;
            _buildHull();
}
void Ship::_buildHull(){
            //if up
            _hull.clear();
            if(_rotation==Up){
                for(int i=0;i<_length;i++){
                    ShipHull hull;
                    hull.pos.x = _Xpos;
                    hull.pos.y = _Ypos+i;
                    _hull.push_back(hull);
                }
            }
            //if down
             if(_rotation==Down){
                for(int i=0;i<_length;i++){
                    ShipHull hull;
                    hull.pos.x = _Xpos;
                    hull.pos.y = _Ypos-i;
                    _hull.push_back(hull);
                }
            }
            //if left
            if(_rotation==Left){
                for(int i=0;i<_length;i++){
                    ShipHull hull;
                    hull.pos.x = _Xpos-i;
                    hull.pos.y = _Ypos;
                    _hull.push_back(hull);
                }
            }
            //if right
            if(_rotation==Right){
                for(int i=0;i<_length;i++){
                    ShipHull hull;
                    hull.pos.x = _Xpos+i;
                    hull.pos.y = _Ypos;
                    _hull.push_back(hull);
                }
            }
}
void Ship::set_x(int x){
    _Xpos=x;
    _buildHull();
}
void Ship::set_y(int y){
    _Ypos=y;
    _buildHull();
}
void Ship::flip_ship(){
    switch(_rotation){
        case Up:
            _rotation=Right;
            break;
        case Right:
            _rotation=Down;
            break;
        case Down:
            _rotation=Left;
            break;
        case Left:
            _rotation=Up;
            break;
	case NUM_ROTATIONS:
	    break;
    }
    _buildHull();
}
SHIP_STATUS Ship::shoot(std::vector<HIT> shots)const{
    //getting if unique
    std::sort(shots.begin(),shots.end());
    std::unique(shots.begin(),shots.end());
    SHIP_STATUS out;
    for(auto shot:shots){
        for(auto hull:_hull){
            if(hull.pos==shot.pos){
		    out.hits++;

            }
        }

    }
    if(out.hits==_length){
        out.sunk=true;
    }
    return out;

}
void Ship::draw(int x,int y, vector<HIT>&beenShot){
    for(auto h:_hull){
        for(auto hit:beenShot){
        if(h.pos==hit.pos){
            draw::drawchar(vec2(h.pos.x+x,h.pos.y+y),'*',SHIP);
                draw::drawchar(vec2(12,12),'h',NONE);
        }else{
            draw::drawchar(vec2(h.pos.x+x,h.pos.y+y),'#',SHIP);
                draw::drawchar(vec2(12,13),'n',NONE);
        }
}
    }
}
bool Grid::placeShip(Ship to_place){
   
    if(isOnBoard(to_place)&& !isOverlapping(to_place)){
        _ships.push_back(to_place);
        return true;
    }else{
    return false;
    }
};
void Grid::addHoverShip(Ship to_place){
    _hoverShip=std::make_unique<Ship>(to_place);
}
bool Grid::placeHover(){
    if(_hoverShip!=nullptr){
        bool status = placeShip(*_hoverShip);
	if(status==true)
            _hoverShip=nullptr;
        return status;
    }
    return false;
    
}
void Grid::moveHoverShip(vec2 delta_pos){
    if(_hoverShip!=nullptr){
        int x = _hoverShip->get_x();
        int y = _hoverShip->get_y();
        _hoverShip->set_x(delta_pos.x+x);
        _hoverShip->set_y(delta_pos.y+y);
        if(!isOnBoard(*_hoverShip)){
            _hoverShip->set_x(x);
            _hoverShip->set_y(y);
        }
    }
}
bool Grid::isOverlapping(const Ship &to_check){
    for(auto ship: _ships){
        for(auto _h:ship._hull){
            for(auto _h2:to_check._hull){
                if(_h.pos==_h2.pos){
                    return true;
                }
            }
        }
    }
    return false;
}
bool Grid::isOnBoard(Ship& to_check){
    if(to_check.get_x()>=_boardXSize || to_check.get_y()>=_boardYSize ){
        return false;
    }
    if(to_check.get_x()<0 || to_check.get_y()<0){
        return false;
    }
    //checking left
    if(to_check.getRot()==Left&& to_check.get_x()-to_check.length()<0){
        return false;
    }
    //checking forwards
    if(to_check.getRot()==Right&& to_check.length()+to_check.get_x()>=_boardXSize){
        return false;
    }
    //checking up
    if(to_check.getRot()==Up&& to_check.length()+to_check.get_y()>=_boardYSize){
        return false;
    }
    //checking down
    if(to_check.getRot()==Down && to_check.get_y()-to_check.length()<0){
        return false;
    }
    return true;
}
bool Grid::shoot(vec2 pos){
    HIT hit;
    hit.pos=pos;
    _hits.push_back(hit);
    bool output = false;
    for(auto ship:_ships){
        if(ship.shoot(_hits).sunk){
        }
	for(auto hit:_hits){
	    if(ship.shoot({hit}).hits==1)
		    output=true;

	}
    }
    return output;
}

void Grid::draw(vec2 offset){
    for(int i=0;i<_boardXSize;i++){
        for(int j=0;j<_boardYSize;j++){
            draw::drawchar(vec2(offset.x+i,offset.y+j),'~',OCEAN);
        }
    }
    for(auto ship:_ships){
        ship.draw(offset.x,offset.y,_hits);
    }
    if(_hoverShip!=nullptr){
	draw::debug("drawing hover ship");
	auto v = std::vector<HIT>();
        _hoverShip->draw(offset.x,offset.y,v);
    }
    draw::drawchar(_cursorPos+offset,'@',CURSOR);
}
void Grid::setCursor(vec2 pos){
    _cursorPos=pos;
}
void Grid::flipHoverShip(){
    if(_hoverShip!=nullptr){
        _hoverShip->flip_ship();
    }
}
