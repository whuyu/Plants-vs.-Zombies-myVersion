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
	//阳光的图片
	IMAGE Sun_img;
	//阳光随机生成的位置
	int sun_place;
	//阳光的坐标
	POINT sun_position;
	//阳光的终点坐标
	int end_y;
	//阳光下落速度
	const int speed = 1;
	//阳光的存在
	bool being;
	//阳光存在计时器
	int timer;

};
