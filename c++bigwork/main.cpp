#include<iostream>
using namespace std;
#include<graphics.h>
#include"Animation.h"
#include<string>
#include<cmath>
#include"player.h"
#include"bullet.h"
#include"Zombie.h"
#include"sunflower.h"
#include"wallnut.h"
#include"ground.h"
#include"sun.h"
#include"shooter.h"
#include"snow_pea.h"
#include"car.h"
#include"snow_bullet.h"
#include"snowman.h"
#include"gbman.h"
#include"qiyana.h"


#pragma comment(lib,"Winmm.lib")
#pragma comment(lib,"MSIMG32.LIB")



//产生僵尸1
void TryGenerateZombie(vector<zombie*>& zombie_list) {
	int interval = 900;
	static int zombie_counter = 0;
	zombie_counter++;
	if (zombie_counter % interval == 0) {
		zombie_list.push_back(new zombie());
	}

}
//产生僵尸2
void TryGenerateZombie(vector<zombie*>&zombie_list,vector<snowman*>&snowman_list)
{
	int interval =500;

	static int zombie_counter = 0;
	zombie_counter++;
	if (zombie_counter % interval == 0) {
		zombie_list.push_back(new zombie());
		snowman_list.push_back(new snowman());
	}
}
//产生gbman
void TryGenerateGbman1(vector<gbman*>& gbman_list)
{
	int interval = 800;
	static int gbman_counter = 0;
	gbman_counter++;
	if (gbman_counter % interval==0) {
			gbman_list.push_back(new gbman());

	}
}
//玩家的自动发射
void Updatebullets(vector<bullet*>&bullet_list,player&a_player) {
	const int interval = 100;
	static int counter = 0;
	counter++;
	if (counter % interval == 0) {
		bullet_list.push_back(new bullet(a_player.Getposition_x(), a_player.Getposition_y()));
	}
	
}

//玩家的子弹手动发射
void update_bullet_shoot(vector<bullet*>& bullet_list, player& a_player) {

	bullet_list.push_back(new bullet(a_player.Getposition_x(), a_player.Getposition_y()));

}

//豌豆射手的自动发射
void Update_shooter_bullet(vector<bullet*>& bullet_list, shooter* a_shooter)
{
	const int interval = 200;
	a_shooter->addconuter();
	if (a_shooter->get_counter() % interval == 0) {
		bullet_list.push_back(new bullet(a_shooter->get_position_x(), a_shooter->get_position_y()));
		a_shooter->cutcounter();
	}
}
//qiyana的子弹发射
void Update_qiyana_bullet(vector<bullet*>& bullet_list, qiyana*a_qiyana)
{
	const int interval = 100;
	a_qiyana ->addconuter();
	if (a_qiyana->get_counter() % interval == 0) {
		bullet_list.push_back(new bullet(a_qiyana->get_position_x(), a_qiyana->get_position_y()));
		a_qiyana->cutcounter();
	}
}


//向日葵的阳光产生
void Update_sun(vector<sun*>&sun_list,sunflower*a_sunflower) {
	const int interval = 800;
	a_sunflower->addconuter();
	if (a_sunflower->get_counter() % interval == 0) {
		sun_list.push_back(new sun(a_sunflower));
		a_sunflower->cutcounter();
	}
}


//冰豌豆的自动发射
void Update_snow_pea_bullet(vector<snow_bullet*>& snow_bullet_list,snow_pea* a_snow_pea)
{
	const int interval = 200;
	a_snow_pea->addconuter();
	if (a_snow_pea->get_counter() % interval == 0) {
		snow_bullet_list.push_back(new snow_bullet(a_snow_pea->get_position_x(), a_snow_pea->get_position_y()));
	}
}


//种植向日葵
void update_sunflower(vector<sunflower*>&sunflower_list,int xx,int yy,int i,int j) {

	sunflower_list.push_back(new sunflower(xx,yy,i,j));

}

//种植豌豆射手
void update_shooter(vector<shooter*>&shooter_list, int xx, int yy,int i,int j) {

	shooter_list.push_back(new shooter(xx, yy,i,j));

}
//种植qiyana
void update_qiyana(vector<qiyana*>& shooter_list, int xx, int yy, int i, int j) {

	shooter_list.push_back(new qiyana(xx, yy, i, j));

}

