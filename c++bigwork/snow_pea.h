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
	//ֲ����
	int snow_pea_num = 3;
	//ֲ���ֵ
	int price;
	//���������
	int counter;
	//ֲ��������·
	int plant_road;
	//ֲ����������
	int plant_line;



};
