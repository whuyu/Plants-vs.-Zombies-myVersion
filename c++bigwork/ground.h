#pragma once
#include<graphics.h>
class ground
{
private:
	//��ά����
	int background[2][5][9]{};

	//�жϳ����Ƿ�Ӧ��������
	int sun_able;
	bool sun_out;
	bool Is_zombie[5];
public:
	ground();
	int getnum1(int a, int b);
	int getnum2(int a, int b);
	void addnum(int a, int b);
	//�����Ƿ��������������ֲ��
	void minnum(int a, int b);
	void put_Is_zombie(int a);
	void no_zombie(int a);
	bool get_Is_zombie(int a);


	void ground_process(const ExMessage& msg, int a);


};
