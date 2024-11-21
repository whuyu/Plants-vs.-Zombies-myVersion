#include"player.h"
player::player() :character(_T("img/player_left_%d.png"), _T("img/player_right_%d.png"), 6, 45, 3, 500, 500)
{
	loadimage(&player_shadow, _T("img/shadow_player.png"));
	facing = 1;
	//1表示面向左边，0表示面向右边
	Is_shoot = 0;
	num =2000;
}
void player::ProcessEvent(const ExMessage& msg) {
	
		if (msg.message == WM_KEYDOWN) {
			switch (msg.vkcode) {
			
			case VK_UP:
				Is_move_up = 1;
				break;
			case VK_DOWN:
				Is_move_down = 1;
				break;
			case VK_LEFT:
				Is_move_left = 1;
				break;
			case VK_RIGHT:
				Is_move_right = 1;
				break;
			}
		}
		else if (msg.message == WM_KEYUP) {
			switch (msg.vkcode) {
		
			case VK_UP:
				Is_move_up = 0;
				break;
			case VK_DOWN:
				Is_move_down = 0;
				break;
			case VK_LEFT:
				Is_move_left = 0;
				break;
			case VK_RIGHT:
				Is_move_right = 0;
				break;
			}

		
	}

}
void player::Process_shoot(const ExMessage& msg) {
	if (msg.message == WM_KEYDOWN) {
		if (msg.vkcode == 0x41) {
			Is_shoot = 1;
		}
	}
	else if (msg.message == WM_KEYUP) {
		if (msg.vkcode == 0x41) {
			Is_shoot = 0;
		}
	}

}


void player::move()
{
	int dx = Is_move_right - Is_move_left;
	if (Is_move_right - Is_move_left > 0) {
		facing = 0;
	}
	else if(Is_move_right - Is_move_left < 0)
	{
		facing = 1;
	}
	int dy = Is_move_up - Is_move_down;
	double dxy = sqrt(dx * dx + dy * dy);
	if (dxy) {
		double correct_x = dx / dxy;
		double correct_y = dy / dxy;
		position.x += (int)(speed * correct_x);
		position.y -= (int)(speed * correct_y);
	}
	if (position.x < 0) {
		position.x = 0;
	}
	if (position.y < 0) {
		position.y = 0;
	}
	if (position.x + player_width > 800) {
		position.x = 800 - player_width;
	}
	if (position.y + player_height > 700) {
		position.y = 700 - player_height;
	}
}



void player::Draw(int delta) {
	int shadow_x = position.x + (player_width / 2 - shadow_width / 2);
	int shadow_y = position.y + player_height - 8;

	if (facing) {
		anim_left->play(position.x, position.y, delta);
		putimage_alpha(shadow_x, shadow_y, &player_shadow);
	}
	else{
		anim_right->play(position.x, position.y, delta);
		putimage_alpha(shadow_x, shadow_y, &player_shadow);
	}


}
void player::shoot_timer() {
	shoot_able++;
}
int player::get_shoot_able() {
	return shoot_able;
}
void player::not_shoot() {
	Is_shoot = 0;
	shoot_able = 0;
}
bool player::get_is_shoot() {
	return Is_shoot;
}
int player::Getposition_x() {
	return position.x;
}
int player::Getposition_y() {
	return position.y;
}
//拾取阳光
void player::pick_sun(sun* a_sun) {
	int a = position.x + 40;
	int b = position.y + 40;
	if (a > a_sun->get_sun_position_x() && a < a_sun->get_sun_position_x() + 78) {
		if (b > a_sun->get_sun_position_y() && b < a_sun->get_sun_position_y() + 78) {
			num += 25;
			a_sun->dis_being();
		}
	}
}
//绘制太阳数量
void player::draw_sun_num() {
	static TCHAR text[64];
	_stprintf_s(text, _T("%d"), num);

	setbkmode(TRANSPARENT);
	settextcolor(RGB(255, 85, 185));
	outtextxy(80, 10, text);
}
//绘制僵尸击败数
void player::draw_battle_num(int a) {
	static TCHAR text[64];
	_stprintf_s(text, _T("已击败僵尸的数量为：%d"), a);

	setbkmode(TRANSPARENT);
	settextcolor(RGB(255, 85, 185));
	outtextxy(500, 10, text);
}
void player::draw_grade() {
	static TCHAR text[64];
	_stprintf_s(text, _T("当前等级为：%d"), grade);

	setbkmode(TRANSPARENT);
	settextcolor(RGB(255, 85, 185));
	outtextxy(600, 600, text);


}




//判断植物种类
int player::what_plant() {
	int a = position.x + 40;
	int b = position.y + 80;
	if (a > 20 && a < 66 && b>600 && b < 670) {
		return 1;
	}
	if (a > 76 && a < 122 && b>600 && b < 670) {
		return 2;
	}
	if (a > 132 && a < 182 && b>600 && b < 670) {
		return 3;
	}
	if (a > 192 && a < 242 && b>600 && b < 670) {
		return 4;
	}
	if (a > 500 && a < 573 && b>600 && b < 673) {
		return 5;
	}


	return 0;
}

int player::get_sun_num() {
	return num;
}
void player::use_sun(int a) {
	switch (a) {
	case 1:
		num -= 50;
		break;
	case 2:
		num -= 100;
		break;
	case 3:
		num -= 175;
		break;
	case 4:
		num -= 50;
		break;
	case 5:
		num -= 200;
		break;
	case 6:
		num -= 300;
		break;
	case 7:
		num -= 500;
		break;
	case 8:
		num -= 300;
		break;
	}

}

void player::upgrade() {
	grade += 1;
}
bool player::is_in_up_place() {
	int a = position.x + 40;
	int b = position.y + 80;
	if (a > 500 && a < 573 && b>600 && b < 673) {
		return 1;
	}

	return 0;
}
int player::get_grade() {
	return grade;
}

