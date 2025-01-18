#include "functions.h"
int platform_gap = L1_PLATFORM_GAP;

void DrawString(SDL_Surface* screen, int x, int y, const char* text, SDL_Surface* charset) {
	int px, py, c;
	SDL_Rect s, d;
	s.w = 8;
	s.h = 8;
	d.w = 8;
	d.h = 8;
	while (*text) {
		c = *text & 255;
		px = (c % 16) * 8;
		py = (c / 16) * 8;
		s.x = px;
		s.y = py;
		d.x = x;
		d.y = y;
		SDL_BlitSurface(charset, &s, screen, &d);
		x += 8;
		text++;
	};
};
void DrawSurface(SDL_Surface* screen, SDL_Surface* sprite, int x, int y) {
	SDL_Rect dest;
	dest.x = x - sprite->w / 2;
	dest.y = y - sprite->h / 2;
	dest.w = sprite->w;
	dest.h = sprite->h;
	SDL_BlitSurface(sprite, NULL, screen, &dest);
};
void DrawPixel(SDL_Surface* surface, int x, int y, Uint32 color) {
	int bpp = surface->format->BytesPerPixel;
	Uint8* p = (Uint8*)surface->pixels + y * surface->pitch + x * bpp;
	*(Uint32*)p = color;
};
// rysowanie linii o d≥ugoúci l w pionie (gdy dx = 0, dy = 1)  bπdü poziomie (gdy dx = 1, dy = 0)
void DrawLine(SDL_Surface* screen, int x, int y, int l, int dx, int dy, Uint32 color) {
	for (int i = 0; i < l; i++) {
		DrawPixel(screen, x, y, color);
		x += dx;
		y += dy;
	};
};
void DrawRectangle(SDL_Surface* screen, int x, int y, int l, int k, Uint32 outlineColor, Uint32 fillColor) {
	int i;
	DrawLine(screen, x, y, k, 0, 1, outlineColor);
	DrawLine(screen, x + l - 1, y, k, 0, 1, outlineColor);
	DrawLine(screen, x, y, l, 1, 0, outlineColor);
	DrawLine(screen, x, y + k - 1, l, 1, 0, outlineColor);
	for (i = y + 1; i < y + k - 1; i++)
		DrawLine(screen, x + 1, i, l - 2, 1, 0, fillColor);
};

