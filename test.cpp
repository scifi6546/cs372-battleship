#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "grid.hpp"

TEST_CASE("GRID","GRID"){
    Grid grid = Grid();
    Ship ship(Up,3,0,5,"battleship");
    REQUIRE(grid.placeShip(ship)==true);
    Ship bad_ship(Left,0,0,5,"battleship");
    REQUIRE(grid.placeShip(bad_ship)==false);
    REQUIRE(grid.shoot(3,0)==true);
    grid.draw(5,5);

}
