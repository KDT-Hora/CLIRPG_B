#include "MapManager.h"
#include "MapFactory.h"

bool MapManager::LoadMap(int stage_id)
{
	//// ステージの生成を呼び出す
	//return MapFactory::CreateStage(stage_id, *MapDataPtr);

	if (!MapFactory::CreateStage(stage_id, *MapDataPtr))
		return false;

	IsDirty = true;
	return true;
}

const MapData& MapManager::GetMapData() const
{
	// TODO: return ステートメントをここに挿入します
	return *MapDataPtr;
}

bool MapManager::DrawIfNeeded(const Player& m_Player, const Npc& m_Npc)
{
	if (!IsDirty)
	{
		return 0;
	}

	system("cls"); // 画面クリア
	MapRenderObj.Draw(*MapDataPtr, m_Player, m_Npc); // マップ描画

	IsDirty = false;
	return true;
}

void MapManager::MarkDirty()
{
	IsDirty = true;
}
