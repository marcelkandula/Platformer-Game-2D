#ifndef STRUCTS_H
#define STRUCTS_H

struct ladders {
	int x;
	int y;
	int width;
	int height;
};
struct platforms {
	int x;
	int y;
	int width;
};
struct barrels {
	double x;
	double y;
	double velocity;
	int Barrel_falling_fromPlatform[4] = { 0,0,0,0 };
	int width;
};
struct ScoreEntry {
	char nickname[50];
	int score;
};

#endif 