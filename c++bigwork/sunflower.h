#pragma once
#include"character.h"
class sunflower :public character 
{
private:
	//ֲ����
	int sunflower_num = 1;
	//ֲ���ֵ
	int price;
	//�����ʱ��
	int counter;
	//ֲ��������·
	int plant_road;
	//ֲ����������
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
