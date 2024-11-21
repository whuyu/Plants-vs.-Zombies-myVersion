#pragma once
#include"character.h"
#include"bullet.h"
#include"snow_bullet.h"
#include"car.h"
#include<ctime>

class zombie :public character
{
protected:
	int zombie_speed;
	int zombie_road;
	int  zombie_delta = 1000/144;
	int zombie_timer = 0;
	const int zmobie_width=166;
	const int zombie_height=144;
	bool alive=1;
	bool move_able;

public:
	//���캯��
	zombie();
	zombie(LPCTSTR path, int a);
	//���ƶ���
	virtual void Draw(int delta);
	//����ӵ�ײ��
	bool CheckBulletCollision(bullet* a_bullet);
	bool CheckSnowBulletCollision(snow_bullet* a_bullet, int a);
	//���С��ײ��
	bool CheckCarCollision(car* a_car);
	//����С��
	bool check_action(car* a_car);
	//����
	void Hurt();
	void Hurt(int a);
	//��⽩ʬ�Ƿ�����
	bool CheckAlive();
	void zombie_move();//��ʬ�ƶ�
	int get_zombiie_road();
	int get_zombie_position_x();
	//Ϊ��ʬ�ڳ�ֲ�ﲻ�ƶ��ṩ��������
	bool get_move_able();
	void no_move();
	void y_move();

	void p(int a);
	void p(int a, int b);
};
