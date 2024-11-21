#include"shooter.h"
shooter::shooter(int a, int b, int i, int j) :character(_T("img/pea_shooter_%d.png"), 12, 45)
{
	position.x = a;
	position.y = b;
	plant_road = i;
	plant_line = j;
	counter = 0;
	hp = 100;
	being = 1;
}

shooter::shooter(int a, int b, int i, int j, int p) :character(_T("img/qiyana_%d.png"), 10, 45)
{
	position.x = a;
	position.y = b;
	plant_road = i;
	plant_line = j;
	counter = 0;
	hp = 500;
	being = 1;
}



bool shooter::check_being() {
	if (hp > 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int shooter::get_position_x() {
	return position.x;
}
int shooter::get_position_y() {
	return position.y;
}
int shooter::get_plant_road() {
	return plant_road;
}
int shooter::get_plant_line() {
	return plant_line;
}
void shooter::addconuter() {
	counter++;
}
int shooter::get_counter() {
	return counter;
}
void shooter::cutcounter() {
	counter = 0;
}
void shooter::hurt() {
	hp -= 1;
}
void shooter::Draw(int delta) {
	anim_left->play(position.x, position.y, delta);
}
