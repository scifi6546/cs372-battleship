#include "grid.hpp"
#include "drawing.hpp"
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
                    hull.x = _Xpos;
                    hull.y = _Ypos+i;
                    _hull.push_back(hull);
                }
            }
            //if down
             if(_rotation==Down){
                for(int i=0;i<_length;i++){
                    ShipHull hull;
                    hull.x = _Xpos;
                    hull.y = _Ypos-i;
                    _hull.push_back(hull);
                }
            }
            //if left
            if(_rotation==Left){
                for(int i=0;i<_length;i++){
                    ShipHull hull;
                    hull.x = _Xpos-i;
                    hull.y = _Ypos;
                    _hull.push_back(hull);
                }
            }
            //if right
            if(_rotation==Right){
                for(int i=0;i<_length;i++){
                    ShipHull hull;
                    hull.x = _Xpos+i;
                    hull.y = _Ypos;
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
    }
    _buildHull();
}
bool Ship::shoot(int x,int y){
    bool is_shot = false;
    for(size_t i =0; i<_hull.size();i++){
        if(_hull[i].x==x && _hull[i].y==y && _hull[i].shot==false){
            _hull[i].shot=true;
            is_shot = true;
        }
    }
    int num_shot = 0;
    for (auto h:_hull){
        if(h.shot==true){
            num_shot++;
        }
    }
    if(num_shot==_length){
        sunk = true;
    }
    return is_shot;
}
void Ship::draw(int x,int y){
    for(auto h:_hull){
        if(h.shot==true){
            drawchar(vec2(h.x+x,LINES - (h.y+y)),'*');
        }else{
            drawchar(vec2(h.x+x,LINES - (h.y+y)),'*');
        }
    }
}
bool Grid::placeShip(Ship to_place){
   
    if(isOnBoard(to_place)){
        _ships.push_back(to_place);
        return true;
    }else{
    return false;
    }
};
void Grid::addHoverShip(Ship to_place){
    _hoverShip=std::make_unique<Ship>(to_place);
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
void Grid::draw(int x,int y){
    for(auto ship:_ships){
        ship.draw(x,y);
        refresh();
    }
    if(_hoverShip!=nullptr){
        _hoverShip->draw(x,y);
    }
}
void Grid::flipHoverShip(){
    if(_hoverShip!=nullptr){
        _hoverShip->flip_ship();
    }
}