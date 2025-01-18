#include "functions.h"

#ifdef __cplusplus
extern "C"
#endif

/*
GAMESTATE 0 - MENU
GAMESTATE 1 - GAME
GAMESTATE 2 - ASK FOR CONTINUE THE GAME
GAMESTATE 3 - SAVING SCORE
GAMESTATE 4 - SHOWING SCOREBOARD
*/

int main(int argc, char** argv) {
	int tick1, tick2, quit, frames, rc, gameState = 0, marioSavedY = 0, num_Deaths = 0, level = 1, marioLives = 3, score = 0, nick_len = 0, page = 1;
	int falling_fromPlatform[4] = { 0, 0, 0, 0 }, barrel_collision[4] = { 0,0,0,0 }, barrel_jumped[4] = { 0,0,0,0 };
	double marioX, marioY, delta, worldTime, fpsTimer, fps, jumpingVelocity, barrelVelocity = 100, marioSpeed = 5000;
	char nick[MAX_NICK_LEN] = {};
	SDL_Event event;
	SDL_Surface* screen, * charset, * mario, * mario_left, * mario_right, *bmp_barrel, *coin;
	SDL_Texture* scrtex;
	SDL_Window* window;
	SDL_Renderer* renderer;
	struct ladders ladder[4];
	struct platforms platform[4];
	struct barrels barrel[4];
	bool jumping = false, falling = false, isOnLadder = false, coinPicked = false, Typenickname = false;
	
	frames_reset(frames, fpsTimer, fps, quit, worldTime, marioX, marioY);
	sdl_config(rc, window, renderer, screen, scrtex);

	// loading bmp images
	charset = SDL_LoadBMP("./Assets/cs8x8.bmp");
	mario = SDL_LoadBMP("./Assets/mario.bmp");
	mario_left = SDL_LoadBMP("./Assets/mario_left.bmp");
	mario_right = SDL_LoadBMP("./Assets/mario.bmp");
	bmp_barrel = SDL_LoadBMP("./Assets/barrel.bmp");
	coin = SDL_LoadBMP("./Assets/coin.bmp");
	if (check_bmps(renderer, window, scrtex, screen, charset, mario, mario_left, mario_right, bmp_barrel, coin))
		return 1;


	char text[128];
	int czarny = SDL_MapRGB(screen->format, 0x00, 0x00, 0x00);
	int green = SDL_MapRGB(screen->format, 0x00, 0xFF, 0x00);
	int red = SDL_MapRGB(screen->format, 0xFF, 0x00, 0x00);
	int blue = SDL_MapRGB(screen->format, 0x11, 0x11, 0xCC);
	int yellow = SDL_MapRGB(screen->format, 0xFF, 0xFF, 0x00);
	
	level1(marioX, marioY, platform, ladder, barrel, level, marioLives,coinPicked);

	tick1 = SDL_GetTicks();
	while (!quit) {
		if (gameState == 0) {
			display_menu(screen, renderer, scrtex, charset, text, czarny);
		}
		if (gameState != 2) {
			tick2 = SDL_GetTicks();
			delta = (tick2 - tick1) * 0.001;
			if (delta <= 0.0)
			{
				delta = 0.001;
			}

			tick1 = tick2;
			worldTime += delta;
			SDL_FillRect(screen, NULL, czarny);
			fpsTimer += delta;
			if (fpsTimer > 0.5) {
				fps = frames * 2;
				frames = 0;
				fpsTimer -= 0.5;
			};
		}
		jumpingVelocity = -100 * delta;

		if (gameState) {
			if (gameState == 1) {
				Refresh_screen(renderer, scrtex, screen, mario, charset, bmp_barrel, coin, text, red, blue, yellow, green, score, gameState, marioLives, marioX, marioY, level, num_Deaths, worldTime, fps, coinPicked, platform, ladder, barrel);
				move_barrels(barrel, delta, worldTime);
				barrelcheck_leftMove(level, barrel, platform, worldTime);
				barrelcheck_RightMove(level, barrel_collision, barrel_jumped, barrel, platform, worldTime);
				check_collision(score, level, gameState, num_Deaths, marioX, marioY, delta, barrel_jumped, barrel_collision, barrel, platform, ladder, frames, fpsTimer, fps, quit, marioLives, worldTime, coinPicked, jumping, falling);
				check_levelEnd(coinPicked, score, level, marioX, marioY, platform, ladder, barrel, frames, fpsTimer, fps, gameState, quit, marioLives, worldTime);
				handleJump(jumping, falling, level, marioX, marioY, marioSavedY, jumpingVelocity, falling_fromPlatform, barrel, platform);

			}
			else if (gameState == 2) {
				Refresh_screen(renderer, scrtex, screen, mario, charset, bmp_barrel, coin, text, red, blue, yellow, green, score, gameState, marioLives, marioX, marioY, level, num_Deaths, worldTime, fps, coinPicked, platform, ladder, barrel);
				display_continueScreen(text, charset, screen, score);
			}
			else if (gameState == 3) {
				display_saveScore(nick,Typenickname, text, charset, screen, scrtex, renderer, czarny);
			}
			else if (gameState == 4) {
				display_scoreboard(text, charset, screen, scrtex, renderer, czarny);
			}
		}


		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_KEYDOWN:
				if (gameState==1)
					handleEvents(event, gameState, level, frames, num_Deaths, quit, marioLives, fpsTimer, delta, fps, worldTime, marioSavedY, marioX, marioY, marioSpeed, isOnLadder, jumping, falling,coinPicked, platform, ladder, barrel, mario, mario_left, mario_right, falling_fromPlatform);
				else if (!gameState)
					handleMenu(event, gameState, marioX, marioY, platform, ladder, barrel, quit, frames, fpsTimer, fps, worldTime, level, marioLives,coinPicked);

				else if (gameState == 2) {
					switch (event.key.keysym.sym) {
					case SDLK_n:
						gameState = 0;
						break;
					case SDLK_y:
						gameState = 1;
						break;
					}
				}
				else if (gameState == 3) {
					switch (event.key.keysym.sym) {
					case SDLK_n:
						if (!Typenickname) {
							score = 0;
							gameState = 0;
						}
						break;
					case SDLK_y:
						Typenickname = true;
						break;
					case SDLK_RETURN:
						saveScore(nick, score);
						Typenickname = false;
						gameState = 0;
						score = 0;
						break;
					case SDLK_BACKSPACE:
						if (Typenickname) {
							if (nick_len > 0) {
								nick[nick_len] = '\0';
								nick_len--;
							}
						}
					}
				}
				else if (gameState == 4) {
					switch (event.key.keysym.sym) {
					case SDLK_RIGHT:
						page++;
						break;
					case SDLK_LEFT:
						if (page > 1)
							page--;
						break;
					case SDLK_ESCAPE:
						gameState = 0;
						break;
					}
				}
				break;
			case SDL_TEXTINPUT:
				if (Typenickname) {
					if (nick_len < MAX_NICK_LEN-1) {
						strcat(nick, event.text.text);
						nick_len += strlen(event.text.text);
					}
				}
				break;
			case SDL_KEYUP:
				break;
			case SDL_QUIT:
				quit = 1;
				break;
			};
		};
		frames++;
	};

	// freeing all surfaces
	SDL_FreeSurface(charset);
	SDL_FreeSurface(screen);
	SDL_DestroyTexture(scrtex);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();
	return 0;
};