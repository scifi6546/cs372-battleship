#ifndef UI_HPP
#define UI_HPP
#include "grid.hpp"
class Game{
    public:
    Game(){
        player1.placeShip(Ship(Right,1,1,4,"battleship"));
        player2.placeShip(Ship(Up,1,1,4,"battleship"));
    }
        void placeShip(Ship to_place){
            while(true){
                clear();
                char temp_char = getch();
                if(temp_char=='w'){
                    to_place.set_y(to_place.get_y()+1);
                }
                if(temp_char=='a'){
                    to_place.set_x(to_place.get_x()-1);
                }
                if(temp_char=='s'){
                    to_place.set_y(to_place.get_y()-1);
                }
                if(temp_char=='d'){
                    to_place.set_x(to_place.get_x()+1);
                }
                if(temp_char==' '){
                    to_place.flip_ship();
                }
                to_place.draw(1,1);
                refresh();
                
            }
        }
        void draw(){
            player1.draw(1,1);
            player2.draw(20,1);
        }
    private:
        Grid player1;
        Grid player2;

        //State
        

};
#endif