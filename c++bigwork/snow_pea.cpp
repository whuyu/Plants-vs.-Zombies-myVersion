#include"snow_pea.h"
snow_pea::snow_pea(int a, int b, int i, int j) :character(_T("img/snow_pea_%d.png"), 7, 45)
{
	position.x = a;
	position.y = b;
	plant_road = i;
	plant_line = j;
	counter = 0;
	hp = 100;
}
snow_pea::snow_pea() :character(_T("img/snow_pea_%d.png"), 7, 45)
{

}
int snow_pea::get_position_x() {
	return position.x;
}
int snow_pea::get_position_y() {
	return position.y;
}
void snow_pea::addconuter() {
	counter++;
}
int snow_pea::get_counter() {
	return counter;
}
void snow_pea::Draw(int delta) {
	anim_left->play(position.x, position.y, delta);
}
void snow_pea::hurt() {
	hp -= 1;
}
int snow_pea::get_plant_road() {
	return plant_road;
}
int snow_pea::get_plant_line() {
	return plant_line;
}
bool snow_pea::check_being() {
	if (hp > 0) {
		return 1;
	}
	else {
		return 0;
	}
}