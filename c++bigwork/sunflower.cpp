#include"sunflower.h"
sunflower::sunflower(int a, int b, int i, int j) :character(_T("img/sun_flower_%d.png"), 18, 45)
{
	position.x = a;
	position.y = b;
	plant_road = i;
	plant_line = j;
	hp = 100;
}
sunflower::sunflower() :character(_T("img/sun_flower_%d.png"), 18, 45)
{
}
int sunflower::get_position_x() {
	return position.x;
}
int sunflower::get_position_y() {
	return position.y;
}
void sunflower::Draw(int delta) {
	anim_left->play(position.x, position.y, delta);
}
void sunflower::addconuter() {
	counter++;
}
int sunflower::get_counter() {
	return counter;
}
void sunflower::cutcounter() {
	counter = 0;
}

void sunflower::hurt() {
	hp -= 1;
}
int sunflower::get_plant_road() {
	return plant_road;
}
int sunflower::get_plant_line() {
	return plant_line;
}
bool sunflower::check_being() {
	if (hp > 0) {
		return 1;
	}
	else {
		return 0;
	}
}