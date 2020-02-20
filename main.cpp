#include "UI.hpp"
#include "drawing.hpp"
int main(){
	draw::init(true);
	Game game;
	game.draw();
	game.placeShip(1,Ship(Up,0,3,5,"air craft carrier"));
    game.placeShip(1,Ship(Up,0,3,4,"Battleship"));
	game.placeShip(1,Ship(Up,0,3,3,"Destroyer"));
	game.placeShip(1,Ship(Up,0,3,2,"Patroll Boat"));

	game.placeShip(2,Ship(Up,0,3,5,"air craft carrier"));
    game.placeShip(2,Ship(Up,0,3,4,"Battleship"));
	game.placeShip(2,Ship(Up,0,3,3,"Destroyer"));
	game.placeShip(2,Ship(Up,0,3,2,"Patroll Boat"));
	game.shoot(1);
	game.shoot(2);
		game.shoot(1);
	game.shoot(2);
		game.shoot(1);
	game.shoot(2);
	
}
