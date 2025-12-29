#pragma once
#include <iostream>

#include "MapData.h"
#include "Player/MapPlayer.h"
#include "Npc/MapNpc.h"

// マップの管理クラス
// 描画や生成をまとめて管理

class MapManager
{
private:

	// マップデータクラス
	std::unique_ptr<MapData> MapDataPtr;

	// 画面が変更されたかどうかのフラグ
	bool m_IsDirty = false;

public:

	// デフォルトコンストラクタ
	MapManager() = default;
	// デストラクタ
	virtual ~MapManager() = default;

	// マップ読み込み関数
	bool LoadMap(int stage_id);

	// マップデータ取得関数
	MapData& GetMapData() const;

	// 画面が変更されたかの状態管理関数
	bool IsDirty() const;
	// 画面変更用
	void MarkDirty();
	// 画面リセット用
	void ClearDirty();
};