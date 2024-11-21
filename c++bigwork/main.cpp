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



//������ʬ1
void TryGenerateZombie(vector<zombie*>& zombie_list) {
	int interval = 900;
	static int zombie_counter = 0;
	zombie_counter++;
	if (zombie_counter % interval == 0) {
		zombie_list.push_back(new zombie());
	}

}
//������ʬ2
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
//����gbman
void TryGenerateGbman1(vector<gbman*>& gbman_list)
{
	int interval = 800;
	static int gbman_counter = 0;
	gbman_counter++;
	if (gbman_counter % interval==0) {
			gbman_list.push_back(new gbman());

	}
}
//��ҵ��Զ�����
void Updatebullets(vector<bullet*>&bullet_list,player&a_player) {
	const int interval = 100;
	static int counter = 0;
	counter++;
	if (counter % interval == 0) {
		bullet_list.push_back(new bullet(a_player.Getposition_x(), a_player.Getposition_y()));
	}
	
}

//��ҵ��ӵ��ֶ�����
void update_bullet_shoot(vector<bullet*>& bullet_list, player& a_player) {

	bullet_list.push_back(new bullet(a_player.Getposition_x(), a_player.Getposition_y()));

}

//�㶹���ֵ��Զ�����
void Update_shooter_bullet(vector<bullet*>& bullet_list, shooter* a_shooter)
{
	const int interval = 200;
	a_shooter->addconuter();
	if (a_shooter->get_counter() % interval == 0) {
		bullet_list.push_back(new bullet(a_shooter->get_position_x(), a_shooter->get_position_y()));
		a_shooter->cutcounter();
	}
}
//qiyana���ӵ�����
void Update_qiyana_bullet(vector<bullet*>& bullet_list, qiyana*a_qiyana)
{
	const int interval = 100;
	a_qiyana ->addconuter();
	if (a_qiyana->get_counter() % interval == 0) {
		bullet_list.push_back(new bullet(a_qiyana->get_position_x(), a_qiyana->get_position_y()));
		a_qiyana->cutcounter();
	}
}


//���տ����������
void Update_sun(vector<sun*>&sun_list,sunflower*a_sunflower) {
	const int interval = 800;
	a_sunflower->addconuter();
	if (a_sunflower->get_counter() % interval == 0) {
		sun_list.push_back(new sun(a_sunflower));
		a_sunflower->cutcounter();
	}
}


//���㶹���Զ�����
void Update_snow_pea_bullet(vector<snow_bullet*>& snow_bullet_list,snow_pea* a_snow_pea)
{
	const int interval = 200;
	a_snow_pea->addconuter();
	if (a_snow_pea->get_counter() % interval == 0) {
		snow_bullet_list.push_back(new snow_bullet(a_snow_pea->get_position_x(), a_snow_pea->get_position_y()));
	}
}


//��ֲ���տ�
void update_sunflower(vector<sunflower*>&sunflower_list,int xx,int yy,int i,int j) {

	sunflower_list.push_back(new sunflower(xx,yy,i,j));

}

//��ֲ�㶹����
void update_shooter(vector<shooter*>&shooter_list, int xx, int yy,int i,int j) {

	shooter_list.push_back(new shooter(xx, yy,i,j));

}
//��ֲqiyana
void update_qiyana(vector<qiyana*>& shooter_list, int xx, int yy, int i, int j) {

	shooter_list.push_back(new qiyana(xx, yy, i, j));

}

//��ֲ���㶹����
void update_snow_pea(vector<snow_pea*>& snow_pea_list, int xx, int yy, int i, int j) {

	snow_pea_list.push_back(new snow_pea(xx, yy,i,j));

}
//��ֲ���ǽ
void update_wallnut(vector<wallnut*>& wallnut_list,int x,int y,int i,int j) {
	wallnut_list.push_back(new wallnut(x, y,i,j));
}


