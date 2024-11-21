#include"sun.h"
sun::sun() {
	loadimage(&Sun_img, _T("img/Sun.png"));
	//时间的随机种子
	srand((unsigned int)time(NULL));

	//随机生成阳光
	sun_place = rand() % 45;
	//阳光生成的行数
	int a = sun_place / 9;
	//阳光生成的列数
	int b = sun_place % 9;
	int y = (a * 100) + 80;//竖直位置
	int x = (b * 80) + 40;//水平位置
	sun_position.x = x;
	sun_position.y = 0;
	end_y = y;
	being = 1;
	timer = 0;
}
sun::sun(sunflower* a_sunflower) {
	loadimage(&Sun_img, _T("img/Sun.png"));
	sun_position.x = a_sunflower->get_position_x();
	sun_position.y = a_sunflower->get_position_y();
	being = 1;
	timer = 0;
}

void sun::timer_add() {
	timer++;
}
int sun::get_timer() {
	return timer;
}

void sun::draw() {

	putimage_alpha(sun_position.x, sun_position.y, &Sun_img);

}
void sun::move() {
	if (sun_position.y < end_y) {
		sun_position.y += speed;
	}
}
int sun::get_sun_position_x() {
	return sun_position.x;
}
int sun::get_sun_position_y() {
	return sun_position.y;
}
void sun::dis_being() {
	being = 0;
}
bool sun::get_being() {
	return being;
}
