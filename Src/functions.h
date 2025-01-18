#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "defines.h"
#include "structs.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

extern "C" {
#include"./SDL2-2.0.10/include/SDL.h"
#include"./SDL2-2.0.10/include/SDL_main.h"
}


void DrawString(SDL_Surface* screen, int x, int y, const char* text, SDL_Surface* charset);
void DrawSurface(SDL_Surface* screen, SDL_Surface* sprite, int x, int y);
void DrawPixel(SDL_Surface* surface, int x, int y, Uint32 color);
void DrawLine(SDL_Surface* screen, int x, int y, int l, int dx, int dy, Uint32 color);
void DrawRectangle(SDL_Surface* screen, int x, int y, int l, int k, Uint32 outlineColor, Uint32 fillColor);
void level1(double& marioX, double& marioY, struct platforms(&platform)[4], struct ladders(&ladder)[4], struct barrels(&barrel)[4], int& level, int& marioLives, bool& coinPicked);
void level2(double& marioX, double& marioY, struct platforms(&platform)[4], struct ladders(&ladder)[4], struct barrels(&barrel)[4], int& level, int& marioLives, bool& coinPicked);
void level3(double& marioX, double& marioY, struct platforms(&platform)[4], struct ladders(&ladder)[4], struct barrels(&barrel)[4], int& level, int& marioLives, bool& coinPicked);
void DrawPlatforms(int level, SDL_Surface* screen, Uint32 red, Uint32 blue, Uint32 yellow, Uint32 green, struct platforms(&platform)[4]);
void DrawLadders(int level, SDL_Surface* screen, Uint32 red, Uint32 blue, Uint32 yellow, Uint32 green, struct ladders(&ladder)[4]);
void DrawBoard(int level, SDL_Surface* screen, Uint32 red, Uint32 blue, Uint32 yellow, Uint32 green, struct platforms(&platform)[4], struct ladders(&ladder)[4]);
void frames_reset(int& frames, double& fpsTimer, double& fps, int& quit, double& worldTime, double& marioX, double& marioY);
void Refresh_screen(SDL_Renderer* renderer, SDL_Texture* scrtex, SDL_Surface* screen, SDL_Surface* mario, SDL_Surface* charset, SDL_Surface* barrelbmp, SDL_Surface* coin, char text[128], Uint32 red, Uint32 blue, Uint32 yellow, Uint32 green, int& score, int& gameState, int& marioLives, int marioX, int marioY, int level, int num_Deaths, double worldTime, double fps, bool coinPicked, struct platforms(&platform)[4], struct ladders(&ladder)[4], struct barrels(&barrel)[4]);
void move_barrels(struct barrels(&barrel)[4], double delta, double worldTime);
void barrelcheck_leftMove(int level, struct barrels(&barrel)[4], struct platforms(&platform)[4], double worldTime);
void barrelcheck_RightMove(int level, int(&barrel_collision)[4], int(&barrel_jumped)[4], struct barrels(&barrel)[4], struct platforms(&platform)[4], double worldTime);
void display_menu(SDL_Surface* screen, SDL_Renderer* renderer, SDL_Texture* scrtex, SDL_Surface* charset, char text[128], Uint32 black);
void check_collision(int& score, int& level, int& gameState, int& num_Deaths, double& marioX, double& marioY, double& delta, int(&barrel_jumped)[4], int(&barrel_collision)[4], struct barrels(&barrel)[4], struct platforms(&platform)[4], struct ladders(&ladder)[4], int& frames, double& fpsTimer, double& fps, int& quit, int& marioLives, double& worldTime, bool& coinPicked, bool jumping, bool falling);
void saveScore(char nick[50], int score);
void display_saveScore(char nick[50], bool nickname, char text[128], SDL_Surface* charset, SDL_Surface* screen, SDL_Texture* scrtex, SDL_Renderer* renderer, Uint32 black);
void display_continueScreen(char text[128], SDL_Surface* charset, SDL_Surface* screen, int& score);
void display_scoreboard(char text[128], SDL_Surface* charset, SDL_Surface* screen, SDL_Texture* scrtex, SDL_Renderer* renderer, Uint32 black);
int compareEntries(const void* a, const void* b);
void sortAndWriteToFile(const char* inputFileName, const char* outputFileName);
bool check_levelEnd(bool& coinPicked, int& score, int& level, double& marioX, double& marioY, struct platforms(&platform)[4], struct ladders(&ladder)[4], struct barrels(&barrel)[4], int& frames, double& fpsTimer, double& fps, int& gameState, int& quit, int& marioLives, double& worldTime);
bool ladderLimitsUp(int marioX, int marioY, struct ladders(&ladder)[4]);
bool ladderLimitsDown(int marioX, int marioY, struct ladders(&ladder)[4]);
bool check_leftMove(int level, double& marioX, double& marioY, double& marioSpeed, double delta, struct platforms platform[4], int(&falling_fromPlatform)[4]);
bool check_rightMove(int level, double& marioX, double& marioY, double& marioSpeed, double delta, struct platforms platform[4], int(&falling_fromPlatform)[4]);
bool check_bmps(SDL_Renderer* renderer, SDL_Window* window, SDL_Texture* scrtex, SDL_Surface* screen, SDL_Surface* charset, SDL_Surface* mario, SDL_Surface* mario_left, SDL_Surface* mario_right, SDL_Surface* bmp_barrel, SDL_Surface* coin);
bool sdl_config(int& rc, SDL_Window* (&window), SDL_Renderer* (&renderer), SDL_Surface* (&screen), SDL_Texture* (&scrtex));
void handleEvents(SDL_Event event, int& gameState, int& level, int& frames, int& num_Deaths, int& quit, int& marioLives, double& fpsTimer, double& delta, double& fps, double& worldTime, int& marioSavedY, double& marioX, double& marioY, double& marioSpeed, bool& isOnLadder, bool& jumping, bool& falling, bool& coinPicked, struct platforms(&platform)[4], struct ladders(&ladder)[4], struct barrels(&barrel)[4], SDL_Surface* (&mario), SDL_Surface* mario_left, SDL_Surface* mario_right, int(&falling_fromPlatform)[4]);
void handleMenu(SDL_Event event, int& gameState, double& marioX, double& marioY, struct platforms(&platform)[4], struct ladders(&ladder)[4], struct barrels(&barrel)[4], int& quit, int& frames, double& fpsTimer, double& fps, double& worldTime, int& level, int& marioLives, bool& coinPicked);
void handleJump(bool& jumping, bool& falling, int& level, double& marioX, double& marioY, int& marioSavedY, double& jumpingVelocity, int(&falling_fromPlatform)[4], struct barrels(&barrel)[4], struct platforms(&platform)[4]);

#endif 