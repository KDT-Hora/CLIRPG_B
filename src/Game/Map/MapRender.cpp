#include "Game/Map/MapRender.h"

void MapRender::Draw(const MapData& m_Map, const Player& m_Player, const Npc& m_Npc)
{

	for (int y = 0; y < m_Map.GetHeight(); ++y)
	{
		for (int x = 0; x < m_Map.GetWidth(); ++x)
		{
			// 視界の外のタイルは見えないようにする
			if (!m_Map.IsExplored(x, y))
			{
				std::cout << "**";
				continue;
			}

			// プレイヤー描画
			if (x == m_Player.GetX() && y == m_Player.GetY())
			{
				std::cout << "@@";
				continue;
			}

			// NPC描画
			if (x == m_Npc.GetX() && y == m_Npc.GetY())
			{
				std::cout << "&&";
				continue;
			}

			// 描画処理（タイル変更）
			switch (static_cast<TileType>(m_Map.GetTile(x, y)))
			{
			case TileType::Wall: std::cout << "##"; break;
			case TileType::Floor: std::cout << ".."; break;
			case TileType::StairDown: std::cout << ">>"; break;
			case TileType::StairUp: std::cout << "<<"; break;
			case TileType::Chest: std::cout << "[]"; break;
			case TileType::HealSpot: std::cout << "()"; break;
			case TileType::StartPoint: std::cout << "SP"; break;
			default: std::cout << "**"; break;
			}
		}
		std::cout << "\n";
	}
}
