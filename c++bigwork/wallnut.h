#pragma once
#include"character.h"
class wallnut :public character
{
public:
	wallnut(int a, int b, int i, int j);
	virtual void Draw(int delta);
	int get_position_x();
	int get_position_y();
	void hurt();
	int get_plant_road();
	int get_plant_line();
	bool check_being();


private:
	//植物编号
	int shoter_num = 4;
	//植物价值
	int price;
	//植物所处的路
	int plant_road;
	//植物所处的列
	int plant_line;
};
