#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "Stage.h"

// ステージのファクトリークラス
// ステージの種類を増やしたい場合、このクラスから拡張する

class CStageFactory
{
public:
	// ステージの生成関数
	static std::shared_ptr<CStage> CreateStage(int id)
	{
		// ステージのIDによって生成するステージを変更
		switch (id)
		{
		case 0:
			return std::make_shared<CStage>(std::vector<std::string>
			{
				// ステージの生成
				"■■■■■■■■■■■■■■■■■■■■■",
				"■         　　　　　■",
				"■   ステージ１      ■",
				"■                   ■",
				"■                   ■",
				"■                   ■",
				"■                   ■",
				"■                   ■",
				"■                   ■",
				"■■■■■■■■■■■■■■■■■■■■■",
			});

		case 1:
			return std::make_shared<CStage>(std::vector<std::string>
			{
				// ステージの生成
				"■■■■■■■■■■■■■■■■■■■■■",
				"■         　　　　　■",
				"■   ステージ２      ■",
				"■                   ■",
				"■                   ■",
				"■                   ■",
				"■                   ■",
				"■                   ■",
				"■                   ■",
				"■■■■■■■■■■■■■■■■■■■■■",
			});

		case 2:
			return std::make_shared<CStage>(std::vector<std::string>
			{
				// ステージの生成
				"■■■■■■■■■■■■■■■■■■■■■",
				"■         　　　　　■",
				"■   ステージ３      ■",
				"■                   ■",
				"■                   ■",
				"■                   ■",
				"■                   ■",
				"■                   ■",
				"■                   ■",
				"■■■■■■■■■■■■■■■■■■■■■",
			});
		}

		return nullptr;	//	無効なIDの場合はnullptrを返す
	}
};