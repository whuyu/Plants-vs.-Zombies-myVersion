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
	//构造函数
	zombie();
	zombie(LPCTSTR path, int a);
	//绘制动画
	virtual void Draw(int delta);
	//检测子弹撞击
	bool CheckBulletCollision(bullet* a_bullet);
	bool CheckSnowBulletCollision(snow_bullet* a_bullet, int a);
	//检测小车撞击
	bool CheckCarCollision(car* a_car);
	//激发小车
	bool check_action(car* a_car);
	//受伤
	void Hurt();
	void Hurt(int a);
	//检测僵尸是否死亡
	bool CheckAlive();
	void zombie_move();//僵尸移动
	int get_zombiie_road();
	int get_zombie_position_x();
	//为僵尸在吃植物不移动提供辅助方法
	bool get_move_able();
	void no_move();
	void y_move();

	void p(int a);
	void p(int a, int b);
};
