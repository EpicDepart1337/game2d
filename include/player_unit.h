#ifndef PLAYER_UNIT_H
#define PLAYER_UNIT_H
#include <SDL.h>

#include "gfc_types.h"
#include "gfc_vector.h"

#include "gf2d_sprite.h"

/**
@brief stores functions used to store the player location
This will be a little shitty since it'll basically force the window to be at a permanent 1200x720px

**/

typedef struct  playerPosition_S
{
	int playerPosX;
	int playerPosY;
	int multiplyer;
	int playerPosMaxX;
	int playerPosMaxY;
	int playerPosMinX;
	int playerPosMinY;
}playerPosition;




/**
@brief sets the multoplyer to 32 and all ints in playerPosition to 0;
*/
void player_unit_initialize();
/**
@brief sets the player location if they location was changed by anything
@param horizontal is the horizontal axis to be saved in playerPosition
@param vertical is the vertical axis to be saved in playerPosition
**/
void setPosition(int horizontal, int vertical);

/**
@brief renders the player based on the position from the 2d array playerPosition
*/
void renderPlayer();

/**
@brief moves the player left(-1) or right (1)
@param int movement, move the player left or right based on the negativity of the 1.
*/
void playerHoriz(int movement);



/**
@brief moves the player up(1) or down(-1)
@param int movement, move the player up or down  based on the negativity of the 1.
*/
void playerVert();

/**
@brief a simple return command to return the current playerPostion on the X axis
**/
int getHorizontal();


/**
@brief a simple return command to return the current playerPosition on the Y axis
**/
int getVertical();

#endif
