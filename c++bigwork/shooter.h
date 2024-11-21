#pragma once
#include"character.h"
class shooter :public character
{
public:
	shooter(int a, int b, int i, int j);

	shooter(int a, int b, int i, int j, int p);



	bool check_being();

	int get_position_x();
	int get_position_y();
	int get_plant_road();
	int get_plant_line();
	void addconuter();
	int get_counter();
	void cutcounter();
	void hurt();
	virtual void Draw(int delta);
	


protected:
	bool being;
	//植物编号
	int shoter_num = 2;
	//植物价值
	const int price = 100;
	//射击计数器
	int counter;
	//植物所处的路
	int plant_road;
	//植物所处的列
	int plant_line;
};