void level1(double& marioX, double& marioY, platforms(&platform)[4], ladders(&ladder)[4], barrels(&barrel)[4], int& level, int& marioLives, bool& coinPicked) {
	coinPicked = false;
	level = 1;
	platform_gap = 90;
	platform[0].x = platform_gap;
	platform[1].x = 0;
	platform[2].x = platform_gap;
	platform[3].x = 0;

	platform[0].width = SCREEN_WIDTH - platform_gap;
	platform[1].width = SCREEN_WIDTH - platform_gap;
	platform[2].width = SCREEN_WIDTH - platform_gap;
	platform[3].width = SCREEN_WIDTH - platform_gap;

	platform[0].y = SCREEN_HEIGHT - platform_gap - PLATFORM_HEIGHT;
	platform[1].y = SCREEN_HEIGHT - platform_gap * 2 - PLATFORM_HEIGHT;
	platform[2].y = SCREEN_HEIGHT - platform_gap * 3 - PLATFORM_HEIGHT;
	platform[3].y = SCREEN_HEIGHT - platform_gap * 4 - PLATFORM_HEIGHT;

	ladder[0].x = 2 * platform_gap;
	ladder[0].y = SCREEN_HEIGHT - PLATFORM_HEIGHT;
	ladder[0].width = LADDER_GAP;
	ladder[0].height = platform_gap;

	ladder[1].x = SCREEN_WIDTH - 2 * platform_gap;
	ladder[1].y = SCREEN_HEIGHT - platform_gap - PLATFORM_HEIGHT;
	ladder[1].width = LADDER_GAP;
	ladder[1].height = platform_gap;

	ladder[2].x = 2 * platform_gap;
	ladder[2].y = SCREEN_HEIGHT - 2 * platform_gap - PLATFORM_HEIGHT;
	ladder[2].width = LADDER_GAP;
	ladder[2].height = platform_gap;

	ladder[3].x = SCREEN_WIDTH - 2 * platform_gap;
	ladder[3].y = SCREEN_HEIGHT - 3 * platform_gap - PLATFORM_HEIGHT;
	ladder[3].width = LADDER_GAP;
	ladder[3].height = platform_gap;

	barrel[0].x = 0;
	barrel[0].y = platform[3].y - PLATFORM_HEIGHT;
	barrel[0].velocity = 100;

	barrel[1].x = 0;
	barrel[1].y = platform[3].y - PLATFORM_HEIGHT;
	barrel[1].velocity = 100;

	barrel[2].x = 0;
	barrel[2].y = platform[3].y - PLATFORM_HEIGHT;
	barrel[2].velocity = 100;

	barrel[3].x = 0;
	barrel[3].y = platform[3].y - PLATFORM_HEIGHT;
	barrel[3].velocity = 100;

	marioX = SCREEN_WIDTH - 0.5 * MARIO_WIDTH;
	marioY = SCREEN_HEIGHT - 0.5 * MARIO_WIDTH - PLATFORM_HEIGHT;

}
void level2(double& marioX, double& marioY, platforms(&platform)[4], ladders(&ladder)[4], barrels(&barrel)[4], int& level, int& marioLives, bool& coinPicked) {
	coinPicked = false;
	level = 2;
	platform_gap = 60;
	platform[0].x = platform_gap;
	platform[1].x = 0;
	platform[2].x = platform_gap;
	platform[3].x = 0;

	platform[0].width = SCREEN_WIDTH - (2 * platform_gap);
	platform[1].width = SCREEN_WIDTH;
	platform[2].width = SCREEN_WIDTH - 2 * platform_gap;
	platform[3].width = SCREEN_WIDTH - platform_gap;

	platform[0].y = SCREEN_HEIGHT - platform_gap - PLATFORM_HEIGHT;
	platform[1].y = SCREEN_HEIGHT - platform_gap * 2 - PLATFORM_HEIGHT;
	platform[2].y = SCREEN_HEIGHT - platform_gap * 3 - PLATFORM_HEIGHT;
	platform[3].y = SCREEN_HEIGHT - platform_gap * 4 - PLATFORM_HEIGHT;

	ladder[0].x = 2 * platform_gap;
	ladder[0].y = SCREEN_HEIGHT - PLATFORM_HEIGHT;
	ladder[0].width = LADDER_GAP;
	ladder[0].height = platform_gap;

	ladder[1].x = SCREEN_WIDTH - 2 * platform_gap + LADDER_GAP;
	ladder[1].y = SCREEN_HEIGHT - platform_gap - PLATFORM_HEIGHT;
	ladder[1].width = LADDER_GAP;
	ladder[1].height = platform_gap;

	ladder[2].x = 2 * platform_gap;
	ladder[2].y = SCREEN_HEIGHT - 2 * platform_gap - PLATFORM_HEIGHT;
	ladder[2].width = LADDER_GAP;
	ladder[2].height = platform_gap;

	ladder[3].x = SCREEN_WIDTH - 2 * platform_gap + LADDER_GAP;
	ladder[3].y = SCREEN_HEIGHT - 3 * platform_gap - PLATFORM_HEIGHT;
	ladder[3].width = LADDER_GAP;
	ladder[3].height = platform_gap;

	barrel[0].x = 0;
	barrel[0].y = platform[3].y - PLATFORM_HEIGHT;
	barrel[0].velocity = 100;

	barrel[1].x = 0;
	barrel[1].y = platform[3].y - PLATFORM_HEIGHT;
	barrel[1].velocity = 100;

	barrel[2].x = 0;
	barrel[2].y = platform[3].y - PLATFORM_HEIGHT;
	barrel[2].velocity = 100;

	barrel[3].x = 0;
	barrel[3].y = platform[3].y - PLATFORM_HEIGHT;
	barrel[3].velocity = 100;

	marioX = SCREEN_WIDTH - 0.5 * MARIO_WIDTH;
	marioY = SCREEN_HEIGHT - 0.5 * MARIO_WIDTH - PLATFORM_HEIGHT;
}
void level3(double& marioX, double& marioY, platforms(&platform)[4], ladders(&ladder)[4], barrels(&barrel)[4], int& level, int& marioLives, bool& coinPicked) {
	coinPicked = false;

	level = 3;

	platform_gap = 90;

	platform[0].x = platform_gap;
	platform[1].x = 0;
	platform[2].x = 0;
	platform[3].x = platform_gap;

	platform[0].width = SCREEN_WIDTH - platform_gap;
	platform[1].width = SCREEN_WIDTH - platform_gap;
	platform[2].width = SCREEN_WIDTH - platform_gap;
	platform[3].width = SCREEN_WIDTH - platform_gap;

	platform[0].y = SCREEN_HEIGHT - platform_gap - PLATFORM_HEIGHT;
	platform[1].y = SCREEN_HEIGHT - platform_gap * 2 - PLATFORM_HEIGHT;
	platform[2].y = SCREEN_HEIGHT - platform_gap * 3 - PLATFORM_HEIGHT;
	platform[3].y = SCREEN_HEIGHT - platform_gap * 4 - PLATFORM_HEIGHT;

	ladder[0].x = 2 * platform_gap + LADDER_GAP;
	ladder[0].y = SCREEN_HEIGHT - PLATFORM_HEIGHT;
	ladder[0].width = LADDER_GAP;
	ladder[0].height = platform_gap;

	ladder[1].x = SCREEN_WIDTH - 2 * platform_gap - 2 * LADDER_GAP;
	ladder[1].y = SCREEN_HEIGHT - platform_gap - PLATFORM_HEIGHT;
	ladder[1].width = LADDER_GAP;
	ladder[1].height = platform_gap;

	ladder[2].x = 2 * platform_gap + 2 * LADDER_GAP;
	ladder[2].y = SCREEN_HEIGHT - 2 * platform_gap - PLATFORM_HEIGHT;
	ladder[2].width = LADDER_GAP;
	ladder[2].height = platform_gap;

	ladder[3].x = SCREEN_WIDTH - 2 * platform_gap - LADDER_GAP;
	ladder[3].y = SCREEN_HEIGHT - 3 * platform_gap - PLATFORM_HEIGHT;
	ladder[3].width = LADDER_GAP;
	ladder[3].height = platform_gap;

	barrel[0].x = SCREEN_WIDTH;
	barrel[0].y = platform[3].y - PLATFORM_HEIGHT;
	barrel[0].velocity = 100;

	barrel[1].x = SCREEN_WIDTH;
	barrel[1].y = platform[3].y - PLATFORM_HEIGHT;
	barrel[1].velocity = 100;

	barrel[2].x = SCREEN_WIDTH;
	barrel[2].y = platform[3].y - PLATFORM_HEIGHT;
	barrel[2].velocity = 100;

	barrel[3].x = SCREEN_WIDTH;
	barrel[3].y = platform[3].y - PLATFORM_HEIGHT;
	barrel[3].velocity = 100;

	marioX = SCREEN_WIDTH - 0.5 * MARIO_WIDTH;
	marioY = SCREEN_HEIGHT - 0.5 * MARIO_WIDTH - PLATFORM_HEIGHT;
}
void DrawPlatforms(int level, SDL_Surface* screen, Uint32 red, Uint32 blue, Uint32 yellow, Uint32 green, platforms(&platform)[4]) {
	Uint32 activecolor = blue;
	if (level == 1)
		activecolor = blue;
	if (level == 2) {
		activecolor = red;
		DrawRectangle(screen, SCREEN_WIDTH * 0.5 - platform_gap, platform[0].y + 0.5 * platform_gap, 2 * platform_gap, PLATFORM_HEIGHT, activecolor, activecolor);
	}
	if (level == 3) {
		activecolor = green;
	}
	DrawRectangle(screen, SCREEN_WIDTH, SCREEN_HEIGHT - PLATFORM_HEIGHT, SCREEN_WIDTH, PLATFORM_HEIGHT, activecolor, activecolor);
	DrawRectangle(screen, platform[0].x, platform[0].y, platform[0].width, PLATFORM_HEIGHT, activecolor, activecolor);
	DrawRectangle(screen, platform[1].x, platform[1].y, platform[1].width, PLATFORM_HEIGHT, activecolor, activecolor);
	DrawRectangle(screen, platform[2].x, platform[2].y, platform[2].width, PLATFORM_HEIGHT, activecolor, activecolor);
	DrawRectangle(screen, platform[3].x, platform[3].y, platform[3].width, PLATFORM_HEIGHT, activecolor, activecolor);
}
void DrawLadders(int level, SDL_Surface* screen, Uint32 red, Uint32 blue, Uint32 yellow, Uint32 green, ladders(&ladder)[4]) {
	Uint32 activecolor;
	if (level == 1) {
		activecolor = red;
	}
	if (level == 2) {
		activecolor = blue;
	}
	if (level == 3) {
		activecolor = yellow;
	}
	DrawRectangle(screen, ladder[0].x, ladder[0].y - platform_gap, LADDER_WIDTH, platform_gap, activecolor, activecolor);
	DrawRectangle(screen, ladder[0].x + LADDER_GAP, ladder[0].y - platform_gap, LADDER_WIDTH, platform_gap, activecolor, activecolor);
	for (int i = 20; i < platform_gap; i += LADDER_GAP)
		DrawRectangle(screen, ladder[0].x, ladder[0].y - i, LADDER_GAP, 3, activecolor, activecolor);

	DrawRectangle(screen, ladder[1].x, ladder[1].y - platform_gap, LADDER_WIDTH, platform_gap, activecolor, activecolor);
	DrawRectangle(screen, ladder[1].x - LADDER_GAP, ladder[1].y - platform_gap, LADDER_WIDTH, platform_gap, activecolor, activecolor);
	for (int i = 20; i < platform_gap; i += LADDER_GAP)
		DrawRectangle(screen, ladder[1].x - LADDER_GAP, ladder[1].y - i, LADDER_GAP, 3, activecolor, activecolor);

	DrawRectangle(screen, ladder[2].x, ladder[2].y - platform_gap, LADDER_WIDTH, platform_gap, activecolor, activecolor);
	DrawRectangle(screen, ladder[2].x + LADDER_GAP, ladder[2].y - platform_gap, LADDER_WIDTH, platform_gap, activecolor, activecolor);
	for (int i = 20; i < platform_gap; i += LADDER_GAP)
		DrawRectangle(screen, ladder[2].x, ladder[2].y - i, LADDER_GAP, 3, activecolor, activecolor);

	DrawRectangle(screen, ladder[3].x, ladder[3].y - platform_gap, LADDER_WIDTH, platform_gap, activecolor, activecolor);
	DrawRectangle(screen, ladder[3].x - LADDER_GAP, ladder[3].y - platform_gap, LADDER_WIDTH, platform_gap, activecolor, activecolor);
	for (int i = 20; i < platform_gap; i += LADDER_GAP)
		DrawRectangle(screen, ladder[3].x - LADDER_GAP, ladder[3].y - i, LADDER_GAP, 3, activecolor, activecolor);
}
void DrawBoard(int level, SDL_Surface* screen, Uint32 red, Uint32 blue, Uint32 yellow, Uint32 green, platforms(&platform)[4], ladders(&ladder)[4]) {
	DrawPlatforms(level, screen, red, blue, yellow, green, platform);
	DrawLadders(level, screen, red, blue, yellow, green, ladder);
}
void frames_reset(int& frames, double& fpsTimer, double& fps, int& quit, double& worldTime, double& marioX, double& marioY) {
	frames = 0;
	fpsTimer = 0;
	fps = 0;
	quit = 0;
	worldTime = 0;
	marioX = SCREEN_WIDTH - 0.5 * MARIO_WIDTH;
	marioY = SCREEN_HEIGHT - 0.5 * MARIO_WIDTH - PLATFORM_HEIGHT;
}
void Refresh_screen(SDL_Renderer* renderer, SDL_Texture* scrtex, SDL_Surface* screen, SDL_Surface* mario, SDL_Surface* charset, SDL_Surface* barrelbmp, SDL_Surface* coin, char text[128], Uint32 red, Uint32 blue, Uint32 yellow, Uint32 green, int& score, int& gameState, int& marioLives, int marioX, int marioY, int level, int num_Deaths, double worldTime, double fps, bool coinPicked, platforms(&platform)[4], ladders(&ladder)[4], barrels(&barrel)[4]) {
	DrawRectangle(screen, 4, 4, SCREEN_WIDTH - 8, 36, red, blue);
	sprintf(text, "World Time: %.1lf s, FPS:  %.0lf Death counter: %d  ", worldTime, fps, num_Deaths);
	DrawString(screen, screen->w / 2 - strlen(text) * 8 / 2, 10, text, charset);
	sprintf(text, "Esc - Quit, n - New Game");
	DrawString(screen, screen->w / 2 - strlen(text) * 8 / 2, 26, text, charset);
	if (gameState) {
		DrawBoard(level, screen, red, blue, yellow, green, platform, ladder);
		DrawSurface(screen, mario, marioX, marioY);
		if (!coinPicked) {
			DrawSurface(screen, coin, platform_gap + 0.5 * MARIO_WIDTH, platform[2].y - 0.5 * MARIO_WIDTH);
		}
		sprintf(text, "Lives left: %d  ", marioLives);
		DrawString(screen, screen->w / 2 - strlen(text) * 8 / 2, 50, text, charset);
		sprintf(text, "Score: %d  ", score);
		DrawString(screen, 0, 50, text, charset);
		sprintf(text, "Level: %d  ", level);
		DrawString(screen, SCREEN_WIDTH - 75, 50, text, charset);
		for (int i = 0; i < 4; i++) {
			if (worldTime > 7.5 * i) {
				DrawSurface(screen, barrelbmp, barrel[i].x, barrel[i].y);
			}
		}
	}
	SDL_UpdateTexture(scrtex, NULL, screen->pixels, screen->pitch);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, scrtex, NULL, NULL);
	SDL_RenderPresent(renderer);
}
void move_barrels(barrels(&barrel)[4], double delta, double worldTime) {
	for (int i = 0; i < BARREL_AMOUNT; i++) {
		if (worldTime > TIME_BET_BARRELLS * i) {
			barrel[i].x += barrel[i].velocity * delta;
			if (barrel[i].x > SCREEN_WIDTH - 0.5 * BARREL_WIDTH) {
				barrel[i].velocity = -100;
				return;
			}
			if (barrel[i].x < 0.5 * BARREL_WIDTH) {
				barrel[i].velocity = 100;
				return;
			}
		}
	}
}
void barrelcheck_leftMove(int level, barrels(&barrel)[4], platforms(&platform)[4], double worldTime) {
	for (int i = 0; i < BARREL_AMOUNT; i++) {
		if (worldTime > TIME_BET_BARRELLS * i) {
			if (level == 1) {
				if (barrel[i].x < platform[0].x - 0.5 * BARREL_WIDTH && barrel[i].y < SCREEN_HEIGHT - PLATFORM_HEIGHT - 0.5 * BARREL_WIDTH && barrel[i].y > platform[1].y) {
					barrel[i].Barrel_falling_fromPlatform[0] = 1;
					continue;
				}
				if (barrel[i].x < platform[2].x - 0.5 * BARREL_WIDTH && barrel[i].y < platform[2].y && barrel[i].y > platform[3].y) {
					barrel[i].Barrel_falling_fromPlatform[2] = 1;
					continue;
				}
			}
			else if (level == 2) {
				if (barrel[i].x < BARREL_WIDTH && barrel[i].y > platform[2].y) {
					barrel[i].x = 0;
					barrel[i].y = platform[3].y - PLATFORM_HEIGHT;
				}
				if (barrel[i].x < platform[0].x - 0.5 * BARREL_WIDTH && barrel[i].y < SCREEN_HEIGHT && barrel[i].y > platform[1].y) {
					barrel[i].Barrel_falling_fromPlatform[0] = 1;
					continue;
				}
				if (barrel[i].x < platform[2].x - 0.5 * BARREL_WIDTH && barrel[i].y < platform[2].y && barrel[i].y > platform[3].y) {
					barrel[i].Barrel_falling_fromPlatform[2] = 1;
					continue;
				}
			}
			else if (level == 3) {
				if (barrel[i].x < platform[0].x - 0.5 * BARREL_WIDTH && barrel[i].y < SCREEN_HEIGHT - PLATFORM_HEIGHT - 0.5 * BARREL_WIDTH && barrel[i].y > platform[1].y) {
					barrel[i].Barrel_falling_fromPlatform[0] = 1;
					continue;
				}
				if (barrel[i].x < platform[2].x - 0.5 * BARREL_WIDTH && barrel[i].y < platform[2].y && barrel[0].y > platform[3].y) {
					barrel[i].Barrel_falling_fromPlatform[2] = 1;
					continue;
				}
				if (barrel[i].x < platform[3].x - 0.5 * BARREL_WIDTH && barrel[i].y < platform[3].y) {
					barrel[i].Barrel_falling_fromPlatform[3] = 1;
					continue;
				}
			}
		}
	}
}
void barrelcheck_RightMove(int level, int(&barrel_collision)[4], int(&barrel_jumped)[4], barrels(&barrel)[4], platforms(&platform)[4], double worldTime) {
	for (int i = 0; i < BARREL_AMOUNT; i++) {
		if (worldTime > TIME_BET_BARRELLS * i) {
			if (barrel[i].x > SCREEN_WIDTH - BARREL_WIDTH && barrel[i].y > platform[0].y) {
				if (level == 1 || level == 2)
					barrel[i].x = 0;
				else if (level == 3)
					barrel[i].x = SCREEN_WIDTH;
				barrel_jumped[i] = 0;
				barrel_collision[i] = 0;
				barrel[i].y = platform[3].y - PLATFORM_HEIGHT;
				continue;
			}
			if (level == 1) {
				if (barrel[i].x > platform[1].width + 0.5 * MARIO_WIDTH && barrel[i].y<platform[1].y && barrel[i].y>platform[2].y) {
					barrel[i].Barrel_falling_fromPlatform[1] = 1;
					continue;
				}
				if (barrel[i].x > platform[3].width + 0.5 * MARIO_WIDTH && barrel[i].y < platform[3].y) {
					barrel[i].Barrel_falling_fromPlatform[3] = 1;
					continue;
				}
			}
			else if (level == 2) {
				if ((barrel[i].x < platform[0].x - 0.5 * MARIO_WIDTH && barrel[i].y < SCREEN_HEIGHT && barrel[i].y > platform[1].y) || (barrel[i].x > platform[0].width + platform[0].x && barrel[i].x < SCREEN_HEIGHT && barrel[i].x > platform[1].y)) {
					barrel[i].Barrel_falling_fromPlatform[0] = 1;
					continue;
				}
				if (barrel[i].x > platform[2].width + platform[2].x && barrel[i].y < platform[2].y && barrel[i].y > platform[3].y) {
					barrel[i].Barrel_falling_fromPlatform[3] = 1;
					continue;
				}
				if (barrel[i].x > platform[3].width + 0.5 * MARIO_WIDTH && barrel[i].y < platform[3].y) {
					barrel[i].Barrel_falling_fromPlatform[2] = 1;
					continue;
				}
			}
			else if (level == 3) {
				if (barrel[i].x > platform[1].width + 0.5 * MARIO_WIDTH && barrel[i].y<platform[1].y && barrel[i].y>platform[2].y) {
					barrel[i].Barrel_falling_fromPlatform[3] = 1;
					continue;
				}
				if (barrel[i].x > platform[2].width + 0.5 * MARIO_WIDTH && barrel[i].y<platform[2].y && barrel[i].y>platform[3].y) {
					barrel[i].Barrel_falling_fromPlatform[1] = 1;
					continue;
				}
				if (barrel[i].x > platform[3].width + platform[3].x + 0.5 * MARIO_WIDTH && barrel[i].y < platform[3].y) {
					barrel[i].Barrel_falling_fromPlatform[3] = 1;
					continue;
				}
			}
		}
	}
}
void display_menu(SDL_Surface* screen, SDL_Renderer* renderer, SDL_Texture* scrtex, SDL_Surface* charset, char text[128], Uint32 black) {
	sprintf(text, "Press 1, 2 or 3 to choose level");
	DrawString(screen, screen->w / 2 - strlen(text) * 8 / 2, screen->h / 2, text, charset);
	sprintf(text, "Press Esc to quit");
	DrawString(screen, screen->w / 2 - strlen(text) * 8 / 2, screen->h / 2 + 24, text, charset);
	sprintf(text, "Press 's' to show scoreboard");
	DrawString(screen, screen->w / 2 - strlen(text) * 8 / 2, screen->h / 2 + 48, text, charset);
	SDL_UpdateTexture(scrtex, NULL, screen->pixels, screen->pitch);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, scrtex, NULL, NULL);
	SDL_RenderPresent(renderer);
	SDL_FillRect(screen, NULL, black);
}
void check_collision(int& score, int& level, int& gameState, int& num_Deaths, double& marioX, double& marioY, double& delta, int(&barrel_jumped)[4], int(&barrel_collision)[4], barrels(&barrel)[4], platforms(&platform)[4], ladders(&ladder)[4], int& frames, double& fpsTimer, double& fps, int& quit, int& marioLives, double& worldTime, bool& coinPicked, bool jumping, bool falling) {
	if (!coinPicked) {
		if (marioX > platform_gap && marioX < platform_gap + MARIO_WIDTH && marioY > platform[2].y - MARIO_WIDTH && marioY < platform[2].y) {
			score += 200;
			coinPicked = true;
		}
	}
	for (int i = 0; i < 4; i++) {
		if (marioX > barrel[i].x - 0.5 * MARIO_WIDTH && marioX < barrel[i].x + BARREL_WIDTH && marioY < barrel[i].y - 0.5 * MARIO_WIDTH && marioY > barrel[i].y - MAX_JUMP && !barrel_jumped[i] && (jumping || falling)) {
			barrel_jumped[i] = 1;
			score += 50;
		}
		if (marioX > barrel[i].x - 0.5 * MARIO_WIDTH && marioX < barrel[i].x + BARREL_WIDTH && marioY > barrel[i].y - 0.5 * MARIO_WIDTH && marioY < barrel[i].y + BARREL_WIDTH && !barrel_collision[i]) {
			barrel_collision[i] = 1;
			num_Deaths++;
			marioLives--;
			gameState = 2;
			if (marioLives == 0) {
				gameState = 3;
				return;
			}
			return;
		}
	}
}
void saveScore(char nick[50], int score) {
	char save_nick[50];
	for (int i = 1; i < 50; i++) {
		save_nick[i - 1] = nick[i];
	}
	FILE* file = fopen("scoreboard.txt", "a");
	if (file == NULL) {
		printf("B≥πd podczas otwierania pliku.\n");
		exit(1);
	}
	fprintf(file, "%s %d\n", save_nick, score);

	fclose(file);
}
void display_saveScore(char nick[50], bool nickname, char text[128], SDL_Surface* charset, SDL_Surface* screen, SDL_Texture* scrtex, SDL_Renderer* renderer, Uint32 black) {
	if (!nickname) {
		sprintf(text, "Do you want to save your score?");
		DrawString(screen, screen->w / 2 - strlen(text) * 8 / 2, screen->h / 2, text, charset);
		sprintf(text, "'y' - Yes, 'n' - No");
		DrawString(screen, screen->w / 2 - strlen(text) * 8 / 2, screen->h / 2 + 24, text, charset);
	}
	else {
		sprintf(text, "Enter your nickname: ");
		DrawString(screen, screen->w / 2 - strlen(text) * 8 / 2, screen->h / 2, text, charset);
		char save_nick[50];
		for (int i = 1; i < 50; i++) {
			save_nick[i - 1] = nick[i];
		}
		sprintf(text, "%s", save_nick);
		DrawString(screen, screen->w / 2 + 80, screen->h / 2, text, charset);
	}
	SDL_UpdateTexture(scrtex, NULL, screen->pixels, screen->pitch);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, scrtex, NULL, NULL);
	SDL_RenderPresent(renderer);
	SDL_FillRect(screen, NULL, black);
}
void display_continueScreen(char text[128], SDL_Surface* charset, SDL_Surface* screen, int& score) {
	sprintf(text, "Do you want to continue?");
	DrawString(screen, screen->w / 2 - strlen(text) * 8 / 2, NOTIFICATION_HEIGHT, text, charset);
	sprintf(text, "'y' - Yes, 'n' - No");
	DrawString(screen, screen->w / 2 - strlen(text) * 8 / 2, NOTIFICATION_HEIGHT + 15, text, charset);
	sprintf(text, "Score: %d ", score);
	DrawString(screen, screen->w / 2 - strlen(text) * 8 / 2, NOTIFICATION_HEIGHT + 30, text, charset);
}
void display_scoreboard(char text[128], SDL_Surface* charset, SDL_Surface* screen, SDL_Texture* scrtex, SDL_Renderer* renderer, Uint32 black) {
	FILE* file = fopen("sorted_scoreboard.txt", "r");
	ScoreEntry entry;
	int count = 0;

	while (fscanf(file, "%s %d", entry.nickname, &entry.score) == 2) {
		sprintf(text, "%d. %s %d\0\n", count + 1, entry.nickname, entry.score);
		DrawString(screen, SCREEN_WIDTH / 2 - strlen(text) * 8 / 2, SCREEN_HEIGHT / 4 + count * 15, text, charset);
		count++;
	}
	fclose(file);

	SDL_UpdateTexture(scrtex, NULL, screen->pixels, screen->pitch);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, scrtex, NULL, NULL);
	SDL_RenderPresent(renderer);
	SDL_FillRect(screen, NULL, black);
}
int compareEntries(const void* a, const void* b) {
	return ((ScoreEntry*)b)->score - ((ScoreEntry*)a)->score;
}
void sortAndWriteToFile(const char* inputFileName, const char* outputFileName) {
	FILE* inputFile, * outputFile;

	if ((inputFile = fopen(inputFileName, "r")) == NULL) {
		perror("Nie moøna otworzyÊ pliku wejúciowego");
		exit(EXIT_FAILURE);
	}

	if ((outputFile = fopen(outputFileName, "w")) == NULL) {
		perror("Nie moøna otworzyÊ pliku wyjúciowego");
		fclose(inputFile);
		exit(EXIT_FAILURE);
	}

	int maxEntries = 100;
	ScoreEntry* scoreboard = (ScoreEntry*)malloc(maxEntries * sizeof(ScoreEntry));
	int entryCount = 0;
	if (scoreboard == NULL) {
		perror("B≥πd alokacji pamiÍci");
		exit(EXIT_FAILURE);
	}

	while (fscanf(inputFile, "%s %d", scoreboard[entryCount].nickname, &scoreboard[entryCount].score) == 2) {
		entryCount++;
		if (entryCount >= maxEntries) {
			maxEntries *= 2;
		}
	}
	qsort(scoreboard, entryCount, sizeof(ScoreEntry), compareEntries);

	for (int i = 0; i < entryCount; i++) {
		fprintf(outputFile, "%s %d\n", scoreboard[i].nickname, scoreboard[i].score);
	}

	free(scoreboard);
	fclose(inputFile);
	fclose(outputFile);
}

