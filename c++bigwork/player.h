#include"character.h"
#include"bullet.h"
#include"sun.h"
class player :public character
{
public:
	player();
	//��������ƶ�
	void ProcessEvent(const ExMessage& msg);
	//����ƶ�
	void move();
	//���ƶ���
	virtual void Draw(int delta);
	//����������
	void Process_shoot(const ExMessage& msg);
	void shoot_timer();
	int get_shoot_able();
	void not_shoot();
	bool get_is_shoot();
	int Getposition_x();
	int Getposition_y();
	void pick_sun(sun* a_sun);//ʰȡ����
	void draw_sun_num();//����̫������
	//���ƽ�ʬ������
	void draw_battle_num(int a);
	//���Ƶȼ�
	void draw_grade();
	//�ж�ֲ������
	int what_plant();
	int  get_sun_num();
	void use_sun(int a);
	void upgrade();
	bool is_in_up_place();
	int get_grade();



protected:
	bool Is_shoot;
private:
	//��ҵĲ���
	const int player_width = 80;
	const int player_height = 80;
	const int shadow_width = 32;
	//����ٶ�
	int player_speed;
	//��ҵ���������
	int num;
	//�����ʱ��
	int shoot_able = 0;
	//�ƶ�
	 bool Is_move_up = 0;
	 bool Is_move_down = 0;
	 bool Is_move_left = 0;
	 bool Is_move_right = 0;
	 //���ﳯ��
	 bool facing;
	 //��ҵĵȼ�
	 int grade=1;
	 //������ӰͼƬ
	 IMAGE player_shadow;
};
