#pragma once
#pragma once
#include"Animation.h"
class snow_bullet {
private:
	IMAGE SNOWBULLET;
	int speed = 1;
	bool being = 1;
	POINT bullet_position;

public:
	snow_bullet(int a, int b);
	void draw();
	void draw(int x, int y);
	int GetPosition_x();
	int GetPosition_y();
	void bullet_move();
	void Hurt();
	bool CheckAlive();

};
