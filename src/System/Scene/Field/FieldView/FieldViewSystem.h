#pragma once
#include "Game/Map/MapRender.h"

// ステージの描画管理を行う

// 前方宣言
class MapData;
class Player;
class Npc;

class FieldViewSystem
{
private:

	// タイル描画用クラス
	MapRender Map_Render;

public:

	// 描画関数
	void DrawField
	(
		const MapData& m_Map,
		const Player& m_Player,
		const Npc& m_Npc
	);

	// 画面クリア関数
	void Clear();
};