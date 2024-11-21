#pragma once
#include"character.h"
class car :public character {
public:
	//构造函数
	car(int a, int num_);
	//小车激发
	void car_action();
	//动画绘制
	void Draw(int delta);
	//小车移动
	void move();

	bool get_action();
	int get_position_x();
	int get_num();


private:
	bool action;
	int num;
};
