#include <SDL.h>
#include <SDL_ttf.h>
#include "gf2d_graphics.h"
#include "gf2d_sprite.h"
#include "simple_logger.h"
#include "user_interface.h"
#include "gfc_input.h"
#include "player_unit.h"
int main(int argc, char* argv[])
{
    /*variable declarations*/
    int done = 0;
    const Uint8* keys;
    Sprite* sprite;
	int mx, my;
    float mf = 0;
    Sprite* mouse;
	Sprite * player;
    Vector4D mouseColor = { 255,100,255,200 };
	//msyi.ttf
	const char * text = "LOL";
	
	
    init_logger("gf2d.log");
    slog("---==== BEGIN ====---");
    gf2d_graphics_initialize(
        "gf2d",
        1200,
        720,
        1200,
        720,
        vector4d(0, 0, 0, 255),
        0);
    gf2d_graphics_set_frame_delay(16);
    gf2d_sprite_init(1024);
	gfc_input_init("config.txt");
    SDL_ShowCursor(SDL_DISABLE);

	user_interface_display_text(text);
	player = gf2d_sprite_load_image("images/player.png");
    /*demo setup*/
	player_unit_initialize();
    sprite = gf2d_sprite_load_image("images/backgrounds/bg_flat.png");
    mouse = gf2d_sprite_load_all("images/pointer.png", 32, 32, 16);
	user_interface_menu_initialize();
	user_interface_set_text(text);
    /*main game loop*/
    while (!done)
    {
        SDL_PumpEvents();   // update SDL's internal event structures
        keys = SDL_GetKeyboardState(NULL); // get the keyboard state for this frame
        /*update things here*/
        SDL_GetMouseState(&mx, &my);
        mf += 0.1;
        if (mf >= 16.0)mf = 0;


        gf2d_graphics_clear_screen();// clears drawing buffers
        // all drawing should happen betweem clear_screen and next_frame
            //backgrounds drawn first
        gf2d_sprite_draw_image(sprite, vector2d(0, 0));
		if (gfc_input_key_down("m"))
			user_interface_menu_toggle();
		if (gfc_input_key_pressed("a"))
			playerHoriz(-1);
		if (gfc_input_key_pressed("d"))
			playerHoriz(1);
		if (gfc_input_key_pressed("w"))
			playerVert(-1);
		if (gfc_input_key_pressed("s"))
			playerVert(1);


		
		
		renderPlayer();
		user_interface_menu_open();
		user_interface_display_text();
        //UI elements last
        gf2d_sprite_draw(
            mouse,
            vector2d(mx, my),
            NULL,
            NULL,
            NULL,
            NULL,
            &mouseColor,
            (int)mf);
		
		renderPlayer();
        gf2d_grahics_next_frame();// render current draw frame and skip to the next frame

        if (keys[SDL_SCANCODE_ESCAPE])done = 1; // exit condition
        slog("Rendering at %f FPS", gf2d_graphics_get_frames_per_second());
    }
    slog("---==== END ====---");
    return 0;
}
/*eol@eof*/