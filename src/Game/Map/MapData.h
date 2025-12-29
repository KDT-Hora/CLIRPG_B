#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

// フィールド内部データの管理
// フィールド上にあるタイルの情報をデータで判定するようにする

enum class TileType
{
	Floor = 0,
	Wall = 1,
	StairDown = 2,
	StairUp = 3,
	Chest = 4,
	HealSpot = 5,
	Enemy = 6,		// エネミータイルを追加（タイルを踏んだらエンゲージ）
	StartPoint = 9,
};

class MapData
{
private:

	// 座標
	int width = 0;
	int height = 0;

	// マップの実データ（壁や床の種類）
	std::vector<std::vector<int>> grid;

	// 視界管理データ（true: 探索済み/見える, false: 未探索/暗闇）
	std::vector<std::vector<bool>> explored;

public:

	// 引数コンストラクタ
	MapData(int w, int h, const int* tiles)
	{
		Init(w, h, tiles);
	}

	// デストラクタ
	virtual ~MapData() = default;

	//	初期化
	void Init(int w, int h, const int* data);

	//	視界の更新
	void UpdateExploredArea(int px, int py);

	// タイルが見えるかどうかの関数
	bool IsExplored(int px, int py) const;

	// 移動できるかできないかの判定用関数
	bool CanMove(int px, int py) const;

	//	指定タイルの情報を取得
	int GetTile(int px, int py) const;

	// 範囲チェック関数
	bool IsInBounds(int px, int py) const;

	// 壁やフロア以外でイベントが起こるタイルを関数で定義
	// フロアはNone、イベントはヒール、エネミー（API）
	// タイル管理関数
	bool IsHealTile(int x, int y)const;
	bool IsEnemyTile(int x, int y)const;
	bool IsStairUpTile(int x, int y)const;
	bool IsStairDownTile(int x, int y)const;

	//	マップのサイズ取得
	int GetWidth() const { return width; }
	int GetHeight() const { return height; }

	//	スタート地点の座標を取得
	//	参照で返す
	//　座標を構造体で持っていないのでこの形
	//	構造体で持つようにするなら要変更
	bool GetStartPos(int& arg_x, int& arg_y) const;

	// ステージを移動した際のプレイヤーの座標管理関数
	bool GetStairUpPos(int& arg_x, int& arg_y) const;
	bool GetStairDownPos(int& arg_x, int& arg_y) const;
};