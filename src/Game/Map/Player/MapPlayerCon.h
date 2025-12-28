#pragma once
#include "Game/Map/Player/MapPlayer.h"

// プレイヤーの座標移動クラス
// WASDで移動

class MapPlayerController
{
public:

	// 入力移動処理関数
	bool InputUpdate(MapPlayer& m_Player, int px, int py);
};
