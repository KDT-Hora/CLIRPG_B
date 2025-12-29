#include "MapData.h"


void MapData::Init(int w, int h, const int* data)
{
	// 座標を入れる
	width = w;
	height = h;

	// ２次元配列の初期化
	grid.assign(height, std::vector<int>(width));
	explored.assign(height, std::vector<bool>(width, false));

	// １次元配列を２次元配列グリッドに展開
	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			grid[y][x] = data[y * width + x];
		}
	}
}

void MapData::UpdateExploredArea(int px, int py)
{
	// 見える範囲（周辺2マス）
	const int range = 2;

	// マスの設定
	for (int dy = -range; dy <= range; ++dy)
	{
		for (int dx = -range; dx <= range; ++dx)
		{
			int nx = px + dx;
			int ny = py + dy;

			if(!IsInBounds(nx, ny)) continue;

			explored[ny][nx] = true;
		}
	}
}

bool MapData::IsExplored(int px, int py) const
{
	// 特定の範囲では処理範囲では描画を行わない
	if (!IsInBounds(px, py))
	{
		return false;
	}

	return explored[py][px];
}

bool MapData::CanMove(int px, int py) const
{
	// 範囲外
	if (!IsInBounds(px, py))
	{
		return false;
	}

	// 壁
	if (GetTile(px, py) == static_cast<int>(TileType::Wall))
	{
		return false;
	}

	return true;
}

int MapData::GetTile(int px, int py) const
{
	// ステージの範囲を取得
	if (!IsInBounds(px, py)) return static_cast<int>(TileType::Wall);

	// タイルのグリッドをreturnで返す
	return grid[py][px];
}

bool MapData::IsInBounds(int px, int py) const
{
	return px >= 0 && px < width && py >= 0 && py < height;
}

bool MapData::GetStartPos(int& arg_x, int& arg_y) const
{
	// スタート座標のタイルを設定
	for (int j = 0; j < height; ++j)
	{
		for (int i = 0; i < width; ++i)
		{
			if (grid[j][i] == static_cast<int>(TileType::StartPoint))
			{
				arg_x = i;
				arg_y = j;
				return true;
			}
		}
	}

	return false;
}

bool MapData::GetStairUpPos(int& arg_x, int& arg_y) const
{
	// スタート座標のタイルを設定
	for (int j = 0; j < height; ++j)
	{
		for (int i = 0; i < width; ++i)
		{
			if (grid[j][i] == static_cast<int>(TileType::StairUp))
			{
				arg_x = i;
				arg_y = j;
				return true;
			}
		}
	}

	return false;
}

bool MapData::GetStairDownPos(int& arg_x, int& arg_y) const
{
	// スタート座標のタイルを設定
	for (int j = 0; j < height; ++j)
	{
		for (int i = 0; i < width; ++i)
		{
			if (grid[j][i] == static_cast<int>(TileType::StairDown))
			{
				arg_x = i;
				arg_y = j;
				return true;
			}
		}
	}
	return false;
}
