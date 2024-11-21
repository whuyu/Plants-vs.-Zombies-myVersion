#include"character.h"
#include"bullet.h"
#include"sun.h"
class player :public character
{
public:
	player();
	//处理玩家移动
	void ProcessEvent(const ExMessage& msg);
	//玩家移动
	void move();
	//绘制动画
	virtual void Draw(int delta);
	//处理玩家射击
	void Process_shoot(const ExMessage& msg);
	void shoot_timer();
	int get_shoot_able();
	void not_shoot();
	bool get_is_shoot();
	int Getposition_x();
	int Getposition_y();
	void pick_sun(sun* a_sun);//拾取阳光
	void draw_sun_num();//绘制太阳数量
	//绘制僵尸击败数
	void draw_battle_num(int a);
	//绘制等级
	void draw_grade();
	//判断植物种类
	int what_plant();
	int  get_sun_num();
	void use_sun(int a);
	void upgrade();
	bool is_in_up_place();
	int get_grade();



protected:
	bool Is_shoot;
private:
	//玩家的参数
	const int player_width = 80;
	const int player_height = 80;
	const int shadow_width = 32;
	//玩家速度
	int player_speed;
	//玩家的阳光数量
	int num;
	//射击计时器
	int shoot_able = 0;
	//移动
	 bool Is_move_up = 0;
	 bool Is_move_down = 0;
	 bool Is_move_left = 0;
	 bool Is_move_right = 0;
	 //人物朝向，
	 bool facing;
	 //玩家的等级
	 int grade=1;
	 //人物阴影图片
	 IMAGE player_shadow;
};
