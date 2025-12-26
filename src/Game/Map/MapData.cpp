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

void MapData::UpdateExploredArea(int x, int y)
{
}

int MapData::GetTile(int x, int y) const
{
	// ステージの範囲を取得
	if (x < 0 || x >= width || y < 0 || y >= height) return static_cast<int>(TileType::Wall);

	// タイルのグリッドをreturnで返す
	return grid[y][x];
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
