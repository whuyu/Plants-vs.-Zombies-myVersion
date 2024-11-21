#include"Animation.h"
Animation::Animation(LPCTSTR path, int num, int interval) {
	interval_ms = interval;
	TCHAR path_file[256];
	//字符串格式化模板
	for (size_t i = 0; i < num; i++) {

		_stprintf_s(path_file, path, i);

		IMAGE* frame = new IMAGE();
		loadimage(frame, path_file);
		frame_list.push_back(frame);
		//将图片对象的指针装入vector容器中
	}
}
void Animation::play(int x, int y, int delta) {
	timer += delta;//delta表示距离上次调用play函数距离了多长时间
	if (timer >= interval_ms) {
		//如果计时器大于帧索引，播放下一帧
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
