#include "UI.hpp"
#include "drawing.hpp"
int main(){
	draw::init(true);
	Game game;
	game.draw();
	game.placeShip(1,Ship(Up,0,3,5,"air craft carrier"));
	game.placeShip(2,Ship(Up,0,3,5,"air craft carrier"));
	game.shoot(0);
	
}
