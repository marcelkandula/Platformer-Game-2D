#ifndef DEFINES_H
#define DEFINES_H

// all defines are in pixels
#define SCREEN_WIDTH	640 // width of screen
#define SCREEN_HEIGHT	480 // height of screen
#define PLATFORM_HEIGHT 6 // height of the platform
#define PLATFORM_WIDTH SCREEN_WIDTH - platform_gap
#define LADDER_WIDTH 3 // width one tangle of the ladder
#define LADDER_GAP 30 // gap between ladder tangles
#define MARIO_MAX_SPEED 5.0 //max speed of mario in pixels per frame
#define MARIO_WIDTH 32 //width and height of mario hitbox
#define MARIO_STEP 5 // how much mario moves in one step
#define MAX_JUMP 50 // max height of jump
#define BARREL_WIDTH 20 // width and height of barrel hitbox
#define BARREL_ACC 100 // acceleration of barrel
#define	MAX_BARELL_VELOCITY 5 // max velocity of barrel
#define BARREL_AMOUNT 4 // amount of barrels
#define PLATFORM_AMOUNT 4 // amount of platforms
#define TIME_BET_BARRELLS 7.5 // time between barrels
#define NOTIFICATION_HEIGHT 150 //height of continue notification 
#define L1_PLATFORM_GAP 90 // gap between platforms in level 1
#define MAX_NICK_LEN 50 // max length of nickname
#define PAGE_SIZE 5 // amount of entries on one page of scoreboard

#endif 
