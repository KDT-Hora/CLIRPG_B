#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

enum class TileType
{
	Floor = 0,
	Wall = 1,
	StairDown = 2,
	Chest = 3,
	HealSpot = 4,
	StartPoint = 9,
};

class MapData
{
private:

	int width = 0;
	int height = 0;

	// マップの実データ（壁や床の種類）
	std::vector<std::vector<int>> grid;

	// 視界管理データ（true: 探索済み/見える, false: 未探索/暗闇）
	std::vector<std::vector<bool>> explored;

public :

	MapData() = default;

	//	初期化
	void Init();

	//	視界の更新
	void UpdateExploredArea(int x,int y);

	//	指定タイルの情報を取得
	int GetTile(int x, int y);

	//	マップのサイズ取得
	int GetWidth() { return width; }
	int Getheight() { return height; }

	//	スタート地点の座標を取得
	//	参照で返す
	//　座標を構造体で持っていないのでこの形
	//	構造体で持つようにするなら要変更
	bool GetStartPos(int& x, int& y);

};