//种植冰豌豆射手
void update_snow_pea(vector<snow_pea*>& snow_pea_list, int xx, int yy, int i, int j) {

	snow_pea_list.push_back(new snow_pea(xx, yy,i,j));

}
//种植坚果墙
void update_wallnut(vector<wallnut*>& wallnut_list,int x,int y,int i,int j) {
	wallnut_list.push_back(new wallnut(x, y,i,j));
}


//产生阳光
void TryGenerateSun(vector<sun*>&sun_list) {
	const int interval = 600;
	static int sun_counter = 0;
	sun_counter++;
	if (sun_counter % interval == 0) {
		sun_list.push_back(new sun());
	}
}


  
int main() {
	//玩家
	player p1;
	//场地类
	ground g1;
	//记录是否有僵尸
	int road[5]{};
	//释放僵尸移动
	int free[5]{};

	//击败的僵尸数量
	static int counter=0;

	
	//僵尸数组
	vector<zombie*>zombie_list;
	vector<snowman*>snowman_list;
	vector<gbman*>gbman_list;

	//子弹植物数组
	vector<bullet*>bullet_list;
	vector<snow_bullet*>snow_bullet_list;
	vector<sunflower*>sunflower_list;
	vector<wallnut*>wallnut_list;
	vector<sun*>sun_list;
	vector<shooter*>shooter_list;
	vector<snow_pea*>snow_pea_list;
	vector<car*>car_list;
	vector<qiyana*>qiyana_list;


	bool starting = 1;
	bool running = 1;
	bool ending = 1;
	bool winning = 1;
	initgraph(800, 700);

	//虚拟按键信息
	ExMessage msg;

	//静态物品的图片
	IMAGE imgs, imgs2;
	IMAGE sun_board;
	IMAGE sunflower_card, shooter_card, wallnut_card, snow_pea_card;
	IMAGE up;
	IMAGE start;
	IMAGE end;
	IMAGE win;

	mciSendString(_T("open mus/bgm.mp3 alias bgm"), NULL, 0, NULL);
	mciSendString(_T("open mus/hit.mp3 alias hit"), NULL, 0, NULL);
	mciSendString(_T("open mus/sun.mp3 alias sun"), NULL, 0, NULL);
	mciSendString(_T("open mus/eating.mp3 alias eating"), NULL, 0, NULL);
	mciSendString(_T("open mus/car.mp3 alias car"), NULL, 0, NULL);
	mciSendString(_T("open mus/win.mp3 alias win"), NULL, 0, NULL);
	mciSendString(_T("open mus/lose.mp3 alias lose"), NULL, 0, NULL);
	mciSendString(_T("open mus/plant.mp3 alias plant"), NULL, 0, NULL);




	mciSendString(_T("play bgm repeat from 0"), NULL, 0, NULL);


	loadimage(&imgs, _T("img/Lawn.jpg"));
	loadimage(&imgs2, _T("img/background.png"));
	loadimage(&sun_board, _T("img/sun_board.png"));
	loadimage(&sunflower_card, _T("img/SunFlowerCard.jpg"));
	loadimage(&shooter_card, _T("img/PeaShooterCard.jpg"));
	loadimage(&snow_pea_card, _T("img/snowShooterCard.png"));
	loadimage(&wallnut_card, _T("img/wallNutCard.png"));
	loadimage(&up, _T("img/up.png"));
	loadimage(&start, _T("img/start.jpg"));
	loadimage(&end, _T("img/end.png"));
	loadimage(&win, _T("img/win.jpg"));

	//载入小推车
	for (int i = 0; i < 5; i++) {
		car_list.push_back(new car(i,i));
	}

	//封面
	while (starting) {

		putimage(0, 0, &start);
		while (peekmessage(&msg))
		{
			if (msg.message == WM_LBUTTONDOWN) {
				int x = msg.x;
				int y = msg.y;
				if (y > 490 && y < 570 && x>130 && x < 670) {
					starting = 0;
				}
			}

		}

	}


	BeginBatchDraw();
	


	//主循环
	while (running) {
		DWORD start_time = GetTickCount();

		//发射计数器
		p1.shoot_timer();


		
		while (peekmessage(&msg))
		{
			//处理植物种植时的鼠标位置
			g1.ground_process(msg,p1.what_plant());
			//处理玩家移动
			p1.ProcessEvent(msg);
			//处理玩家子弹发射
			p1.Process_shoot(msg);

		}

		//玩家移动
		p1.move();


		//升级系统
		if (p1.get_is_shoot() && p1.is_in_up_place()) {
			
			if (p1.get_grade() == 1&&p1.get_sun_num()>=200) {
				p1.upgrade();
				p1.use_sun(5);
			}
			else if (p1.get_grade() == 2&&p1.get_sun_num()>=300) {
				p1.upgrade();
				p1.use_sun(6);
			}
			else if(p1.get_grade() == 3&&p1.get_sun_num()>=500) {
				p1.upgrade();
				p1.use_sun(7);
			}

		}

		//player的发射处理
		//当player按下按键并且计数器足够大时可以发射
		if (p1.get_is_shoot()&&p1.get_shoot_able()>100&&p1.get_grade()>1) {
			update_bullet_shoot(bullet_list, p1);
			p1.not_shoot();
		}

		//产生bullet
		if (p1.get_grade() > 2) {
			Updatebullets(bullet_list, p1);
		}

		//阳光自动产生
		TryGenerateSun(sun_list);

		//向日葵阳光的产生
		for (size_t i = 0; i < sunflower_list.size(); i++) {
			Update_sun(sun_list, sunflower_list[i]);
		}



		//产生zombie
		if (counter > 30) {
			TryGenerateZombie(zombie_list, snowman_list);
			TryGenerateGbman1(gbman_list);

		}
		else {
			TryGenerateZombie(zombie_list);
		}
		


		//记录该路是否有僵尸
		for (size_t i = 0; i < zombie_list.size(); i++) {
			road[zombie_list[i]->get_zombiie_road()]++;
		}
		for (size_t i = 0; i < gbman_list.size(); i++) {
			road[gbman_list[i]->get_zombiie_road()]++;
		}
		for (size_t i = 0; i < snowman_list.size(); i++) {
			road[snowman_list[i]->get_zombiie_road()]++;
		}
		//将road的内容传入g1
		for (int i = 0; i < 5; i++) {
			if (road[i]) {
				g1.put_Is_zombie(i);
				road[i] = 0;
			}
			else {
				g1.no_zombie(i);
				road[i] = 0;
			}
		}

		
		//豌豆发射处理
		for (size_t i = 0; i < shooter_list.size(); i++) {
			if (g1.get_Is_zombie(shooter_list[i]->get_plant_road())) {
				Update_shooter_bullet(bullet_list, shooter_list[i]);
			}
		}
		//qiyana的子弹发射
		for (size_t i = 0; i < qiyana_list.size(); i++) {
				Update_qiyana_bullet(bullet_list, qiyana_list[i]);
		}
		//冰豌豆发射处理
		for (size_t i = 0; i <snow_pea_list.size(); i++) {
			if (g1.get_Is_zombie(snow_pea_list[i]->get_plant_road())) {
				Update_snow_pea_bullet(snow_bullet_list, snow_pea_list[i]);
			}
		}


		



		//小推车激发处理
		for (size_t i = 0; i < car_list.size(); i++) {
			for (size_t j = 0; j < zombie_list.size(); j++) {
				if (zombie_list[j]->check_action(car_list[i])) {
					mciSendString(_T("play car from 0"), NULL, 0, NULL);
					car_list[i]->car_action();
				}
			}
		}






		//植物种植处理
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 9; j++) {
				if (!g1.getnum2(i, j)) {
					if (g1.getnum1(i,j)==1&&p1.get_sun_num()>=50) {
						int b = (i *100)+80;//竖直位置
						int a = (j * 80) + 40;//水平位置
						update_sunflower(sunflower_list, a, b,i,j);
						g1.addnum(i, j);
						p1.use_sun(1);
						mciSendString(_T("play plant from 0"), NULL, 0, NULL);
					}
					if (g1.getnum1(i, j) == 2 && p1.get_sun_num() >= 100) {
						int b = (i * 100) + 80;//竖直位置
						int a = (j * 80) + 40;//水平位置
						update_shooter(shooter_list, a, b,i,j);
						g1.addnum(i, j);
						p1.use_sun(2);
						mciSendString(_T("play plant from 0"), NULL, 0, NULL);
					}
					if (g1.getnum1(i, j) == 3 && p1.get_sun_num() >= 175) {
						int b = (i * 100) + 80;//竖直位置
						int a = (j * 80) + 40;//水平位置
						update_snow_pea(snow_pea_list, a, b,i,j);
						g1.addnum(i, j);
						p1.use_sun(3);
						mciSendString(_T("play plant from 0"), NULL, 0, NULL);
					}
					if (g1.getnum1(i, j) == 4&&p1.get_sun_num() >= 50) {
						int b = (i * 100) + 80;//竖直位置
						int a = (j * 80) + 40;//水平位置
						update_wallnut(wallnut_list, a, b,i,j);
						g1.addnum(i, j);
						p1.use_sun(4);
						mciSendString(_T("play plant from 0"), NULL, 0, NULL);
					}
					if (g1.getnum1(i, j) == 5 && p1.get_sun_num() >=300&&p1.get_grade()==4) {
						int b = (i * 100) + 80;//竖直位置
						int a = (j * 80) + 40;//水平位置
						update_qiyana(qiyana_list, a, b, i, j);
						g1.addnum(i, j);
						p1.use_sun(8);
						mciSendString(_T("play plant from 0"), NULL, 0, NULL);
					}
				}
			}

		}
	


		//移动处理
		
		//僵尸的移动
		for (size_t i = 0; i < zombie_list.size(); i++) {
			if (zombie_list[i]->get_move_able()) {
				zombie_list[i]->zombie_move();
			}
		}
		for (size_t i = 0; i < snowman_list.size(); i++) {
			if (snowman_list[i]->get_move_able()) {
				snowman_list[i]->zombie_move();
			}
		}



		//bullet的移动
		for (size_t i = 0; i < bullet_list.size(); i++) {
			bullet_list[i]->bullet_move();
		}
		//snow_bullet的移动
		for (size_t i = 0; i < snow_bullet_list.size(); i++) {
			snow_bullet_list[i]->bullet_move();
		}
		//小推车的移动
		for (size_t i = 0; i < car_list.size(); i++) {
			if (car_list[i]->get_action()) {
				car_list[i]->move();
			}
		}
		//阳光的移动
		for (size_t i = 0; i < sun_list.size(); i++) {
			sun_list[i]->move();
		}



		//受击处理

		//僵尸受击处理(豌豆)
		for (size_t i = 0; i < bullet_list.size(); i++) {
			for (size_t j = 0; j < zombie_list.size(); j++) {
				if (zombie_list[j]->CheckBulletCollision(bullet_list[i])) {
					mciSendString(_T("play hit from 0"), NULL, 0, NULL);
					zombie_list[j]->Hurt();
					bullet_list[i]->Hurt();

				}
			}
		}
		//snowman的受击处理1
		for (size_t i = 0; i < bullet_list.size(); i++) {
			for (size_t j = 0; j < snowman_list.size(); j++) {
				if (snowman_list[j]->CheckBulletCollision(bullet_list[i])) {
					mciSendString(_T("play hit from 0"), NULL, 0, NULL);
					snowman_list[j]->Hurt();
					bullet_list[i]->Hurt();

				}
			}
		}
		//gbman受击处理
		for (size_t i = 0; i < bullet_list.size(); i++) {
			for (size_t j = 0; j < gbman_list.size(); j++) {
				if (gbman_list[j]->CheckBulletCollision(bullet_list[i])) {
					mciSendString(_T("play hit from 0"), NULL, 0, NULL);
					gbman_list[j]->Hurt();
					bullet_list[i]->Hurt();
				}
			}
		}
		//僵尸受击处理(冰豌豆)
		for (size_t i = 0; i < snow_bullet_list.size(); i++) {
			for (size_t j = 0; j < zombie_list.size(); j++) {
				if (zombie_list[j]->CheckSnowBulletCollision(snow_bullet_list[i],1)) {
					mciSendString(_T("play hit from 0"), NULL, 0, NULL);
					zombie_list[j]->Hurt(1);
					snow_bullet_list[i]->Hurt();

				}
			}
		}
		//snowman的受击处理2
		for (size_t i = 0; i < snow_bullet_list.size(); i++) {
			for (size_t j = 0; j < snowman_list.size(); j++) {
				if (snowman_list[j]->CheckSnowBulletCollision(snow_bullet_list[i],2)) {
					mciSendString(_T("play hit from 0"), NULL, 0, NULL);
					snow_bullet_list[i]->Hurt();
				}
			}
		}
		//gbman的受击处理
		for (size_t i = 0; i < snow_bullet_list.size(); i++) {
			for (size_t j = 0; j < gbman_list.size(); j++) {
				if (gbman_list[j]->CheckSnowBulletCollision(snow_bullet_list[i], 2)) {
					mciSendString(_T("play hit from 0"), NULL, 0, NULL);
					snow_bullet_list[i]->Hurt();
					gbman_list[j]->Hurt();
				}
			}
		}
		//僵尸受击处理（小推车）
		for (size_t i = 0; i < car_list.size(); i++) {
			for (size_t j = 0; j < zombie_list.size(); j++) {
				if (zombie_list[j]->CheckCarCollision(car_list[i])) {
					zombie_list[j]->Hurt();
				}
			}
		}
	






		//植物的受伤处理
		for (size_t i = 0; i < zombie_list.size(); i++) {
			for (size_t j = 0; j < shooter_list.size(); j++) {
				if (shooter_list[j]->get_position_x() > zombie_list[i]->get_zombie_position_x() + 16
					&&shooter_list[j]->get_plant_road() ==zombie_list[i]->get_zombiie_road()) {
					shooter_list[j]->hurt();
					zombie_list[i]->no_move();
				}
			}
			for (size_t j = 0; j < qiyana_list.size(); j++) {
				if (qiyana_list[j]->get_position_x() > zombie_list[i]->get_zombie_position_x() + 16
					&& qiyana_list[j]->get_plant_road() == zombie_list[i]->get_zombiie_road()) {
					qiyana_list[j]->hurt();
					zombie_list[i]->no_move();
				}
			}
			for (size_t j = 0; j < snow_pea_list.size(); j++) {
				if (snow_pea_list[j]->get_position_x() > zombie_list[i]->get_zombie_position_x() + 16
					&& snow_pea_list[j]->get_plant_road() == zombie_list[i]->get_zombiie_road()) {
					snow_pea_list[j]->hurt();
					zombie_list[i]->no_move();
				}
			}
			for (size_t j = 0; j < sunflower_list.size(); j++) {
				if (sunflower_list[j]->get_position_x() > zombie_list[i]->get_zombie_position_x() + 16
					&& sunflower_list[j]->get_plant_road() == zombie_list[i]->get_zombiie_road()) {
					
					sunflower_list[j]->hurt();
					zombie_list[i]->no_move();
				}
			}
			for (size_t j = 0; j < wallnut_list.size(); j++) {
				if (wallnut_list[j]->get_position_x() > zombie_list[i]->get_zombie_position_x() + 16
					&& wallnut_list[j]->get_plant_road() == zombie_list[i]->get_zombiie_road()) {
					wallnut_list[j]->hurt();
					zombie_list[i]->no_move();
				}
			}

		}






		//阳光拾取处理
		for (size_t i = 0; i < sun_list.size(); i++) {
			p1.pick_sun(sun_list[i]);
		}


		//删除处理
		//僵尸的删除
		for (size_t i = 0; i < zombie_list.size(); i++) {
			zombie* zombie = zombie_list[i];
			if (!zombie->CheckAlive()) {
				swap(zombie_list[i], zombie_list.back());
				zombie_list.pop_back();
				delete zombie;
				counter++;
			}
		}
		for (size_t i = 0; i < snowman_list.size(); i++) {
			snowman* snowman = snowman_list[i];
			if (!snowman->CheckAlive() || snowman->get_zombie_position_x() <-200) {
				swap(snowman_list[i], snowman_list.back());
				snowman_list.pop_back();
				delete snowman;
				counter++;
			}
		}
		for (size_t i = 0; i < gbman_list.size(); i++) {
			gbman* gbman = gbman_list[i];
			if (!gbman->CheckAlive()) {
				swap(gbman_list[i], gbman_list.back());
				gbman_list.pop_back();
				delete gbman;
				counter++;
			}
		}




		//豌豆射手的删除
		for (size_t i = 0; i < shooter_list.size(); i++) {
			shooter* shooter = shooter_list[i];
			if (!shooter->check_being()){
				mciSendString(_T("play eating from 0"), NULL, 0, NULL);
				free[shooter->get_plant_road()]++;
				g1.minnum(shooter->get_plant_road(), shooter->get_plant_line());
				swap(shooter_list[i], shooter_list.back());
				shooter_list.pop_back();
				delete shooter;
			}
		}
		//qiyana的删除
		for (size_t i = 0; i < qiyana_list.size(); i++) {
			qiyana* qiyana = qiyana_list[i];
			if (!qiyana->check_being()) {
				mciSendString(_T("play eating from 0"), NULL, 0, NULL);
				free[qiyana->get_plant_road()]++;
				g1.minnum(qiyana->get_plant_road(), qiyana->get_plant_line());
				swap(qiyana_list[i], qiyana_list.back());
				qiyana_list.pop_back();
				delete qiyana;
			}

		}
		//冰豌豆射手的删除
		for (size_t i = 0; i < snow_pea_list.size(); i++) {
			snow_pea* snow_pea = snow_pea_list[i];
			if (!snow_pea->check_being()) {
				mciSendString(_T("play eating from 0"), NULL, 0, NULL);
				free[snow_pea->get_plant_road()]++;
				g1.minnum(snow_pea->get_plant_road(), snow_pea->get_plant_line());
				swap(snow_pea_list[i], snow_pea_list.back());
				snow_pea_list.pop_back();
				delete snow_pea;
			}
		}
		//向日葵的删除
		for (size_t i = 0; i <sunflower_list.size(); i++) {
			sunflower* sunflower = sunflower_list[i];
			if (!sunflower->check_being()) {
				mciSendString(_T("play eating from 0"), NULL, 0, NULL);
				free[sunflower->get_plant_road()]++;
				g1.minnum(sunflower->get_plant_road(), sunflower->get_plant_line());
				swap(sunflower_list[i], sunflower_list.back());
				sunflower_list.pop_back();
				delete sunflower;
			}
		}
		//坚果墙的删除
		for (size_t i = 0; i < wallnut_list.size(); i++) {
			wallnut* wallnut = wallnut_list[i];
			if (!wallnut->check_being()) {
				mciSendString(_T("play eating from 0"), NULL, 0, NULL);
				free[wallnut->get_plant_road()]++;
				g1.minnum(wallnut->get_plant_road(),wallnut->get_plant_line());
				swap(wallnut_list[i], wallnut_list.back());
				wallnut_list.pop_back();
				delete wallnut;
			}
		}


		//bullet的删除
		for (size_t i = 0; i < bullet_list.size(); i++) {
			bullet* bullet = bullet_list[i];
			if (!bullet->CheckAlive()||bullet->GetPosition_x()>900) {
				//当bullet击中僵尸或bullet出界时删除
				swap(bullet_list[i], bullet_list.back());
				bullet_list.pop_back();
				delete bullet;
			}
		}
		//snow_bullet的删除
		for (size_t i = 0; i < snow_bullet_list.size(); i++) {
			snow_bullet* bullet = snow_bullet_list[i];
			if (!bullet->CheckAlive() || bullet->GetPosition_x() > 900) {
				//当snow_bullet击中僵尸或bullet出界时删除
				swap(snow_bullet_list[i], snow_bullet_list.back());
				snow_bullet_list.pop_back();
				delete bullet;
			}
		}

		//小推车的删除
		for (size_t i = 0; i < car_list.size(); i++) {
			car* car = car_list[i];
			if (car_list[i]->get_position_x() > 700) {
				swap(car_list[i], car_list.back());
				car_list.pop_back();
				delete car;
			}
		}
		//阳光的删除
		for (size_t i = 0; i < sun_list.size(); i++) {
			sun* sun = sun_list[i];
			sun_list[i]->timer_add();
			if (!sun_list[i]->get_being()||sun_list[i]->get_timer()>1000) {
				mciSendString(_T("play sun from 0"), NULL, 0, NULL);
				swap(sun_list[i], sun_list.back());
				sun_list.pop_back();
				delete sun;
			}
		}


		//僵尸的行动释放
		for (int i = 0; i < 5; i++){
			if (free[i]) {
				for (size_t j = 0; j < zombie_list.size(); j++) {
					if (zombie_list[j]->get_zombiie_road() == i) {
						zombie_list[j]->y_move();
					}

				}
			}
			free[i] = 0;
		}


		cleardevice();

		//静态物品绘制
		putimage(0, 0, &imgs);
		putimage(0, 600, &imgs2);
		putimage_alpha(0, 0, &sun_board);
		putimage_alpha(20, 600, &sunflower_card);
		putimage_alpha(76, 600, &shooter_card);
		putimage_alpha(132, 600, &snow_pea_card);
		putimage_alpha(192, 600, &wallnut_card);
		putimage_alpha(500, 600, &up);

		//阳光数量的绘制
		p1.draw_sun_num();
		//等级的绘制
		p1.draw_grade();
		//僵尸击败数量的绘制
		p1.draw_battle_num(counter);

		//玩家绘制
		p1.Draw(1000 / 144);
		
	
		//僵尸画面绘制
		for (size_t i = 0; i < zombie_list.size(); i++) {
			zombie_list[i]->Draw(1000 / 144);
			
		}
		//snowman的绘制
		for (size_t i = 0; i < snowman_list.size(); i++) {
			snowman_list[i]->Draw(1000 / 144);
		}
		//改变man的绘制
		for (size_t i = 0; i <gbman_list.size(); i++) {
			gbman_list[i]->Draw(1000 / 144);
		}
		//豌豆画面绘制
		for (size_t i = 0; i < bullet_list.size(); i++) {
			bullet_list[i]->draw();
		}
		//冰豌豆绘制
		for (size_t i = 0; i < snow_bullet_list.size(); i++) {
			snow_bullet_list[i]->draw();
		}
		//向日葵画面绘制
		for (size_t i = 0; i < sunflower_list.size(); i++) {
			sunflower_list[i]->Draw(1000 / 144);
		}
		//坚果的画面绘制
		for (size_t i = 0; i < wallnut_list.size(); i++) {
			wallnut_list[i]->Draw(1000 / 144);
		}
		//豌豆射手画面绘制
		for (size_t i = 0; i < shooter_list.size(); i++) {
			shooter_list[i]->Draw(1000 / 144);
		}
		//琪亚娜画面绘制
		for (size_t i = 0; i < qiyana_list.size(); i++) {
			qiyana_list[i]->Draw(1000 / 144);
		}
		//冰豌豆射手画面绘制
		for (size_t i = 0; i < snow_pea_list.size(); i++) {
			snow_pea_list[i]->Draw(1000 / 144);
		}
		//阳光画面绘制
		for (size_t i = 0; i < sun_list.size(); i++) {
			sun_list[i]->draw();
		}
		//小推车的画面绘制
		for (size_t i = 0; i < car_list.size(); i++) {
			car_list[i]->Draw(1000 / 144);
		}




		//胜负判断
		for (size_t i = 0; i < zombie_list.size(); i++) {
			if (zombie_list[i]->get_zombie_position_x() < -200) {
				mciSendString(_T("play lose from 0"), NULL, 0, NULL);
				running = 0;
				winning = 0;
			}
			if (counter >= 100) {
				mciSendString(_T("play win from 0"), NULL, 0, NULL);
				running = 0;
				ending = 0;
			}

		}
		
		FlushBatchDraw();

		//动态延时
		DWORD end_time = GetTickCount();
		DWORD delta_time = end_time - start_time;
		if (delta_time < 1000 / 144) {
			Sleep(1000 / 144 - delta_time);
		}

	}
	EndBatchDraw();

	while (ending) {
		putimage(0, 0, &end);
		while (peekmessage(&msg))
		{
			if (msg.message == WM_LBUTTONDOWN) {
				
					ending = 0;
					return 0;
			}

		}
	}

	while (winning) {
		putimage(0, 0, &win);
		while (peekmessage(&msg))
		{
			if (msg.message == WM_LBUTTONDOWN) {

				winning = 0;
				return 0;
			}

		}
	}



	return 0;
}