#pragma once
#include <vector>
#include <string>

// ステージの描画管理を行う

// 操作マニュアルの描画
// WASDの移動と階段タイルに乗った際に描画する次のステージや前のステージの描画

// 前方宣言
class MapData;
class MapPlayer;
class MapEnemy;

class FieldViewSystem
{
private:


public:

	virtual ~FieldViewSystem();

	// １タイルの描画数
	static constexpr int TILE_VIEW_WIDTH = 3;
	
	// 描画用関数
	void FieldDraw
	(
		const MapData& m_Map,
		const MapPlayer& m_Player,
		const MapEnemy& m_Npc
	) const;;

};