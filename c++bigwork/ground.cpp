#include"ground.h"
ground::ground() {

}
int ground::getnum1(int a, int b) {
	return background[0][a][b];
}
int ground::getnum2(int a, int b) {

	return background[1][a][b];
}
void ground::addnum(int a, int b) {

	background[1][a][b] = 1;
}
//保存是否在这个格子上有植物
void ground::minnum(int a, int b) {
	background[1][a][b] = 0;
	background[0][a][b] = 0;
}
void ground::put_Is_zombie(int a) {
	Is_zombie[a] = 1;
}
void ground::no_zombie(int a) {
	Is_zombie[a] = 0;
}
bool ground::get_Is_zombie(int a) {
	return Is_zombie[a];
}


void ground::ground_process(const ExMessage& msg, int a) {
	if (msg.message == WM_LBUTTONDOWN) {
		int x = msg.x;
		int y = msg.y;
		//优化：使用d_X
		int d_x = (x - 40) / 80;
		int d_y = (y - 80) / 100;
		
		background[0][d_y][d_x] = a;
	}

}


