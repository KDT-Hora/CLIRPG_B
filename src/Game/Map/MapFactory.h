#pragma once
#include "StageData.h"
#include "MapData.h"

class MapFactory
{
public:

	// ステージ情報クラスのインスタンス
	static const StageData StageTable[];
	// ステージ情報のサイズを取得するための変数
	static const int StageTableSize;

	// ステージの変更するための関数
	static bool CreateStage(int stage_id, MapData& OutMap);
};