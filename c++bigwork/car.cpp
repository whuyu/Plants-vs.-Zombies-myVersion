#include"car.h"
car::car(int a, int num_) :character(_T("img/car_%d.png"), 1, 45) {
	position.x = -20;
	position.y = a * 100 + 80;
	speed = 2;
	action = 0;
	num = num_;
}
void car::car_action() {
	action = 1;
}

void car::Draw(int delta) {
	anim_left->play(position.x, position.y, delta);
}
void car::move() {
	position.x += speed;
}
bool car::get_action() {
	return action;
}
int car::get_position_x()
{
	return position.x;
}
int car::get_num() {
	return num;
}

