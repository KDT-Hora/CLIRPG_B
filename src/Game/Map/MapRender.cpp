#include "Game/Map/MapRender.h"

#include <iostream>
#include <string>

void MapRender::Draw(const MapData& m_Map, const Player& m_Player, const Npc& m_Npc)
{

	for (int y = 0; y < m_Map.GetHeight(); ++y)
	{
		// ローカルstring関数
		std::string line;

		for (int x = 0; x < m_Map.GetWidth(); ++x)
		{
			// 空白
			std::string cell = " ";

			// 視界の外のタイルは見えないようにする
			if (!m_Map.IsExplored(x, y))
			{
				cell = "**";
			}
			// プレイヤー描画
			else if (x == m_Player.GetX() && y == m_Player.GetY())
			{
				cell = "@@";
			}
			// NPC描画
			else if (x == m_Npc.GetX() && y == m_Npc.GetY())
			{
				cell = "&&";
			}
			else
			{
				// 描画処理（タイル変更）
				switch (static_cast<TileType>(m_Map.GetTile(x, y)))
				{
				case TileType::Wall:		cell = "##"; break;
				case TileType::Floor:		cell = ".."; break;
				case TileType::StairDown:	cell = ">>"; break;
				case TileType::StairUp:		cell = "<<"; break;
				case TileType::Chest:		cell = "[]"; break;
				case TileType::HealSpot:	cell = "()"; break;
				case TileType::StartPoint:	cell = "SP"; break;
				default:					cell = "**"; break;
				}
			}
			
			// 半角スペース込みで追加
			line += cell;
			line += ' ';
		}

		// 行単位での描画
		std::cout << line << "\n";
	}
}
