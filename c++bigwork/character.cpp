#include"character.h"
character::character(LPCTSTR path, LPCTSTR path2, int num, int interval, int specific_speed,int x,int y) {
	anim_left = new Animation(path, num, interval);
	anim_right = new Animation(path2, num, interval);
	speed = specific_speed;
	position.x= x;
	position.y =y;
}
character::character(LPCTSTR path, int num, int interval, int specific_speed) {
	anim_left = new Animation(path, num, interval);
	speed = specific_speed;
}
character::character(LPCTSTR path, int num, int interval) {
	anim_left = new Animation(path, num, interval);
}
character::~character()
{
	delete anim_left;
	delete anim_right;
}
