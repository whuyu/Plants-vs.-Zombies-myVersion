#include"snow_bullet.h"
snow_bullet::snow_bullet(int a, int b) {

	loadimage(&SNOWBULLET, _T("img/snowBullet.png"));

	bullet_position.x = a;
	bullet_position.y = b;

}
void snow_bullet::draw() {
	putimage_alpha(bullet_position.x, bullet_position.y, &SNOWBULLET);
}
void snow_bullet::draw(int x, int y) {
	putimage_alpha(x, y, &SNOWBULLET);
}
int snow_bullet::GetPosition_x() {

	return bullet_position.x;
}
int snow_bullet::GetPosition_y() {

	return bullet_position.y;
}
void snow_bullet::bullet_move() {
	bullet_position.x += speed;

}
void snow_bullet::Hurt() {

	being = 0;

}
bool snow_bullet::CheckAlive() {

	return being;

}