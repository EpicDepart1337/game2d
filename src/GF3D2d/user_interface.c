#include <SDL_ttf.h>
#include "user_interface.h"
#include "simple_logger.h"
#include "gf2d_graphics.h"


static userInterface user_interface;

Sprite * menu;


void user_interface_menu_initialize(){
	const char * file;
	TTF_Font * funt;
	user_interface.on = TTF_Init();
	file = "times.ttf";
	funt = TTF_OpenFont(file, 20);
	if (funt){
		
		slog("Font file has been initialized");

	}
	else
	{
		slog("Font file not found");
	}
	if (gf2d_sprite_manager_exists && funt){
		
		SDL_Color fg = { 0, 0, 0 };
		user_interface.fg = fg;
		user_interface.on = 1;
		user_interface.font = funt;
		menu = gf2d_sprite_load_image("images/default_menu.png");
		user_interface.open = false;
		slog("Menu UI system initialized");
	}
	else{
		slog("Error: either the sprite manager is not initialized OR the image given does not exist!");
	}
}


void user_interface_menu_open(){

	if (user_interface.open)
	{ 
		gf2d_sprite_draw_image(menu, vector2d(400, 576)); 
		
	
	}
}

void user_interface_menu_toggle(){
	unsigned int currentTime = SDL_GetTicks();
	if (currentTime > user_interface.menuDelay + 200) {

		user_interface.menuDelay = currentTime;
		user_interface.open = !user_interface.open;
	}
}

void user_interface_set_text(const char *text){
	
	user_interface.surface = TTF_RenderText_Solid(user_interface.font, text, user_interface.fg);
	user_interface.texture = SDL_CreateTextureFromSurface(gf2d_graphics_get_renderer(), user_interface.surface);
}

void user_interface_display_text(){
	if (user_interface.open){
	SDL_Rect target;
	gfc_rect_set(target, 400, 576, 400, 144);
	SDL_RenderCopy(gf2d_graphics_get_renderer(), user_interface.texture, NULL, &target);

}
}