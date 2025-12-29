#include "FieldViewSystem.h"
#include "../../../../Game/Map/MapData.h"
#include "../../../../Game/Map/Player/MapPlayer.h"
#include "../../../../Game/Map/Npc/MapNpc.h"

//	描画システム
#include "../../../View/View.h"

#include <iostream>
#include <cstdlib>

FieldViewSystem::~FieldViewSystem() = default;

//	フィールドの描画メソッド
void FieldViewSystem::FieldDraw
(
	const MapData& m_Map,
	const MapPlayer& m_Player,
	const MapNpc& m_Npc
) const
{

	// ローカルstring関数
	std::vector<std::string> Lines;

	for (int y = 0; y < m_Map.GetHeight(); ++y)
	{
		// タイルの更新を行う
		std::string line;

		for (int x = 0; x < m_Map.GetWidth(); ++x)
		{
			// ２マス開けるように描画する
			auto Put = [&](const std::string& s)
			{
				line += s;
				line += std::string(TILE_VIEW_WIDTH - s.size(), ' ');
			};

			// 視界の外のタイルは見えないようにする
			if (!m_Map.IsExplored(x, y))
			{
				Put("**");
				continue;
			}

			// プレイヤー描画
			if (x == m_Player.GetX() && y == m_Player.GetY())
			{
				Put("@@");
				continue;
			}

			// NPC描画
			if (x == m_Npc.GetX() && y == m_Npc.GetY())
			{
				Put("&&");
				continue;
			}

			// 描画処理（タイル変更）
			switch (static_cast<TileType>(m_Map.GetTile(x, y)))
			{
			case TileType::Wall:		Put("##"); break;
			case TileType::Floor:		Put(".."); break;
			case TileType::StairDown:	Put(">>"); break;
			case TileType::StairUp:		Put("<<"); break;
			case TileType::Chest:		Put("[]"); break;
			case TileType::HealSpot:	Put("()"); break;
			case TileType::StartPoint:	Put("SP"); break;
			default:					Put("**"); break;
			}
		}

		// 描画の追加
		View::Instance().Add(line);
	}
}

