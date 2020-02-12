#ifndef __USER_INTERFACE_H__
#define __USER_INTERFACE_H__

#include <SDL.h>
#include "gfc_types.h"
#include "gfc_vector.h"
#include "gfc_text.h"
#include "gf2d_sprite.h"





typedef struct userInterface_S
{
	Uint32 open;

}userInterface;

/**
@breif puts the sprite of the menu into the sprite loader
*/
void user_interfeace_menu_initialize();




/**
@brief draws the menu interface on the screen
*/
void user_interface_menu_open();




/**
@brief un-draws the menu interface on the screen
*/

void user_interface_menu_close();




#endif