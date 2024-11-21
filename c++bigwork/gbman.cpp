#include"gbman.h"
gbman::gbman() :zombie(_T("img/gbman_%d.png"), 1) {
	//时间的随机种子
	srand((unsigned int)time(NULL));

	//阳光生成的列数
	int b = rand() % 3;
	int y = (zombie_road * 100) + 60;//竖直位置
	int x = (b * 80) + 440;//水平位置
	p(x, y);
};