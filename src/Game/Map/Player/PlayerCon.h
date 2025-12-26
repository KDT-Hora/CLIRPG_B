#pragma once
#include "Game/Map/Player/Player.h"
#include "Game/Map/MapData.h"

// プレイヤーの座標移動クラス
// WASDで移動

class PlayerController
{
public:

	// 入力更新処理
	bool InputUpdate(Player& m_Player, const MapData& m_Map);
};
