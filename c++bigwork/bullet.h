#pragma once
#include"Animation.h"
class bullet {
private:
	IMAGE BULLET;
	int speed = 2;
	bool being=1;
	POINT bullet_position;

public:
	bullet(int a, int b);
	void draw();
	void draw(int x, int y);
	int GetPosition_x();
	int GetPosition_y();
	void bullet_move();
	void Hurt();
	bool CheckAlive();

};
