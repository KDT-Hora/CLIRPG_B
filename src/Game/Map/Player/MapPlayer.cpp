#include "Game/Map/Player/MapPlayer.h"

void MapPlayer::SetPos(int arg_x, int arg_y)
{
	// 引数で取得した座標をいれる
	m_x = arg_x;
	m_y = arg_y;
}

void MapPlayer::Move(int dx, int dy)
{
	// 座標の更新
	m_x += dx;
	m_y += dy;
}
