#pragma once
#include"character.h"
class car :public character {
public:
	//���캯��
	car(int a, int num_);
	//С������
	void car_action();
	//��������
	void Draw(int delta);
	//С���ƶ�
	void move();

	bool get_action();
	int get_position_x();
	int get_num();


private:
	bool action;
	int num;
};
