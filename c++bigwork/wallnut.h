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
	//ֲ����
	int shoter_num = 4;
	//ֲ���ֵ
	int price;
	//ֲ��������·
	int plant_road;
	//ֲ����������
	int plant_line;
};
