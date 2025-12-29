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

	// 修正：MapDataを生成して返すように変更
	static MapData CreateStage(int stage_id);
};