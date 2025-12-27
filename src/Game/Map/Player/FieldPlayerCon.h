#pragma once
#include "Game/Map/Player/FieldPlayer.h"

// プレイヤーの座標移動クラス
// WASDで移動

class PlayerController
{
public:

	// 入力移動処理関数
	bool InputUpdate(Player& m_Player, int px, int py);
};
