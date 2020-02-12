#include "user_interface.h"
#include "simple_logger.h"


static userInterface user_interface;

Sprite * menu;


void user_interface_menu_initialize(){
	if (gf2d_sprite_manager_exists){
		menu = gf2d_sprite_load_image("images/default_menu.png");
		user_interface.open = true;
	}
	else{
		slog("Error: either the sprite manager is not initialized OR the image given does not exist!");
	}
}


void user_interface_menu_open(){
	if(user_interface.open) gf2d_sprite_draw_image(menu,vector2d(32,32));
}

void user_interface_menu_close(){
	user_interface.open = false;
}