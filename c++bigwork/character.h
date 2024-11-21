#pragma once
#include<graphics.h>
#include"Animation.h"
class character{
public:
	character(LPCTSTR path, LPCTSTR path2, int num, int interval, int specific_speed,int x,int y);//�Ż�����point
	character(LPCTSTR path, int num, int interval, int specific_speed);
	character(LPCTSTR path, int num, int interval);

	virtual void Draw(int delta) = 0;
	//���ƻ���
	~character();

protected:
	POINT position;
	Animation* anim_left;//����ͼƬ
	Animation* anim_right;
	int hp;
	int speed;

private:
	
	
};
