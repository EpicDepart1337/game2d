#ifndef __USER_INTERFACE_H__
#define __USER_INTERFACE_H__

#include <SDL.h>
#include <SDL_ttf.h>
#include "gfc_types.h"
#include "gfc_vector.h"
#include "gfc_text.h"
#include "gf2d_sprite.h"
/**
@brief userInterface system that stores important variables that will be used by all types of text displays
@param open check if a menu should be open
@param if the TTF_Init has been called and if sprite manager is working(it depends on it)
@param fg the font color used by all texts
@param font the font utilized
@param menuDelay, keeps track of a menudelay(default 0.2 seconds) so that hitting the button won't rapidly open and close the file
@param surface kept NULL and is filled for the menu that will be currently used
@param texture, also kept null and is filled for when a menu needs to be loaded
*/




typedef struct userInterface_S
{
	Uint32 open;
	int on;
	SDL_Color fg;
	TTF_Font *font;
	unsigned int menuDelay;
	SDL_Surface * surface;
	SDL_Texture * texture;
}userInterface;

/**
@breif puts the sprite of the menu into the sprite loader
*/
void user_interfeace_menu_initialize();




/**
@brief draws the menu interface on the screen if the menu has been toggled
*/
void user_interface_menu_open();



/**
@brief sets a text to be rendered 
@param the text to be put in the menu
*/
void user_interface_set_text(const char *text);
/**
@brief toggles whether or not the menu will be displayed on the next frame
*/

void user_interface_menu_toggle();



/**
@brief displays the tex we've set with set_text 
@param LOL
*/
void user_interface_display_text();
#endif