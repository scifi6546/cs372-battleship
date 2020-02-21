#include "UI.hpp"
#include "drawing.hpp"
#include<vector>
using std::vector;
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
	
	bool quit = false;

	while(true)
	{
		game.shoot(1);
		if(quit) //Allows Player 1 to end the game when they want to quit
			break;
		game.shoot(2);
		if(quit) //Allows Player 2 to end the game when they want to quit
			break;
	}
}
