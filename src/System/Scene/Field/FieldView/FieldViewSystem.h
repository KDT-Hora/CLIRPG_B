#pragma once
#include <vector>
#include <string>

// ステージの描画管理を行う

// 前方宣言
class MapData;
class MapPlayer;
class MapNpc;

class FieldViewSystem
{
private:

	std::vector<std::string> LastLines;

public:

	// １タイルの描画数
	static constexpr int TILE_VIEW_WIDTH = 4;
	
	// 描画用ベクター関数
	std::vector<std::string> BuildFieldLines
	(
		const MapData& m_Map,
		const MapPlayer& m_Player,
		const MapNpc& m_Npc
	) const;;

	// ステージの描画用関数
	void Submit(const std::vector<std::string>& lines);

	// 画面クリア関数
	void Clear();
};