#include "grid.hpp"
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
            mvaddch(LINES - (h.y+y),h.x+x,'*');
        }else{
            mvaddch(LINES - (h.y+y),h.x+x,'#');
        }
    }
}
bool Grid::placeShip(Ship to_place){
    if(to_place.get_x()>=_boardXSize || to_place.get_y()>=_boardYSize ){
        return false;
    }
    //checking backwards
    if(to_place.getRot()==Left&& to_place.get_x()-to_place.length()<0){
        return false;
    }
    //checking forwards
    if(to_place.getRot()==Right&& to_place.length()+to_place.get_x()>=_boardXSize){
        return false;
    }
    //checking up
    if(to_place.getRot()==Up&& to_place.length()+to_place.get_y()>=_boardYSize){
        return false;
    }
    //checking down
    if(to_place.getRot()==Down && to_place.length()-to_place.get_y()<0){
        return false;
    }
    _ships.push_back(to_place);
    return true;
};