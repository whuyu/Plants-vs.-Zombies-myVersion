#include"gbman.h"
gbman::gbman() :zombie(_T("img/gbman_%d.png"), 1) {
	//ʱ����������
	srand((unsigned int)time(NULL));

	//�������ɵ�����
	int b = rand() % 3;
	int y = (zombie_road * 100) + 60;//��ֱλ��
	int x = (b * 80) + 440;//ˮƽλ��
	p(x, y);
};