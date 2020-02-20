#ifndef UI_HPP
#define UI_HPP
#include "grid.hpp"
#include "drawing.hpp"
#include<vector>

class Game{
    public:
    Game(){
        player1.placeShip(Ship(Right,1,1,4,"battleship"));
        player2.placeShip(Ship(Up,1,1,4,"battleship"));
    }
        void placeShip(int playerNum, Ship to_place, std::vector<std::vector<bool>> & beenShot);
        void draw(std::vector<std::vector<bool>> & beenShot);
        void shoot(int player_num, std::vector<std::vector<bool>> & beenShot, bool & quit);
    private:
        Grid player1;
        Grid player2;
        //State
        

};
#endif