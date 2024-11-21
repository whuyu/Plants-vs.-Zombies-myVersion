#pragma once
#include<vector>
#include"putimage_alpha.h"
class Animation {
public:
	//LPCTSTR�ͱ�ʾһ��ָ�򳣹̶���ַ�Ŀ��Ը���һЩ�궨��ı�������ַ���
	//num��ʾanimation��ͼƬ����
	Animation(LPCTSTR path, int num, int interval);
	void play(int x, int y, int delta);
	~Animation();


private:
	int timer = 0;//������ʱ��
	int idx_frame = 0;//����֡����
	int interval_ms = 0;//֡���
	std::vector<IMAGE*>frame_list;
};