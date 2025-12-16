#include "PlayerView.h"
#include <iostream>

void CPlayerView::Draw(const CPlayerModel& model) const
{
	// 画面クリア
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
	// プレイヤーの座標を表示
	std::cout << "Player Position : ("
		<< model.GetX() << ","
		<< model.GetY() << ")" << std::endl;
}
