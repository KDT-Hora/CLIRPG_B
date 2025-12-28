#include "MapManager.h"
#include "MapFactory.h"

bool MapManager::LoadMap(int stage_id)
{
	// ステージの作成検証
	try
	{
		// 選ばれたステージの生成
		MapDataPtr = std::make_unique<MapData>
			(
				MapFactory::CreateStage(stage_id)
			);
	}
	catch (...)	// 例外が出た場合はステージを表示しない
	{
		return false;
	}

	m_IsDirty = true;
	return true;
}

MapData& MapManager::GetMapData() const
{
	// リターンでMapDataを呼び出す
	return *MapDataPtr;
}

bool MapManager::IsDirty() const
{
	return m_IsDirty;
}

void MapManager::MarkDirty()
{
	m_IsDirty = true;
}

void MapManager::ClearDirty()
{
	m_IsDirty = false;
}
