#include "UI.hpp"

void Game::placeShip(int playerNum, Ship to_place){
    auto player = &player1;
    if(playerNum==2){
        player = &player2; 
    }
    player->addHoverShip(to_place);
    while(true){
        vec2 delta(0,0);
        char temp_char = draw::getchar();
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
        if(temp_char=='r'){
            player->flipHoverShip();
            //to_place.flip_ship();
        }
        if(temp_char==' '){
            player->placeHover();
            break;
        }
        player->moveHoverShip(delta);
        //refresh();
        draw::clear_screen();
        //to_place.draw(1,1);
        draw();
        draw::refresh_screen();
        
    }
}
void Game::draw(){
    player1.draw(vec2(1,1));
    player2.draw(vec2(20,1));
}
void Game::shoot(int player_num){
    auto player = &player1;
    if(player_num==2){
        player = &player2; 
    }
    vec2 offset(1,1);
    if(player_num==2){
        offset=vec2(20,1);
    }
    vec2 char_pos(0,0);
    while(true){
        char temp_char = draw::getchar();
        if(temp_char=='w'){
            char_pos.y+=1;
        }
        if(temp_char=='a'){
            char_pos.x-=1;
        }
        if(temp_char=='s'){
            char_pos.y-=1;
        }
        if(temp_char=='d'){
            char_pos.x+=1;
        }
        if(temp_char==' '){
            player->shoot(char_pos.x,char_pos.y);
            break;
        }
        player->setCursor(char_pos);
        draw();
        draw::refresh_screen();
    }
    player->shoot(char_pos.x,char_pos.y);
    draw::refresh_screen();
}