bool check_levelEnd(bool& coinPicked, int& score, int& level, double& marioX, double& marioY, platforms(&platform)[4], ladders(&ladder)[4], barrels(&barrel)[4], int& frames, double& fpsTimer, double& fps, int& gameState, int& quit, int& marioLives, double& worldTime)
{
	if (level == 1 || level == 2) {
		if (marioX < 0.5 * MARIO_WIDTH + platform_gap && marioY < platform[3].y) {
			level++;
			if (level == 2) {
				score += 500;
				level2(marioX, marioY, platform, ladder, barrel, level, marioLives, coinPicked);
				frames_reset(frames, fpsTimer, fps, quit, worldTime, marioX, marioY);
				return true;
			}
			else if (level == 3) {
				score += 500;
				level3(marioX, marioY, platform, ladder, barrel, level, marioLives, coinPicked);
				frames_reset(frames, fpsTimer, fps, quit, worldTime, marioX, marioY);
				return true;
			}
		}
	}
	else if (level == 3) {
		if (marioX > SCREEN_WIDTH - platform_gap - 0.5 * MARIO_WIDTH && marioY < platform[3].y) {
			gameState = 3;
			score += 500;
		}
	}
	return false;
}
bool ladderLimitsUp(int marioX, int marioY, ladders(&ladder)[4]) {
	if (marioX > ladder[0].x && marioX < ladder[0].x + ladder[0].width && marioY > ladder[1].y - 0.5 * MARIO_WIDTH - PLATFORM_HEIGHT + MARIO_STEP && marioY < ladder[0].y - 0.5 * MARIO_WIDTH + MARIO_STEP) {
		return true;
	}
	if (marioX < ladder[1].x && marioX > ladder[1].x - ladder[1].width && marioY > ladder[2].y - 0.5 * MARIO_WIDTH - PLATFORM_HEIGHT + MARIO_STEP && marioY < ladder[1].y - 0.5 * MARIO_WIDTH + MARIO_STEP) {
		return true;
	}
	if (marioX > ladder[2].x && marioX < ladder[2].x + ladder[2].width && marioY > ladder[3].y - 0.5 * MARIO_WIDTH - PLATFORM_HEIGHT + MARIO_STEP && marioY < ladder[2].y - 0.5 * MARIO_WIDTH + MARIO_STEP) {
		return true;
	}
	if (marioX < ladder[3].x && marioX > ladder[3].x - ladder[3].width && marioY > ladder[3].y - 0.5 * MARIO_WIDTH - platform_gap - PLATFORM_HEIGHT + MARIO_STEP && marioY < ladder[3].y - 0.5 * MARIO_WIDTH + MARIO_STEP) {
		return true;
	}
	return false;
}
bool ladderLimitsDown(int marioX, int marioY, ladders(&ladder)[4]) {
	if (marioX > ladder[0].x - 0.5 * MARIO_WIDTH && marioX < ladder[0].x + ladder[0].width + 0.5 * MARIO_WIDTH && marioY < ladder[0].y - 0.5 * MARIO_WIDTH + MARIO_STEP && marioY >= ladder[1].y - 0.5 * MARIO_WIDTH)
		return true;
	if (marioX < ladder[1].x + 0.5 * MARIO_WIDTH && marioX > ladder[1].x - ladder[1].width - 0.5 * MARIO_WIDTH && marioY < ladder[1].y - 0.5 * MARIO_WIDTH + MARIO_STEP && marioY >= ladder[2].y - 0.5 * MARIO_WIDTH)
		return true;
	if (marioX > ladder[0].x - 0.5 * MARIO_WIDTH && marioX < ladder[0].x + ladder[0].width + 0.5 * MARIO_WIDTH && marioY < ladder[2].y - 0.5 * MARIO_WIDTH + MARIO_STEP && marioY >= ladder[3].y - 0.5 * MARIO_WIDTH)
		return true;
	if (marioX < ladder[1].x + 0.5 * MARIO_WIDTH && marioX > ladder[1].x - ladder[1].width - 0.5 * MARIO_WIDTH && marioY > ladder[3].y - 0.5 * MARIO_WIDTH - platform_gap - PLATFORM_HEIGHT + MARIO_STEP && marioY < ladder[3].y - 0.5 * MARIO_WIDTH + MARIO_STEP)
		return true;
	return false;
}
bool check_leftMove(int level, double& marioX, double& marioY, double& marioSpeed, double delta, platforms platform[4], int(&falling_fromPlatform)[4]) {
	marioX -= marioSpeed * delta;
	if (marioX < 0.5 * MARIO_WIDTH) {
		marioX = 0.5 * MARIO_WIDTH;
		return true;
	}
	if (level == 1) {
		if (marioX < platform[0].x - 0.5 * MARIO_WIDTH && marioY < SCREEN_HEIGHT && marioY > platform[1].y) {
			falling_fromPlatform[0] = 1;
			return true;
		}
		if (marioX < platform[2].x - 0.5 * MARIO_WIDTH && marioY < platform[2].y && marioY > platform[3].y) {
			falling_fromPlatform[2] = 1;
			return true;
		}
	}
	else if (level == 2) {
		if (marioX < platform[0].x - 0.5 * MARIO_WIDTH && marioY < SCREEN_HEIGHT && marioY > platform[1].y) {
			falling_fromPlatform[0] = 1;
			return true;
		}
		if (marioX < platform[2].x - 0.5 * MARIO_WIDTH && marioY < platform[2].y && marioY > platform[3].y) {
			falling_fromPlatform[2] = 1;
			return true;
		}
		if (marioX < SCREEN_WIDTH * 0.5 - platform_gap - 0.5 * MARIO_WIDTH && marioY >platform[0].y - 0.5 * MARIO_WIDTH && marioY < SCREEN_HEIGHT - 0.5 * platform_gap) {
			falling_fromPlatform[0] = 1;
			return true;
		}
	}
	else if (level == 3) {
		if (marioX < platform[0].x - 0.5 * MARIO_WIDTH && marioY < SCREEN_HEIGHT && marioY > platform[1].y) {
			falling_fromPlatform[0] = 1;
			return true;
		}
		if (marioX < platform[2].x - 0.5 * MARIO_WIDTH && marioY < platform[2].y && marioY > platform[3].y) {
			falling_fromPlatform[2] = 1;
			return true;
		}
		if (marioX < platform[3].x - 0.5 * MARIO_WIDTH && marioY < platform[3].y) {
			falling_fromPlatform[3] = 1;
			return true;
		}
	}
	return true;
}
bool check_rightMove(int level, double& marioX, double& marioY, double& marioSpeed, double delta, platforms platform[4], int(&falling_fromPlatform)[4]) {
	marioX += marioSpeed * delta;
	if (marioX > SCREEN_WIDTH - 0.5 * MARIO_WIDTH) {
		marioX = SCREEN_WIDTH - 0.5 * MARIO_WIDTH;
		return true;
	}
	if (level == 1) {
		if (marioX > platform[1].width + 0.5 * MARIO_WIDTH && marioY<platform[1].y && marioY>platform[2].y) {
			falling_fromPlatform[1] = 1;
			return true;
		}
		if (marioX > platform[3].width + 0.5 * MARIO_WIDTH && marioY < platform[3].y) {
			falling_fromPlatform[3] = 1;
			return true;
		}
	}
	else if (level == 2) {
		if ((marioX < platform[0].x - 0.5 * MARIO_WIDTH && marioY < SCREEN_HEIGHT && marioY > platform[1].y) || (marioX > platform[0].width + platform[0].x && marioY < SCREEN_HEIGHT && marioY > platform[1].y)) {
			falling_fromPlatform[0] = 1;
			return true;
		}
		if (marioX > platform[2].width + platform[2].x && marioY < platform[2].y && marioY > platform[3].y) {
			falling_fromPlatform[2] = 1;
			return true;
		}
		if (marioX > platform[3].width + 0.5 * MARIO_WIDTH && marioY < platform[3].y) {
			falling_fromPlatform[3] = 1;
			return true;
		}
		if (marioX > SCREEN_WIDTH * 0.5 + platform_gap + 0.5 * MARIO_WIDTH && marioY > platform[0].y - 0.5 * MARIO_WIDTH && marioY < SCREEN_HEIGHT - 0.5 * platform_gap) {
			falling_fromPlatform[0] = 1;
			return true;
		}
	}
	else if (level == 3) {
		if (marioX > platform[1].width + 0.5 * MARIO_WIDTH && marioY<platform[1].y && marioY>platform[2].y) {
			falling_fromPlatform[1] = 1;
			return true;
		}
		if (marioX > platform[2].width + 0.5 * MARIO_WIDTH && marioY<platform[2].y && marioY>platform[3].y) {
			falling_fromPlatform[2] = 1;
			return true;
		}
		if (marioX > platform[3].width + platform[3].x + 0.5 * MARIO_WIDTH && marioY < platform[3].y) {
			falling_fromPlatform[3] = 1;
			return true;
		}
	}
	return true;
}
bool check_bmps(SDL_Renderer* renderer, SDL_Window* window, SDL_Texture* scrtex, SDL_Surface* screen, SDL_Surface* charset, SDL_Surface* mario, SDL_Surface* mario_left, SDL_Surface* mario_right, SDL_Surface* bmp_barrel, SDL_Surface* coin) {
	if (charset == NULL) {
		printf("SDL_LoadBMP(cs8x8.bmp) error: %s\n", SDL_GetError());
		SDL_FreeSurface(screen);
		SDL_DestroyTexture(scrtex);
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		return true;
	}
	SDL_SetColorKey(charset, true, 0x000000);
	if (mario == NULL) {
		printf("SDL_LoadBMP(mario.bmp) error: %s\n", SDL_GetError());
		SDL_FreeSurface(screen);
		SDL_DestroyTexture(scrtex);
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		return true;
	}
	if (mario_left == NULL) {
		printf("SDL_LoadBMP(mario_left.bmp) error: %s\n", SDL_GetError());
		SDL_FreeSurface(screen);
		SDL_DestroyTexture(scrtex);
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		return true;
	}
	if (mario_right == NULL) {
		printf("SDL_LoadBMP(mario.bmp) error: %s\n", SDL_GetError());
		SDL_FreeSurface(screen);
		SDL_DestroyTexture(scrtex);
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		return true;
	}
	if (bmp_barrel == NULL) {
		printf("SDL_LoadBMP(barrel.bmp) error: %s\n", SDL_GetError());
		SDL_FreeSurface(screen);
		SDL_DestroyTexture(scrtex);
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		return true;
	}
	if (coin == NULL) {
		printf("SDL_LoadBMP(coin.bmp) error: %s\n", SDL_GetError());
		SDL_FreeSurface(screen);
		SDL_DestroyTexture(scrtex);
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		return true;
	}
	return false;
}
bool sdl_config(int& rc, SDL_Window* (&window), SDL_Renderer* (&renderer), SDL_Surface* (&screen), SDL_Texture* (&scrtex)) {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		printf("SDL_Init error: %s\n", SDL_GetError());
		return 1;
	}
	rc = SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer);
	if (rc != 0) {
		SDL_Quit();
		printf("SDL_CreateWindowAndRenderer error: %s\n", SDL_GetError());
		return 1;
	};
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_SetWindowTitle(window, "Szablon do zdania drugiego 2017");
	screen = SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_HEIGHT, 32, 0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);
	scrtex = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, SCREEN_WIDTH, SCREEN_HEIGHT);
	SDL_ShowCursor(SDL_DISABLE);
}

