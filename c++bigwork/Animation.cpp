#include"Animation.h"
Animation::Animation(LPCTSTR path, int num, int interval) {
	interval_ms = interval;
	TCHAR path_file[256];
	//�ַ�����ʽ��ģ��
	for (size_t i = 0; i < num; i++) {

		_stprintf_s(path_file, path, i);

		IMAGE* frame = new IMAGE();
		loadimage(frame, path_file);
		frame_list.push_back(frame);
		//��ͼƬ�����ָ��װ��vector������
	}
}
void Animation::play(int x, int y, int delta) {
	timer += delta;//delta��ʾ�����ϴε���play���������˶೤ʱ��
	if (timer >= interval_ms) {
		//�����ʱ������֡������������һ֡
		idx_frame++;
		if (idx_frame == frame_list.size()) {
			idx_frame = 0;
		}
		timer = 0;
	}
	putimage_alpha(x, y, frame_list[idx_frame]);
}
Animation::~Animation()
{
	for (size_t i = 0; i < frame_list.size(); i++) {
		delete frame_list[i];
	}
}
