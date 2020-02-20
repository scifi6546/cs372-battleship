#include "UI.hpp"
#include "drawing.hpp"
#include<vector>
using std::vector;
int main(){
	draw::init(true);
	Game game;
	vector<vector<bool>> beenShot1(10, vector<bool>(10, false));
	vector<vector<bool>> beenShot2(10, vector<bool>(10, false));
	game.draw(beenShot1);
	game.placeShip(1,Ship(Up,0,3,5,"air craft carrier"), beenShot1);
    game.placeShip(1,Ship(Up,0,3,4,"Battleship"), beenShot1);
	game.placeShip(1,Ship(Up,0,3,3,"Destroyer"), beenShot1);
	game.placeShip(1,Ship(Up,0,3,2,"Patroll Boat"), beenShot1);

	game.placeShip(2,Ship(Up,0,3,5,"air craft carrier"), beenShot2);
    game.placeShip(2,Ship(Up,0,3,4,"Battleship"), beenShot2);
	game.placeShip(2,Ship(Up,0,3,3,"Destroyer"), beenShot2);
	game.placeShip(2,Ship(Up,0,3,2,"Patroll Boat"), beenShot2);
	
	bool quit = false;

	while(true)
	{
		game.shoot(1, beenShot1, quit);
		if(quit) //Allows Player 1 to end the game when they want to quit
			break;
		game.shoot(2, beenShot2, quit);
		if(quit) //Allows Player 2 to end the game when they want to quit
			break;
	}
}
