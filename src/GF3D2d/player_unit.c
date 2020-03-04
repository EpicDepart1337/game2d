#include <SDL.h>

#include "gfc_types.h"
#include "gfc_vector.h"

#include "gf2d_sprite.h"
#include "player_unit.h"


static playerPosition playerPos;
Sprite * player;


void player_unit_initialize(){
	playerPos.multiplyer = 32;
	playerPos.playerPosMaxX = 36;
	playerPos.playerPosMaxY = 21;
	playerPos.playerPosMinX = 1;
	playerPos.playerPosMinY = 1;
	playerPos.playerPosX = 5;
	playerPos.playerPosY = 6;
	player = gf2d_sprite_load_image("images/player.png");
}


void renderPlayer(){
	gf2d_sprite_draw_image(player,vector2d(playerPos.playerPosX*playerPos.multiplyer, playerPos.playerPosY*playerPos.multiplyer));
}

void playerHoriz(int movement){
	if (playerPos.playerPosX + movement > playerPos.playerPosMaxX || playerPos.playerPosX + movement < playerPos.playerPosMinX){
		return;
	}
	else {
		playerPos.playerPosX += movement;
	}
}

void playerVert(int movement){
	if (playerPos.playerPosY + movement > playerPos.playerPosMaxY || playerPos.playerPosY + movement < playerPos.playerPosMinY){
		return;
	}
	else
	{
		playerPos.playerPosY += movement;
	}
	
}
void setPosition(int horizontal, int vertical){
	playerPos.playerPosX = horizontal;
	playerPos.playerPosY = vertical;
}

int getVertical(){
	return playerPos.playerPosY;
}