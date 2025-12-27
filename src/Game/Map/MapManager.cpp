#include "MapManager.h"
#include "MapFactory.h"

bool MapManager::LoadMap(int stage_id)
{
	//// ステージの生成を呼び出す
	//return MapFactory::CreateStage(stage_id, *MapDataPtr);

	if (!MapFactory::CreateStage(stage_id, *MapDataPtr))
		return false;

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
