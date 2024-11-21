#pragma once
#include<vector>
#include"putimage_alpha.h"
class Animation {
public:
	//LPCTSTR就表示一个指向常固定地址的可以根据一些宏定义改变语义的字符串
	//num表示animation的图片数量
	Animation(LPCTSTR path, int num, int interval);
	void play(int x, int y, int delta);
	~Animation();


private:
	int timer = 0;//动画计时器
	int idx_frame = 0;//动画帧索引
	int interval_ms = 0;//帧间隔
	std::vector<IMAGE*>frame_list;
};