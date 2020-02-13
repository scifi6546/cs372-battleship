#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "grid.hpp"
#include "drawing.hpp"

TEST_CASE("Grid Testing","Grid"){
    init(false);
    Grid grid;
    Ship ship(Up,1,0,5,"battleship");
    INFO("grid.placeShip(ship)==true)");
    REQUIRE(grid.placeShip(ship)==true);
    Ship bad_ship(Left,0,0,5,"battleship");
    INFO("grid.placeShip(bad_ship)==false");
    REQUIRE(grid.placeShip(bad_ship)==false);
    INFO("grid.shoot(3,0)==true");
    REQUIRE(grid.shoot(1,0)==true);
    grid.draw(5,5);

    REQUIRE(grid.isOnBoard(bad_ship)==false);

}
