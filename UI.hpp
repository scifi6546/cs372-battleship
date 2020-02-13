#ifndef UI_HPP
#define UI_HPP
#include "grid.hpp"
class Game{
    public:
    Game(){
        initscr();
        player1.placeShip(Ship(Right,1,1,4,"battleship"));
        player2.placeShip(Ship(Up,1,1,4,"battleship"));
    }
        void placeShip(Ship to_place){
            player1.addHoverShip(to_place);
            while(true){
                
                
                vec2 delta(0,0);
                char temp_char = getch();
                if(temp_char=='w'){
                    delta.y+=1;
                    //to_place.set_y(to_place.get_y()+1);
                }
                if(temp_char=='a'){
                    delta.x-=1;
                    //to_place.set_x(to_place.get_x()-1);
                }
                if(temp_char=='s'){
                    delta.y-=1;
                    //to_place.set_y(to_place.get_y()-1);
                }
                if(temp_char=='d'){
                    delta.x+=1;
                    //to_place.set_x(to_place.get_x()+1);
                }
                if(temp_char==' '){
                    player1.flipHoverShip();
                    //to_place.flip_ship();
                }
                int res = clear();
                if(res!=OK){
                    endwin();
                    printf("clear broke\n");
                    break;
                }
                player1.moveHoverShip(delta);
                //refresh();
                clear();
                //to_place.draw(1,1);
                draw();
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