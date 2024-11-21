#include"bullet.h"
bullet::bullet(int a, int b) {

	loadimage(&BULLET, _T("img/Bullet2.png"));
	bullet_position.x = a + 63;
	bullet_position.y = b;

}
void bullet::draw() {
	putimage_alpha(bullet_position.x, bullet_position.y, &BULLET);
}
void  bullet::draw(int x, int y) {
	putimage_alpha(x, y, &BULLET);
}
int  bullet::GetPosition_x() {

	return bullet_position.x;
}
int  bullet::GetPosition_y() {

	return bullet_position.y;
}
void  bullet::bullet_move() {
	bullet_position.x += speed;

}
void  bullet::Hurt() {

	being = 0;

}
bool  bullet::CheckAlive() {

	return being;

}