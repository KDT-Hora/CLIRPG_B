#pragma once
#include <iostream>
#include <vector>
#include <string>

// ステージクラス

class CStage
{
private:

	// ステージデータ配列
	std::vector<std::string> Data;
	// ステージの幅と高さ
	int width;
	int height;

public:

	// デフォルトコンストラクタ
	CStage()
		:Data(), width(0), height(0) 
	{}

	// 引数コンストラクタ
	CStage(const std::vector<std::string>& MapData)
		: Data(MapData), width(MapData[0].size()), height(MapData.size())
	{
		//// ステージデータの代入
		//Data = {
		//	"■■■■■■■■■■■■■■■■■■■■■",
		//	"■         　　　　　■",
		//	"■                   ■",
		//	"■                   ■",
		//	"■                   ■",
		//	"■                   ■",
		//	"■                   ■",
		//	"■                   ■",
		//	"■                   ■",
		//	"■■■■■■■■■■■■■■■■■■■■■",
		//};

		//// ステージの幅と高さを取得
		//width = Data[0].size();
		//height = Data.size();
	}

	// 描画処理
	void DrawWithPlayer(int player_x, int player_y) const;

	// 壁の判定
	bool IsWall(int x, int y) const;

	// ステージ切り替えを行う関数
	// 次のステージ
	bool IsNextStage(int x, int y) const;
	// 前のステージ
	bool IsPrevStage(int x, int y) const;
};