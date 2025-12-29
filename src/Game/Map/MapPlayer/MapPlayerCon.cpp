#include "MapPlayerCon.h"

bool MapPlayerController::InputUpdate(MapPlayer& m_Player, int px, int py)
{
	if(px == 0 && py == 0)
	return false;

		// プレイヤー座標を更新
	m_Player.Move(px, py);
	return true;
}
