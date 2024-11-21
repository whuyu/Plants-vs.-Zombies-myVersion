#pragma once
#include"character.h"
class sunflower :public character 
{
private:
	//植物编号
	int sunflower_num = 1;
	//植物价值
	int price;
	//阳光计时器
	int counter;
	//植物所处的路
	int plant_road;
	//植物所处的列
	int plant_line;

public:

	sunflower(int a, int b, int i, int j);
	sunflower();
	int get_position_x();
	int get_position_y();
	virtual void Draw(int delta);
	void addconuter();
	int get_counter();
	void cutcounter();

	void hurt();
	int get_plant_road();
	int get_plant_line();
	bool check_being();

};
