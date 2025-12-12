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

	// コンストラクタ
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
	void Draw() const;
};