void handleEvents(SDL_Event event, int& gameState, int& level, int& frames, int& num_Deaths, int& quit, int& marioLives, double& fpsTimer, double& delta, double& fps, double& worldTime, int& marioSavedY, double& marioX, double& marioY, double& marioSpeed, bool& isOnLadder, bool& jumping, bool& falling, bool& coinPicked, platforms(&platform)[4], ladders(&ladder)[4], barrels(&barrel)[4], SDL_Surface* (&mario), SDL_Surface* mario_left, SDL_Surface* mario_right, int(&falling_fromPlatform)[4]) {
	switch (event.key.keysym.sym) {
	case SDLK_1:
		marioLives = 3;
		level1(marioX, marioY, platform, ladder, barrel, level, marioLives, coinPicked);
		frames_reset(frames, fpsTimer, fps, quit, worldTime, marioX, marioY);
		break;
	case SDLK_2:
		marioLives = 3;
		level2(marioX, marioY, platform, ladder, barrel, level, marioLives, coinPicked);
		frames_reset(frames, fpsTimer, fps, quit, worldTime, marioX, marioY);
		break;
	case SDLK_3:
		marioLives = 3;
		level3(marioX, marioY, platform, ladder, barrel, level, marioLives, coinPicked);
		frames_reset(frames, fpsTimer, fps, quit, worldTime, marioX, marioY);
		break;
	case SDLK_n:
		frames_reset(frames, fpsTimer, fps, quit, worldTime, marioX, marioY);
		num_Deaths = 0;
		break;
	case SDLK_ESCAPE:
		gameState = 0;
		break;
	case SDLK_UP:
		marioY -= marioSpeed;
		if (ladderLimitsUp(marioX, marioY, ladder)) {
			isOnLadder = true;
			break;
		}
		else
			isOnLadder = false;
		marioY += marioSpeed;
		break;
	case SDLK_DOWN:
		marioY += marioSpeed;
		if (ladderLimitsDown(marioX, marioY, ladder)) {
			isOnLadder = true;
			break;
		}
		else {
			isOnLadder = false;
		}
		marioY -= marioSpeed;
		break;
	case SDLK_LEFT:
		if (isOnLadder)
			break;
		mario = mario_left;
		if (check_leftMove(level, marioX, marioY, marioSpeed, delta, platform, falling_fromPlatform))
			break;
	case SDLK_RIGHT:
		if (isOnLadder)
			break;
		mario = mario_right;
		if (check_rightMove(level, marioX, marioY, marioSpeed, delta, platform, falling_fromPlatform))
			break;
	case SDLK_SPACE:
		if (jumping || falling)
			break;
		jumping = true;
		marioSavedY = marioY;
		break;
	};
}
void handleMenu(SDL_Event event, int& gameState, double& marioX, double& marioY, platforms(&platform)[4], ladders(&ladder)[4], barrels(&barrel)[4], int& quit, int& frames, double& fpsTimer, double& fps, double& worldTime, int& level, int& marioLives, bool& coinPicked) {
	switch (event.key.keysym.sym) {
	case SDLK_1:
		gameState = 1;
		marioLives = 3;
		level1(marioX, marioY, platform, ladder, barrel, level, marioLives, coinPicked);
		frames_reset(frames, fpsTimer, fps, quit, worldTime, marioX, marioY);
		break;
	case SDLK_2:
		gameState = 1;
		marioLives = 3;
		level2(marioX, marioY, platform, ladder, barrel, level, marioLives, coinPicked);
		frames_reset(frames, fpsTimer, fps, quit, worldTime, marioX, marioY);
		break;
	case SDLK_3:
		gameState = 1;
		marioLives = 3;
		level3(marioX, marioY, platform, ladder, barrel, level, marioLives, coinPicked);
		frames_reset(frames, fpsTimer, fps, quit, worldTime, marioX, marioY);
		break;
	case SDLK_ESCAPE:
		quit = 1;
		break;
	case SDLK_s:
		gameState = 4;
		sortAndWriteToFile("scoreboard.txt", "sorted_scoreboard.txt");
		break;
	case SDLK_n:
		break;
	}
}
void handleJump(bool& jumping, bool& falling, int& level, double& marioX, double& marioY, int& marioSavedY, double& jumpingVelocity, int(&falling_fromPlatform)[4], barrels(&barrel)[4], platforms(&platform)[4]) {
	for (int j = 0; j < BARREL_AMOUNT; j++) {
		for (int i = 0; i < PLATFORM_AMOUNT; i++) {
			if (barrel[j].Barrel_falling_fromPlatform[i]) {
				barrel[j].y -= 2 * jumpingVelocity;
				if (barrel[j].y >= platform[i].y - 0.5 * BARREL_WIDTH + platform_gap) {
					barrel[j].Barrel_falling_fromPlatform[i] = 0;
				}
			}
		}
	}

	for (int i = 0; i < PLATFORM_AMOUNT; i++) {
		if (falling_fromPlatform[i]) {
			jumping = false;
			marioY -= jumpingVelocity;
			if (marioY >= platform[i].y - 0.5 * MARIO_WIDTH + platform_gap) {
				falling_fromPlatform[i] = 0;
			}
		}
	}

	if (jumping) {
		if (level == 2 && marioX > SCREEN_WIDTH * 0.5 - platform_gap - 0.5 * MARIO_WIDTH && marioX<SCREEN_WIDTH * 0.5 + platform_gap + 0.5 * MARIO_WIDTH && marioY > SCREEN_HEIGHT - 0.5 * platform_gap - PLATFORM_HEIGHT && marioY < SCREEN_HEIGHT - 0.5 * platform_gap) {
			jumping = false;
			marioY = SCREEN_HEIGHT - 0.5 * platform_gap - PLATFORM_HEIGHT - 0.5 * MARIO_WIDTH;
		}
		if (level == 2 && marioX > SCREEN_WIDTH * 0.5 - platform_gap - 0.5 * MARIO_WIDTH && marioX < SCREEN_WIDTH * 0.5 + platform_gap + 0.5 * MARIO_WIDTH && marioY > platform[0].y - 0.5 * MARIO_WIDTH && marioY < platform[0].y) {
			jumping = false;
			marioY = platform[0].y - 0.5 * MARIO_WIDTH;
		}
		else {
			marioY += jumpingVelocity;
			if (marioSavedY - marioY >= MAX_JUMP) {
				falling = true;
				jumping = false;
			}
		}
	}

	if (falling) {
		marioY -= jumpingVelocity;
		if (marioSavedY - marioY <= 0) {
			falling = false;
		}
	}
}

