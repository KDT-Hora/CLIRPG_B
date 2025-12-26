#pragma once
#include <iostream>

#include "Game/Map/MapData.h"
#include "Game/Map/MapRender.h"
#include "Game/Map/Player/Player.h"
#include "Game/Map/Npc/Npc.h"

// マップの管理クラス
// 描画や生成をまとめて管理

class MapManager
{
private:

	// マップデータクラス
	std::unique_ptr<MapData> MapDataPtr = std::make_unique<MapData>();
	// マップ描画クラス
	MapRender MapRenderObj;

	// 画面が変更されたかどうかのフラグ
	bool IsDirty = true;

public:

	// デフォルトコンストラクタ
	MapManager() = default;
	// デストラクタ
	virtual ~MapManager() = default;

	// マップ読み込み関数
	bool LoadMap(int stage_id);

	// マップデータ取得関数
	MapData& GetMapData();

	// 画面制御関数
	bool DrawIfNeeded(const Player& m_Player, const Npc& m_Npc);
	void MarkDirty();
};