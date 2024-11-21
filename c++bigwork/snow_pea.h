#pragma once
#include"character.h"
class snow_pea:public character
{
public:
	snow_pea(int a, int b, int i, int j);
	snow_pea();
	int get_position_x();
	int get_position_y();
	void addconuter();
	int get_counter();
	virtual void Draw(int delta);
	void hurt();
	int get_plant_road();
	int get_plant_line();
	bool check_being();

private:
	//植物编号
	int snow_pea_num = 3;
	//植物价值
	int price;
	//射击计数器
	int counter;
	//植物所处的路
	int plant_road;
	//植物所处的列
	int plant_line;



};
