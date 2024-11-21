#pragma once
#include"putimage_alpha.h"
#include"sunflower.h"
#include<graphics.h>
#include<ctime>

class sun {
public:
	sun();
	sun(sunflower* a_sunflower);

	void timer_add();
	int get_timer();

	void draw();
	void move();
	int get_sun_position_x();
	int get_sun_position_y();
	void dis_being();
	bool get_being();
	
private:
	const int sun_width = 78;
	const int sun_height = 78;
	//�����ͼƬ
	IMAGE Sun_img;
	//����������ɵ�λ��
	int sun_place;
	//���������
	POINT sun_position;
	//������յ�����
	int end_y;
	//���������ٶ�
	const int speed = 1;
	//����Ĵ���
	bool being;
	//������ڼ�ʱ��
	int timer;

};
