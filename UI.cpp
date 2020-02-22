#include "UI.hpp"
using std::vector;

void Game::placeShip(int playerNum, Ship to_place){
    auto player = &player1;
    if(playerNum==2){
        player = &player2; 
    }
    player->addHoverShip(to_place);
    while(true){
        vec2 delta(0,0);
        char temp_char = draw::getchar();
	if(temp_char==' ')
	    draw::drawchar(vec2(12,14),'S',NONE);
        if(temp_char=='w'){
            delta.y+=1;
	    draw::drawchar(vec2(12,13),'W',NONE);
        }
        else if(temp_char=='a'){
            delta.x-=1;
	    draw::drawchar(vec2(12,13),'A',NONE);
        }
        else if(temp_char=='s'){
            delta.y-=1;
	    draw::drawchar(vec2(12,13),'S',NONE);
        }
        else if(temp_char=='d'){
            delta.x+=1;
	    draw::drawchar(vec2(12,13),'D',NONE);
        }
        else if(temp_char=='r'){
            player->flipHoverShip();
	    draw::drawchar(vec2(12,13),'R',NONE);
        }
        else if(temp_char==' '){
            player->placeHover();
            break;
        }else{
	    draw::drawchar(vec2(12,13),'N',NONE);
	}
        player->moveHoverShip(delta);
        draw();
    }
    player->placeHover();
}
void Game::draw(){
    draw::clear_screen();
    player1.draw(vec2(1,1));
    player2.draw(vec2(20,1));
    draw::refresh_screen();
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
            player->shoot(char_pos);
            break;
        }
        if(temp_char==27){
            return;
        }
        player->setCursor(char_pos);
        draw();
    }
}