//��������
void TryGenerateSun(vector<sun*>&sun_list) {
	const int interval = 600;
	static int sun_counter = 0;
	sun_counter++;
	if (sun_counter % interval == 0) {
		sun_list.push_back(new sun());
	}
}


  
int main() {
	//���
	player p1;
	//������
	ground g1;
	//��¼�Ƿ��н�ʬ
	int road[5]{};
	//�ͷŽ�ʬ�ƶ�
	int free[5]{};

	//���ܵĽ�ʬ����
	static int counter=0;

	
	//��ʬ����
	vector<zombie*>zombie_list;
	vector<snowman*>snowman_list;
	vector<gbman*>gbman_list;

	//�ӵ�ֲ������
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

	//���ⰴ����Ϣ
	ExMessage msg;

	//��̬��Ʒ��ͼƬ
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

	//����С�Ƴ�
	for (int i = 0; i < 5; i++) {
		car_list.push_back(new car(i,i));
	}

	//����
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
	


	//��ѭ��
	while (running) {
		DWORD start_time = GetTickCount();

		//���������
		p1.shoot_timer();


		
		while (peekmessage(&msg))
		{
			//����ֲ����ֲʱ�����λ��
			g1.ground_process(msg,p1.what_plant());
			//��������ƶ�
			p1.ProcessEvent(msg);
			//��������ӵ�����
			p1.Process_shoot(msg);

		}

		//����ƶ�
		p1.move();


		//����ϵͳ
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

		//player�ķ��䴦��
		//��player���°������Ҽ������㹻��ʱ���Է���
		if (p1.get_is_shoot()&&p1.get_shoot_able()>100&&p1.get_grade()>1) {
			update_bullet_shoot(bullet_list, p1);
			p1.not_shoot();
		}

		//����bullet
		if (p1.get_grade() > 2) {
			Updatebullets(bullet_list, p1);
		}

		//�����Զ�����
		TryGenerateSun(sun_list);

		//���տ�����Ĳ���
		for (size_t i = 0; i < sunflower_list.size(); i++) {
			Update_sun(sun_list, sunflower_list[i]);
		}



		//����zombie
		if (counter > 30) {
			TryGenerateZombie(zombie_list, snowman_list);
			TryGenerateGbman1(gbman_list);

		}
		else {
			TryGenerateZombie(zombie_list);
		}
		


		//��¼��·�Ƿ��н�ʬ
		for (size_t i = 0; i < zombie_list.size(); i++) {
			road[zombie_list[i]->get_zombiie_road()]++;
		}
		for (size_t i = 0; i < gbman_list.size(); i++) {
			road[gbman_list[i]->get_zombiie_road()]++;
		}
		for (size_t i = 0; i < snowman_list.size(); i++) {
			road[snowman_list[i]->get_zombiie_road()]++;
		}
		//��road�����ݴ���g1
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

		
		//�㶹���䴦��
		for (size_t i = 0; i < shooter_list.size(); i++) {
			if (g1.get_Is_zombie(shooter_list[i]->get_plant_road())) {
				Update_shooter_bullet(bullet_list, shooter_list[i]);
			}
		}
		//qiyana���ӵ�����
		for (size_t i = 0; i < qiyana_list.size(); i++) {
				Update_qiyana_bullet(bullet_list, qiyana_list[i]);
		}
		//���㶹���䴦��
		for (size_t i = 0; i <snow_pea_list.size(); i++) {
			if (g1.get_Is_zombie(snow_pea_list[i]->get_plant_road())) {
				Update_snow_pea_bullet(snow_bullet_list, snow_pea_list[i]);
			}
		}


		



		//С�Ƴ���������
		for (size_t i = 0; i < car_list.size(); i++) {
			for (size_t j = 0; j < zombie_list.size(); j++) {
				if (zombie_list[j]->check_action(car_list[i])) {
					mciSendString(_T("play car from 0"), NULL, 0, NULL);
					car_list[i]->car_action();
				}
			}
		}






		//ֲ����ֲ����
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 9; j++) {
				if (!g1.getnum2(i, j)) {
					if (g1.getnum1(i,j)==1&&p1.get_sun_num()>=50) {
						int b = (i *100)+80;//��ֱλ��
						int a = (j * 80) + 40;//ˮƽλ��
						update_sunflower(sunflower_list, a, b,i,j);
						g1.addnum(i, j);
						p1.use_sun(1);
						mciSendString(_T("play plant from 0"), NULL, 0, NULL);
					}
					if (g1.getnum1(i, j) == 2 && p1.get_sun_num() >= 100) {
						int b = (i * 100) + 80;//��ֱλ��
						int a = (j * 80) + 40;//ˮƽλ��
						update_shooter(shooter_list, a, b,i,j);
						g1.addnum(i, j);
						p1.use_sun(2);
						mciSendString(_T("play plant from 0"), NULL, 0, NULL);
					}
					if (g1.getnum1(i, j) == 3 && p1.get_sun_num() >= 175) {
						int b = (i * 100) + 80;//��ֱλ��
						int a = (j * 80) + 40;//ˮƽλ��
						update_snow_pea(snow_pea_list, a, b,i,j);
						g1.addnum(i, j);
						p1.use_sun(3);
						mciSendString(_T("play plant from 0"), NULL, 0, NULL);
					}
					if (g1.getnum1(i, j) == 4&&p1.get_sun_num() >= 50) {
						int b = (i * 100) + 80;//��ֱλ��
						int a = (j * 80) + 40;//ˮƽλ��
						update_wallnut(wallnut_list, a, b,i,j);
						g1.addnum(i, j);
						p1.use_sun(4);
						mciSendString(_T("play plant from 0"), NULL, 0, NULL);
					}
					if (g1.getnum1(i, j) == 5 && p1.get_sun_num() >=300&&p1.get_grade()==4) {
						int b = (i * 100) + 80;//��ֱλ��
						int a = (j * 80) + 40;//ˮƽλ��
						update_qiyana(qiyana_list, a, b, i, j);
						g1.addnum(i, j);
						p1.use_sun(8);
						mciSendString(_T("play plant from 0"), NULL, 0, NULL);
					}
				}
			}

		}
	


		//�ƶ�����
		
		//��ʬ���ƶ�
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



		//bullet���ƶ�
		for (size_t i = 0; i < bullet_list.size(); i++) {
			bullet_list[i]->bullet_move();
		}
		//snow_bullet���ƶ�
		for (size_t i = 0; i < snow_bullet_list.size(); i++) {
			snow_bullet_list[i]->bullet_move();
		}
		//С�Ƴ����ƶ�
		for (size_t i = 0; i < car_list.size(); i++) {
			if (car_list[i]->get_action()) {
				car_list[i]->move();
			}
		}
		//������ƶ�
		for (size_t i = 0; i < sun_list.size(); i++) {
			sun_list[i]->move();
		}



		//�ܻ�����

		//��ʬ�ܻ�����(�㶹)
		for (size_t i = 0; i < bullet_list.size(); i++) {
			for (size_t j = 0; j < zombie_list.size(); j++) {
				if (zombie_list[j]->CheckBulletCollision(bullet_list[i])) {
					mciSendString(_T("play hit from 0"), NULL, 0, NULL);
					zombie_list[j]->Hurt();
					bullet_list[i]->Hurt();

				}
			}
		}
		//snowman���ܻ�����1
		for (size_t i = 0; i < bullet_list.size(); i++) {
			for (size_t j = 0; j < snowman_list.size(); j++) {
				if (snowman_list[j]->CheckBulletCollision(bullet_list[i])) {
					mciSendString(_T("play hit from 0"), NULL, 0, NULL);
					snowman_list[j]->Hurt();
					bullet_list[i]->Hurt();

				}
			}
		}
		//gbman�ܻ�����
		for (size_t i = 0; i < bullet_list.size(); i++) {
			for (size_t j = 0; j < gbman_list.size(); j++) {
				if (gbman_list[j]->CheckBulletCollision(bullet_list[i])) {
					mciSendString(_T("play hit from 0"), NULL, 0, NULL);
					gbman_list[j]->Hurt();
					bullet_list[i]->Hurt();
				}
			}
		}
		//��ʬ�ܻ�����(���㶹)
		for (size_t i = 0; i < snow_bullet_list.size(); i++) {
			for (size_t j = 0; j < zombie_list.size(); j++) {
				if (zombie_list[j]->CheckSnowBulletCollision(snow_bullet_list[i],1)) {
					mciSendString(_T("play hit from 0"), NULL, 0, NULL);
					zombie_list[j]->Hurt(1);
					snow_bullet_list[i]->Hurt();

				}
			}
		}
		//snowman���ܻ�����2
		for (size_t i = 0; i < snow_bullet_list.size(); i++) {
			for (size_t j = 0; j < snowman_list.size(); j++) {
				if (snowman_list[j]->CheckSnowBulletCollision(snow_bullet_list[i],2)) {
					mciSendString(_T("play hit from 0"), NULL, 0, NULL);
					snow_bullet_list[i]->Hurt();
				}
			}
		}
		//gbman���ܻ�����
		for (size_t i = 0; i < snow_bullet_list.size(); i++) {
			for (size_t j = 0; j < gbman_list.size(); j++) {
				if (gbman_list[j]->CheckSnowBulletCollision(snow_bullet_list[i], 2)) {
					mciSendString(_T("play hit from 0"), NULL, 0, NULL);
					snow_bullet_list[i]->Hurt();
					gbman_list[j]->Hurt();
				}
			}
		}
		//��ʬ�ܻ�����С�Ƴ���
		for (size_t i = 0; i < car_list.size(); i++) {
			for (size_t j = 0; j < zombie_list.size(); j++) {
				if (zombie_list[j]->CheckCarCollision(car_list[i])) {
					zombie_list[j]->Hurt();
				}
			}
		}
	






		//ֲ������˴���
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






		//����ʰȡ����
		for (size_t i = 0; i < sun_list.size(); i++) {
			p1.pick_sun(sun_list[i]);
		}


		//ɾ������
		//��ʬ��ɾ��
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




		//�㶹���ֵ�ɾ��
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
		//qiyana��ɾ��
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
		//���㶹���ֵ�ɾ��
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
		//���տ���ɾ��
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
		//���ǽ��ɾ��
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


		//bullet��ɾ��
		for (size_t i = 0; i < bullet_list.size(); i++) {
			bullet* bullet = bullet_list[i];
			if (!bullet->CheckAlive()||bullet->GetPosition_x()>900) {
				//��bullet���н�ʬ��bullet����ʱɾ��
				swap(bullet_list[i], bullet_list.back());
				bullet_list.pop_back();
				delete bullet;
			}
		}
		//snow_bullet��ɾ��
		for (size_t i = 0; i < snow_bullet_list.size(); i++) {
			snow_bullet* bullet = snow_bullet_list[i];
			if (!bullet->CheckAlive() || bullet->GetPosition_x() > 900) {
				//��snow_bullet���н�ʬ��bullet����ʱɾ��
				swap(snow_bullet_list[i], snow_bullet_list.back());
				snow_bullet_list.pop_back();
				delete bullet;
			}
		}

		//С�Ƴ���ɾ��
		for (size_t i = 0; i < car_list.size(); i++) {
			car* car = car_list[i];
			if (car_list[i]->get_position_x() > 700) {
				swap(car_list[i], car_list.back());
				car_list.pop_back();
				delete car;
			}
		}
		//�����ɾ��
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


		//��ʬ���ж��ͷ�
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

		//��̬��Ʒ����
		putimage(0, 0, &imgs);
		putimage(0, 600, &imgs2);
		putimage_alpha(0, 0, &sun_board);
		putimage_alpha(20, 600, &sunflower_card);
		putimage_alpha(76, 600, &shooter_card);
		putimage_alpha(132, 600, &snow_pea_card);
		putimage_alpha(192, 600, &wallnut_card);
		putimage_alpha(500, 600, &up);

		//���������Ļ���
		p1.draw_sun_num();
		//�ȼ��Ļ���
		p1.draw_grade();
		//��ʬ���������Ļ���
		p1.draw_battle_num(counter);

		//��һ���
		p1.Draw(1000 / 144);
		
	
		//��ʬ�������
		for (size_t i = 0; i < zombie_list.size(); i++) {
			zombie_list[i]->Draw(1000 / 144);
			
		}
		//snowman�Ļ���
		for (size_t i = 0; i < snowman_list.size(); i++) {
			snowman_list[i]->Draw(1000 / 144);
		}
		//�ı�man�Ļ���
		for (size_t i = 0; i <gbman_list.size(); i++) {
			gbman_list[i]->Draw(1000 / 144);
		}
		//�㶹�������
		for (size_t i = 0; i < bullet_list.size(); i++) {
			bullet_list[i]->draw();
		}
		//���㶹����
		for (size_t i = 0; i < snow_bullet_list.size(); i++) {
			snow_bullet_list[i]->draw();
		}
		//���տ��������
		for (size_t i = 0; i < sunflower_list.size(); i++) {
			sunflower_list[i]->Draw(1000 / 144);
		}
		//����Ļ������
		for (size_t i = 0; i < wallnut_list.size(); i++) {
			wallnut_list[i]->Draw(1000 / 144);
		}
		//�㶹���ֻ������
		for (size_t i = 0; i < shooter_list.size(); i++) {
			shooter_list[i]->Draw(1000 / 144);
		}
		//�����Ȼ������
		for (size_t i = 0; i < qiyana_list.size(); i++) {
			qiyana_list[i]->Draw(1000 / 144);
		}
		//���㶹���ֻ������
		for (size_t i = 0; i < snow_pea_list.size(); i++) {
			snow_pea_list[i]->Draw(1000 / 144);
		}
		//���⻭�����
		for (size_t i = 0; i < sun_list.size(); i++) {
			sun_list[i]->draw();
		}
		//С�Ƴ��Ļ������
		for (size_t i = 0; i < car_list.size(); i++) {
			car_list[i]->Draw(1000 / 144);
		}




		//ʤ���ж�
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

		//��̬��ʱ
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