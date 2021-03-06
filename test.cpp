#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "grid.hpp"
#include "drawing.hpp"
#include "UI.hpp"

TEST_CASE("Grid Testing","Grid"){
    draw::init(false);
    Grid grid;
    Ship ship(Up,1,0,5,"battleship");
    INFO("grid.placeShip(ship)==true)");
    REQUIRE(grid.placeShip(ship)==true);
    Ship bad_ship(Left,0,0,5,"battleship");
    INFO("grid.placeShip(bad_ship)==false");
    REQUIRE(grid.placeShip(bad_ship)==false);
    INFO("grid.shoot(3,0)==true");
    REQUIRE(grid.shoot(vec2(1,0))==true);
    grid.draw(vec2(5,5));

    REQUIRE(grid.isOnBoard(bad_ship)==false);
    Grid grid2;
    Ship ship3(Up,1,0,5,"battleship");
    grid2.addHoverShip(ship3);
    REQUIRE(grid2.placeHover());
    grid2.addHoverShip(ship3);
    REQUIRE(grid2.placeHover()==false);
}
