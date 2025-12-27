#pragma once
#include "Game/Map/MapData.h"
#include "Game/Map/Player/FieldPlayer.h"
#include "Game/Map/Npc/Npc.h"

class MapRender
{
public:

	// ステージ描画用関数（読み取り専用）
	static void Draw(const MapData& m_Map, 
		const Player& m_Player,
		const Npc& m_Npc
	);
};
