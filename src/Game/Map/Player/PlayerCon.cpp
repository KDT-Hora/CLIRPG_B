#include "PlayerCon.h"
#include "System/Input/InputMG.h"

bool PlayerController::InputUpdate(Player& m_Player, const MapData& m_Map)
{
	// キー入力の取得
	auto key = InputMG::Instance().GetKey();

	// 座標更新用変数
	int dx = 0;
	int dy = 0;

	// キー入力による移動処理
	switch (key)
	{
	case InputMG::UP:		dy = -1; break;
	case InputMG::DOWN:		dy = 1; break;
	case InputMG::LEFT:		dx = -1; break;
	case InputMG::RIGHT:	dx = 1; break;
	default:
		return false;
	}

	// 座標の更新
	int nx = m_Player.GetX() + dx;
	int ny = m_Player.GetY() + dy;

	// 壁判定
	if (m_Map.GetTile(nx, ny) == static_cast<int>(TileType::Wall))
	{
		return false;
	}

	// プレイヤー座標を更新
	m_Player.Move(dx, dy);

	return true;
}
