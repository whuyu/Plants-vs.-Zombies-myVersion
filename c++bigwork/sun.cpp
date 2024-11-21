#include"sun.h"
sun::sun() {
	loadimage(&Sun_img, _T("img/Sun.png"));
	//ʱ����������
	srand((unsigned int)time(NULL));

	//�����������
	sun_place = rand() % 45;
	//�������ɵ�����
	int a = sun_place / 9;
	//�������ɵ�����
	int b = sun_place % 9;
	int y = (a * 100) + 80;//��ֱλ��
	int x = (b * 80) + 40;//ˮƽλ��
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
