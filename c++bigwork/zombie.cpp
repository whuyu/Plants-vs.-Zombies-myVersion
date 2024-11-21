#include"Zombie.h"
zombie::zombie() :character(_T("img/zombie_%d.png"), 8, 45, 1) {
	hp = 125;
	move_able = 1;
	srand((unsigned int)time(NULL));
	zombie_road = rand() % 5;
	//僵尸的随机分路
	switch (zombie_road) {
	case 0:
		position.x = 700;
		position.y = zombie_road * 120;
		break;
	case 1:
		position.x = 700;
		position.y = zombie_road * 120;
		break;
	case 2:
		position.x = 700;
		position.y = zombie_road * 120 - 20;
		break;
	case 3:
		position.x = 700;
		position.y = zombie_road * 120 - 50;
		break;
	case 4:
		position.x = 700;
		position.y = zombie_road * 120 - 50;
		break;

	}
}


zombie::zombie(LPCTSTR path, int a) :character(path, a, 45, 1) {
	hp = 400;
	move_able = 1;
	srand((unsigned int)time(NULL));
	zombie_road = rand() % 5;
	//僵尸的随机分路
	switch (zombie_road) {
	case 0:
		position.x = 700;
		position.y = zombie_road * 120;
		break;
	case 1:
		position.x = 700;
		position.y = zombie_road * 120;
		break;
	case 2:
		position.x = 700;
		position.y = zombie_road * 120 - 20;
		break;
	case 3:
		position.x = 700;
		position.y = zombie_road * 120 - 50;
		break;
	case 4:
		position.x = 700;
		position.y = zombie_road * 120 - 50;
		break;

	}
}


void zombie::Draw(int delta) {

	anim_left->play(position.x, position.y, delta);

}

bool zombie::CheckBulletCollision(bullet* a_bullet) {

	if (a_bullet->GetPosition_x() > position.x + 42 && a_bullet->GetPosition_x() < position.x + zmobie_width) {
		if (a_bullet->GetPosition_y() > position.y && a_bullet->GetPosition_y() < position.y + zombie_height) {
			return true;
		}
	}
	return false;
}

bool zombie::CheckSnowBulletCollision(snow_bullet* a_bullet, int a) {

	if (a_bullet->GetPosition_x() > position.x + 42 && a_bullet->GetPosition_x() < position.x + zmobie_width) {
		if (a_bullet->GetPosition_y() > position.y && a_bullet->GetPosition_y() < position.y + zombie_height) {
			speed = a;
			return true;
		}
	}
	return false;
}


bool zombie::CheckCarCollision(car* a_car) {
	if (a_car->get_position_x() > position.x && zombie_road == a_car->get_num()) {

		return true;
	}
	return false;
}

bool zombie::check_action(car* a_car) {
	if (position.x < -10 && !a_car->get_action() && a_car->get_num() == zombie_road) {
		return 1;
	}
	return 0;
}
void zombie::Hurt() {
	hp -= 25;
}
void zombie::Hurt(int a) {
	hp -= 45;
}
bool zombie::CheckAlive() {
	if (hp > 0) {
		return 1;
	}
	else {
		return 0;
	}

}
void zombie::zombie_move() {
	//利用动画计时器的类似原理控制僵尸移动速度
	zombie_timer += zombie_delta;
	if (zombie_timer >= 45) {
		position.x -= speed;
		zombie_timer = 0;
	}
}
int zombie::get_zombiie_road() {
	return zombie_road;
}
int zombie::get_zombie_position_x() {
	return position.x;
}
bool zombie::get_move_able() {
	return move_able;
}
void zombie::no_move() {
	move_able = 0;
}
void zombie::y_move() {
	move_able = 1;
}
void zombie::p(int a) {
	switch (a)
	{
	case 1:
		position.x = 650;
	}
}
void zombie::p(int a, int b) {
	position.x = a;
	position.y = b;
}