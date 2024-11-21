#include"wallnut.h"
wallnut::wallnut(int a, int b, int i, int j) :character(_T("img/wallnut_%d.png"), 8, 45)
{
	position.x = a;
	position.y = b;
	plant_road = i;
	plant_line = j;
	hp = 600;
}
void wallnut::Draw(int delta) {
	anim_left->play(position.x, position.y, delta);
}
int wallnut::get_position_x() {
	return position.x;
}
int wallnut::get_position_y() {
	return position.y;
}
void wallnut::hurt() {
	hp -= 1;
}
int wallnut::get_plant_road() {
	return plant_road;
}
int wallnut::get_plant_line() {
	return plant_line;
}
bool wallnut::check_being() {
	if (hp > 0) {
		return 1;
	}
	else {
		return 0;
	}
}
